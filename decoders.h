#pragma once

std::wstring UUIDToString(const winrt::guid & uuid);
std::wstring ServiceToString(const winrt::guid & uuid);
std::wstring CharacteristicToString(const winrt::guid & uuid);
std::wstring AdvertisementTypeToString(BluetoothLEAdvertisementType type);
std::wstring AdvertisementDataTypeToString(uint8_t dataType);
std::wstring AddrToString(uint64_t addr);
std::wstring GattCommunicationStatusToString(GattCommunicationStatus status);