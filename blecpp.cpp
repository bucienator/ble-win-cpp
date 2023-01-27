// blecpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "decoders.h"

std::wstring GetDeviceName(uint64_t deviceAddr) {
	BluetoothLEDevice dev = BluetoothLEDevice::FromBluetoothAddressAsync(deviceAddr).get();

	GattDeviceServicesResult gapServicesResult = dev.GetGattServicesForUuidAsync(GattServiceUuids::GenericAccess(), BluetoothCacheMode::Uncached).get();
	if (gapServicesResult.Status() == GattCommunicationStatus::Success) {
		IVectorView<GattDeviceService> gapServices = gapServicesResult.Services();
		if (gapServices.Size() > 0) {
			GattDeviceService genericAccessSvc = gapServices.GetAt(0);
			if (genericAccessSvc) {
				IVectorView<GattCharacteristic> gapDeviceNameChrs = genericAccessSvc.GetCharacteristics(GattCharacteristicUuids::GapDeviceName());
				if (gapDeviceNameChrs.Size() == 1) {
					GattCharacteristic gapDeviceNameChr = gapDeviceNameChrs.GetAt(0);

					GattReadResult readRes = gapDeviceNameChr.ReadValueAsync().get();
					if (readRes.Status() == GattCommunicationStatus::Success) {
						DataReader reader = DataReader::FromBuffer(readRes.Value());
						return reader.ReadString(reader.UnconsumedBufferLength()).c_str();
					}
				}
			}
		}
	}

	std::wstring devName = dev.Name().c_str();
	if (!devName.empty()) {
		return devName;
	}

	std::wstringstream str;
	str << L"Unnamed device " << AddrToString(deviceAddr);
	return str.str();
}

void ShowAdvertisement(BluetoothLEAdvertisementReceivedEventArgs eventArgs)
{
	std::wcout << L"Advertisement received from: " << AddrToString(eventArgs.BluetoothAddress());
	std::wcout << L" with signal strength " << eventArgs.RawSignalStrengthInDBm() << " dBm";
	std::wcout << L" Advertisement type: " << AdvertisementTypeToString(eventArgs.AdvertisementType()) << std::endl;

	BluetoothLEAdvertisement advertisement = eventArgs.Advertisement();
	auto dataSections = advertisement.DataSections();
	std::wcout << L" Number of data sections: " << dataSections.Size() << std::endl;
	for (BluetoothLEAdvertisementDataSection dataSection : dataSections) {
		std::wcout << L"  Data type: " << AdvertisementDataTypeToString(dataSection.DataType()) << std::endl;
	}

}

uint64_t GetFirstAdvertisingBLEAddr()
{
	std::mutex m;
	std::condition_variable cv;

	BluetoothLEAdvertisementWatcher advWatcher;
	uint64_t addr = 0;
	bool stopCalled = false;
	auto recvToken = advWatcher.Received([&addr, &m, &cv](BluetoothLEAdvertisementWatcher watcher, BluetoothLEAdvertisementReceivedEventArgs eventArgs) {
		ShowAdvertisement(eventArgs);
		addr = eventArgs.BluetoothAddress();
		watcher.Stop();
		std::unique_lock l(m);
		cv.notify_all();
	});
	auto stoppedToken = advWatcher.Stopped([&stopCalled, &m, &cv](BluetoothLEAdvertisementWatcher watcher, BluetoothLEAdvertisementWatcherStoppedEventArgs eventArgs) {
		std::unique_lock l(m);
		stopCalled = true;
		cv.notify_all();
	});

	{
		std::unique_lock l(m);
		advWatcher.Start();
		cv.wait(l, [&addr, &stopCalled, &advWatcher] { return addr != 0 && stopCalled && (advWatcher.Status() == BluetoothLEAdvertisementWatcherStatus::Aborted || advWatcher.Status() == BluetoothLEAdvertisementWatcherStatus::Stopped); });
	}

	// remove event handlers
	advWatcher.Received(recvToken);
	advWatcher.Stopped(stoppedToken);

	return addr;
}


int main()
{
	winrt::init_apartment();

	std::wcout << "Main thread: " << std::this_thread::get_id() << std::endl;

	uint64_t addr = GetFirstAdvertisingBLEAddr();
	if (addr == 0) {
		std::wcout << L"Failed to find advertising BLE device." << std::endl;
		return 1;
	}

	std::wcout << "Found BLE device: " << GetDeviceName(addr) << std::endl;

	BluetoothLEDevice dev = BluetoothLEDevice::FromBluetoothAddressAsync(addr).get();

	GattDeviceServicesResult result = dev.GetGattServicesAsync(BluetoothCacheMode::Uncached).get();
	if (result.Status() == GattCommunicationStatus::Success)
	{
		IVectorView<GattDeviceService> services = result.Services();
		for (GattDeviceService service : services) {
			auto uuid = service.Uuid();
			std::wcout << L" Characteristic: " << ServiceToString(uuid) << std::endl;
		}
	}
	else
	{
		std::wcout << L"Falied to read GATT services: " << GattCommunicationStatusToString(result.Status()) << std::endl;
	}

	return 0;
}
