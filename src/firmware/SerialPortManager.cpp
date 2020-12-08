#include "SerialPortManager.h"

#include <Arduino.h>
#include "DataManager.h"
#include "Beeper.h"

SerialPortManager::SerialPortManager()
{

}

void SerialPortManager::init(int baudRate)
{
	Serial.begin(baudRate);
}

void SerialPortManager::update(int dt)
{

	if (_counter < _updateInterval)
	{
		_counter += dt;
		return;
	}

	_counter = 0;

	switch (_mode)
	{

	// Нормальный режим работы
	case SerialPortManager::normal:

		Serial.write(reinterpret_cast<uint8_t*>(&DataManager::outData()), sizeof(McuOutData)); // Отсылаем структуру с текущим состоянием устройства

		if (Serial.peek() == START_MARKER1)
		{
			if (Serial.readBytes(reinterpret_cast<uint8_t*>(&_inData), sizeof(McuInData)) == sizeof(McuInData)) // Принимаем структуру с заданиями от программы на ПК
			{
				if ((_inData.startMarker1 == START_MARKER1) && (_inData.startMarker2 == START_MARKER2))
				{
					const char* tmpPtr1 = reinterpret_cast<const char*>(&DataManager::config());
					const char* tmpPtr2 = reinterpret_cast<const char*>(&_inData);
					

					for (size_t i = 0; i < sizeof(McuInData); i++)
					{
						if (tmpPtr1[i] != tmpPtr2[i])
						{
							_needToUpdateSettings = true;
							break;
						}
					}
				}
			}
		}

		break;

	case SerialPortManager::timeSet:
		break;

	default:
		break;

	}
}

bool SerialPortManager::needToUpdateConfig() const
{
	return _needToUpdateSettings;
}

void SerialPortManager::setConfigUpdated()
{
	_needToUpdateSettings = false;
}

SerialPortManager::Mode SerialPortManager::mode() const
{
	return _mode;
}

const McuInData* SerialPortManager::inData() const
{
	return &_inData;
}
