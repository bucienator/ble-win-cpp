#include "pch.h"


std::wstring UUIDToString(const winrt::guid & uuid)
{
	std::wstringstream str;
	str << std::uppercase << std::hex;
	str << std::setw(8) << std::setfill(L'0') << uuid.Data1 << L"-";
	str << std::setw(4) << std::setfill(L'0') << uuid.Data2 << L"-";
	str << std::setw(4) << std::setfill(L'0') << uuid.Data3 << L"-";
	str << std::setw(2) << std::setfill(L'0') << static_cast<short>(uuid.Data4[0])
		<< std::setw(2) << std::setfill(L'0') << static_cast<short>(uuid.Data4[1])
		<< '-'
		<< std::setw(2) << std::setfill(L'0') << static_cast<short>(uuid.Data4[2])
		<< std::setw(2) << std::setfill(L'0') << static_cast<short>(uuid.Data4[3])
		<< std::setw(2) << std::setfill(L'0') << static_cast<short>(uuid.Data4[4])
		<< std::setw(2) << std::setfill(L'0') << static_cast<short>(uuid.Data4[5])
		<< std::setw(2) << std::setfill(L'0') << static_cast<short>(uuid.Data4[6])
		<< std::setw(2) << std::setfill(L'0') << static_cast<short>(uuid.Data4[7]);
	str << std::nouppercase;
	return str.str();

}

std::wstring ServiceToString(const winrt::guid & uuid)
{
	if (uuid == GattServiceUuids::AlertNotification())
	{
		return L"Alert Notification";
	}
	if (uuid == GattServiceUuids::Battery())
	{
		return L"Battery";
	}
	if (uuid == GattServiceUuids::BloodPressure())
	{
		return L"Blood Pressure";
	}
	if (uuid == GattServiceUuids::CurrentTime())
	{
		return L"Current Time";
	}
	if (uuid == GattServiceUuids::CyclingPower())
	{
		return L"Cycling Power";
	}
	if (uuid == GattServiceUuids::CyclingSpeedAndCadence())
	{
		return L"Cycling Speed and Cadence";
	}
	if (uuid == GattServiceUuids::DeviceInformation())
	{
		return L"Device Information";
	}
	if (uuid == GattServiceUuids::GenericAccess())
	{
		return L"Generic Access";
	}
	if (uuid == GattServiceUuids::GenericAttribute())
	{
		return L"Generic Attribute";
	}
	if (uuid == GattServiceUuids::Glucose())
	{
		return L"Glucose";
	}
	if (uuid == GattServiceUuids::HealthThermometer())
	{
		return L"Health Thermometer";
	}
	if (uuid == GattServiceUuids::HeartRate())
	{
		return L"Heart Rate";
	}
	if (uuid == GattServiceUuids::HumanInterfaceDevice())
	{
		return L"Human Interface Device";
	}
	if (uuid == GattServiceUuids::ImmediateAlert())
	{
		return L"Immediate Alert";
	}
	if (uuid == GattServiceUuids::LinkLoss())
	{
		return L"Link Loss";
	}
	if (uuid == GattServiceUuids::LocationAndNavigation())
	{
		return L"Location and Navigation";
	}
	if (uuid == GattServiceUuids::NextDstChange())
	{
		return L"Next Dst Change";
	}
	if (uuid == GattServiceUuids::PhoneAlertStatus())
	{
		return L"Phone Alert Status";
	}
	if (uuid == GattServiceUuids::ReferenceTimeUpdate())
	{
		return L"Reference Time Update";
	}
	if (uuid == GattServiceUuids::RunningSpeedAndCadence())
	{
		return L"Running Speed and Cadence";
	}
	if (uuid == GattServiceUuids::ScanParameters())
	{
		return L"Scan Parameters";
	}
	if (uuid == GattServiceUuids::TxPower())
	{
		return L"Tx Power";
	}
	return UUIDToString(uuid);
}

std::wstring CharacteristicToString(const winrt::guid & uuid)
{
	if (uuid == GattCharacteristicUuids::AlertCategoryId())
	{
		return L"AlertCategoryId";
	}
	if (uuid == GattCharacteristicUuids::AlertCategoryIdBitMask())
	{
		return L"AlertCategoryIdBitMask";
	}
	if (uuid == GattCharacteristicUuids::AlertLevel())
	{
		return L"AlertLevel";
	}
	if (uuid == GattCharacteristicUuids::AlertNotificationControlPoint())
	{
		return L"AlertNotificationControlPoint";
	}
	if (uuid == GattCharacteristicUuids::AlertStatus())
	{
		return L"AlertStatus";
	}
	if (uuid == GattCharacteristicUuids::BatteryLevel())
	{
		return L"BatteryLevel";
	}
	if (uuid == GattCharacteristicUuids::BloodPressureFeature())
	{
		return L"BloodPressureFeature";
	}
	if (uuid == GattCharacteristicUuids::BloodPressureMeasurement())
	{
		return L"BloodPressureMeasurement";
	}
	if (uuid == GattCharacteristicUuids::BodySensorLocation())
	{
		return L"BodySensorLocation";
	}
	if (uuid == GattCharacteristicUuids::BootKeyboardInputReport())
	{
		return L"BootKeyboardInputReport";
	}
	if (uuid == GattCharacteristicUuids::BootKeyboardOutputReport())
	{
		return L"BootKeyboardOutputReport";
	}
	if (uuid == GattCharacteristicUuids::BootMouseInputReport())
	{
		return L"BootMouseInputReport";
	}
	if (uuid == GattCharacteristicUuids::CscFeature())
	{
		return L"CscFeature";
	}
	if (uuid == GattCharacteristicUuids::CscMeasurement())
	{
		return L"CscMeasurement";
	}
	if (uuid == GattCharacteristicUuids::CurrentTime())
	{
		return L"CurrentTime";
	}
	if (uuid == GattCharacteristicUuids::CyclingPowerControlPoint())
	{
		return L"CyclingPowerControlPoint";
	}
	if (uuid == GattCharacteristicUuids::CyclingPowerFeature())
	{
		return L"CyclingPowerFeature";
	}
	if (uuid == GattCharacteristicUuids::CyclingPowerMeasurement())
	{
		return L"CyclingPowerMeasurement";
	}
	if (uuid == GattCharacteristicUuids::CyclingPowerVector())
	{
		return L"CyclingPowerVector";
	}
	if (uuid == GattCharacteristicUuids::DateTime())
	{
		return L"DateTime";
	}
	if (uuid == GattCharacteristicUuids::DayDateTime())
	{
		return L"DayDateTime";
	}
	if (uuid == GattCharacteristicUuids::DayOfWeek())
	{
		return L"DayOfWeek";
	}
	if (uuid == GattCharacteristicUuids::DstOffset())
	{
		return L"DstOffset";
	}
	if (uuid == GattCharacteristicUuids::ExactTime256())
	{
		return L"ExactTime256";
	}
	if (uuid == GattCharacteristicUuids::FirmwareRevisionString())
	{
		return L"FirmwareRevisionString";
	}
	if (uuid == GattCharacteristicUuids::GapAppearance())
	{
		return L"GapAppearance";
	}
	if (uuid == GattCharacteristicUuids::GapDeviceName())
	{
		return L"GapDeviceName";
	}
	if (uuid == GattCharacteristicUuids::GapPeripheralPreferredConnectionParameters())
	{
		return L"GapPeripheralPreferredConnectionParameters";
	}
	if (uuid == GattCharacteristicUuids::GapPeripheralPrivacyFlag())
	{
		return L"GapPeripheralPrivacyFlag";
	}
	if (uuid == GattCharacteristicUuids::GapReconnectionAddress())
	{
		return L"GapReconnectionAddress";
	}
	if (uuid == GattCharacteristicUuids::GattServiceChanged())
	{
		return L"GattServiceChanged";
	}
	if (uuid == GattCharacteristicUuids::GlucoseFeature())
	{
		return L"GlucoseFeature";
	}
	if (uuid == GattCharacteristicUuids::GlucoseMeasurement())
	{
		return L"GlucoseMeasurement";
	}
	if (uuid == GattCharacteristicUuids::GlucoseMeasurementContext())
	{
		return L"GlucoseMeasurementContext";
	}
	if (uuid == GattCharacteristicUuids::HardwareRevisionString())
	{
		return L"HardwareRevisionString";
	}
	if (uuid == GattCharacteristicUuids::HeartRateControlPoint())
	{
		return L"HeartRateControlPoint";
	}
	if (uuid == GattCharacteristicUuids::HeartRateMeasurement())
	{
		return L"HeartRateMeasurement";
	}
	if (uuid == GattCharacteristicUuids::HidControlPoint())
	{
		return L"HidControlPoint";
	}
	if (uuid == GattCharacteristicUuids::HidInformation())
	{
		return L"HidInformation";
	}
	if (uuid == GattCharacteristicUuids::Ieee1107320601RegulatoryCertificationDataList())
	{
		return L"Ieee1107320601RegulatoryCertificationDataList";
	}
	if (uuid == GattCharacteristicUuids::IntermediateCuffPressure())
	{
		return L"IntermediateCuffPressure";
	}
	if (uuid == GattCharacteristicUuids::IntermediateTemperature())
	{
		return L"IntermediateTemperature";
	}
	if (uuid == GattCharacteristicUuids::LnControlPoint())
	{
		return L"LnControlPoint";
	}
	if (uuid == GattCharacteristicUuids::LnFeature())
	{
		return L"LnFeature";
	}
	if (uuid == GattCharacteristicUuids::LocalTimeInformation())
	{
		return L"LocalTimeInformation";
	}
	if (uuid == GattCharacteristicUuids::LocationAndSpeed())
	{
		return L"LocationAndSpeed";
	}
	if (uuid == GattCharacteristicUuids::ManufacturerNameString())
	{
		return L"ManufacturerNameString";
	}
	if (uuid == GattCharacteristicUuids::MeasurementInterval())
	{
		return L"MeasurementInterval";
	}
	if (uuid == GattCharacteristicUuids::ModelNumberString())
	{
		return L"ModelNumberString";
	}
	if (uuid == GattCharacteristicUuids::Navigation())
	{
		return L"Navigation";
	}
	if (uuid == GattCharacteristicUuids::NewAlert())
	{
		return L"NewAlert";
	}
	if (uuid == GattCharacteristicUuids::PnpId())
	{
		return L"PnpId";
	}
	if (uuid == GattCharacteristicUuids::PositionQuality())
	{
		return L"PositionQuality";
	}
	if (uuid == GattCharacteristicUuids::ProtocolMode())
	{
		return L"ProtocolMode";
	}
	if (uuid == GattCharacteristicUuids::RecordAccessControlPoint())
	{
		return L"RecordAccessControlPoint";
	}
	if (uuid == GattCharacteristicUuids::ReferenceTimeInformation())
	{
		return L"ReferenceTimeInformation";
	}
	if (uuid == GattCharacteristicUuids::Report())
	{
		return L"Report";
	}
	if (uuid == GattCharacteristicUuids::ReportMap())
	{
		return L"ReportMap";
	}
	if (uuid == GattCharacteristicUuids::RingerControlPoint())
	{
		return L"RingerControlPoint";
	}
	if (uuid == GattCharacteristicUuids::RingerSetting())
	{
		return L"RingerSetting";
	}
	if (uuid == GattCharacteristicUuids::RscFeature())
	{
		return L"RscFeature";
	}
	if (uuid == GattCharacteristicUuids::RscMeasurement())
	{
		return L"RscMeasurement";
	}
	if (uuid == GattCharacteristicUuids::ScanIntervalWindow())
	{
		return L"ScanIntervalWindow";
	}
	if (uuid == GattCharacteristicUuids::ScanRefresh())
	{
		return L"ScanRefresh";
	}
	if (uuid == GattCharacteristicUuids::SCControlPoint())
	{
		return L"SCControlPoint";
	}
	if (uuid == GattCharacteristicUuids::SensorLocation())
	{
		return L"SensorLocation";
	}
	if (uuid == GattCharacteristicUuids::SerialNumberString())
	{
		return L"SerialNumberString";
	}
	if (uuid == GattCharacteristicUuids::SoftwareRevisionString())
	{
		return L"SoftwareRevisionString";
	}
	if (uuid == GattCharacteristicUuids::SupportedNewAlertCategory())
	{
		return L"SupportedNewAlertCategory";
	}
	if (uuid == GattCharacteristicUuids::SupportUnreadAlertCategory())
	{
		return L"SupportUnreadAlertCategory";
	}
	if (uuid == GattCharacteristicUuids::SystemId())
	{
		return L"SystemId";
	}
	if (uuid == GattCharacteristicUuids::TemperatureMeasurement())
	{
		return L"TemperatureMeasurement";
	}
	if (uuid == GattCharacteristicUuids::TemperatureType())
	{
		return L"TemperatureType";
	}
	if (uuid == GattCharacteristicUuids::TimeAccuracy())
	{
		return L"TimeAccuracy";
	}
	if (uuid == GattCharacteristicUuids::TimeSource())
	{
		return L"TimeSource";
	}
	if (uuid == GattCharacteristicUuids::TimeUpdateControlPoint())
	{
		return L"TimeUpdateControlPoint";
	}
	if (uuid == GattCharacteristicUuids::TimeUpdateState())
	{
		return L"TimeUpdateState";
	}
	if (uuid == GattCharacteristicUuids::TimeWithDst())
	{
		return L"TimeWithDst";
	}
	if (uuid == GattCharacteristicUuids::TimeZone())
	{
		return L"TimeZone";
	}
	if (uuid == GattCharacteristicUuids::TxPowerLevel())
	{
		return L"TxPowerLevel";
	}
	if (uuid == GattCharacteristicUuids::UnreadAlertStatus())
	{
		return L"UnreadAlertStatus";
	}
	return UUIDToString(uuid);

}

std::wstring AdvertisementTypeToString(BluetoothLEAdvertisementType type)
{
	switch (type) {
	case BluetoothLEAdvertisementType::ConnectableUndirected:
		return L"Connectable Undirected";
	case BluetoothLEAdvertisementType::ConnectableDirected:
		return L"Connectable Directed";
	case BluetoothLEAdvertisementType::ScannableUndirected:
		return L"Scannable Undirected";
	case BluetoothLEAdvertisementType::ScanResponse:
		return L"Scan Response";
	case BluetoothLEAdvertisementType::NonConnectableUndirected:
		return L"Non-Connectable Undirected";
	default:
		return L"Unknown advertisement type";
	}
}

std::wstring AdvertisementDataTypeToString(uint8_t dataType)
{
	if (dataType == BluetoothLEAdvertisementDataTypes::AdvertisingInterval())
	{
		return L"AdvertisingInterval";
	}
	if (dataType == BluetoothLEAdvertisementDataTypes::Appearance())
	{
		return L"Appearance";
	}
	if (dataType == BluetoothLEAdvertisementDataTypes::CompleteLocalName())
	{
		return L"CompleteLocalName";
	}
	if (dataType == BluetoothLEAdvertisementDataTypes::CompleteService128BitUuids())
	{
		return L"CompleteService128BitUuids";
	}
	if (dataType == BluetoothLEAdvertisementDataTypes::CompleteService16BitUuids())
	{
		return L"CompleteService16BitUuids";
	}
	if (dataType == BluetoothLEAdvertisementDataTypes::CompleteService32BitUuids())
	{
		return L"CompleteService32BitUuids";
	}
	if (dataType == BluetoothLEAdvertisementDataTypes::Flags())
	{
		return L"Flags";
	}
	if (dataType == BluetoothLEAdvertisementDataTypes::IncompleteService128BitUuids())
	{
		return L"IncompleteService128BitUuids";
	}
	if (dataType == BluetoothLEAdvertisementDataTypes::IncompleteService16BitUuids())
	{
		return L"IncompleteService16BitUuids";
	}
	if (dataType == BluetoothLEAdvertisementDataTypes::IncompleteService32BitUuids())
	{
		return L"IncompleteService32BitUuids";
	}
	if (dataType == BluetoothLEAdvertisementDataTypes::ManufacturerSpecificData())
	{
		return L"ManufacturerSpecificData";
	}
	if (dataType == BluetoothLEAdvertisementDataTypes::PublicTargetAddress())
	{
		return L"PublicTargetAddress";
	}
	if (dataType == BluetoothLEAdvertisementDataTypes::RandomTargetAddress())
	{
		return L"RandomTargetAddress";
	}
	if (dataType == BluetoothLEAdvertisementDataTypes::ServiceData128BitUuids())
	{
		return L"ServiceData128BitUuids";
	}
	if (dataType == BluetoothLEAdvertisementDataTypes::ServiceData16BitUuids())
	{
		return L"ServiceData16BitUuids";
	}
	if (dataType == BluetoothLEAdvertisementDataTypes::ServiceData32BitUuids())
	{
		return L"ServiceData32BitUuids";
	}
	if (dataType == BluetoothLEAdvertisementDataTypes::ServiceSolicitation128BitUuids())
	{
		return L"ServiceSolicitation128BitUuids";
	}
	if (dataType == BluetoothLEAdvertisementDataTypes::ServiceSolicitation16BitUuids())
	{
		return L"ServiceSolicitation16BitUuids";
	}
	if (dataType == BluetoothLEAdvertisementDataTypes::ServiceSolicitation32BitUuids())
	{
		return L"ServiceSolicitation32BitUuids";
	}
	if (dataType == BluetoothLEAdvertisementDataTypes::ShortenedLocalName())
	{
		return L"ShortenedLocalName";
	}
	if (dataType == BluetoothLEAdvertisementDataTypes::PeripheralConnectionIntervalRange())
	{
		return L"PeripheralConnectionIntervalRange ";
	}
	if (dataType == BluetoothLEAdvertisementDataTypes::TxPowerLevel())
	{
		return L"TxPowerLevel";
	}

	return L"Unknown data type " + std::to_wstring(dataType);
}

std::wstring AddrToString(uint64_t addr)
{
	std::wostringstream ret;
	ret << std::hex << std::setfill(L'0')
		<< std::setw(2) << ((addr >> (5 * 8)) & 0xff) << ":"
		<< std::setw(2) << ((addr >> (4 * 8)) & 0xff) << ":"
		<< std::setw(2) << ((addr >> (3 * 8)) & 0xff) << ":"
		<< std::setw(2) << ((addr >> (2 * 8)) & 0xff) << ":"
		<< std::setw(2) << ((addr >> (1 * 8)) & 0xff) << ":"
		<< std::setw(2) << ((addr >> (0 * 8)) & 0xff);
	return ret.str();
}

std::wstring GattCommunicationStatusToString(GattCommunicationStatus status)
{
	switch (status) {
	case GattCommunicationStatus::Success:
		return L"Success";
	case GattCommunicationStatus::AccessDenied:
		return L"Access Denied";
	case GattCommunicationStatus::ProtocolError:
		return L"Protocol Error";
	case GattCommunicationStatus::Unreachable:
		return L"Unreachable";
	default:
		return L"Unknown GATT communication status";
	}

}