#include "TemperatureSensors.h"
#include "DataManager.h"
#include "Krakeenone_pinout.h"
#include "Beeper.h"
#include "PcPower.h"
#include "TricolorLED.h"

TemperatureSensors::TemperatureSensors()
{
	
}

void TemperatureSensors::init()
{
	// создаём объект для работы с библиотекой OneWire
	_oneWire1 = OneWire(TEMP1);
	_oneWire2 = OneWire(TEMP2);

	_temperatureSensor1 = DallasTemperature(&_oneWire1);
	_temperatureSensor2 = DallasTemperature(&_oneWire2);

	// начинаем работу с датчиками температуры
	_temperatureSensor1.begin();
	_temperatureSensor2.begin();

	// устанавливаем разрешение датчиков, от 9 до 12 бит
	_temperatureSensor1.setResolution(9);
	_temperatureSensor2.setResolution(9);

	_temperatureSensor1.getAddress(_temperatureSensorAddr1, 0);
	_temperatureSensor2.getAddress(_temperatureSensorAddr2, 0);
}

void TemperatureSensors::update()
{
	if (_temperatureSensor1.requestTemperaturesByAddress(_temperatureSensorAddr1)) DataManager::outData().temperatureSensor1 = _temperatureSensor1.getTempC(_temperatureSensorAddr1);
	if (_temperatureSensor2.requestTemperaturesByAddress(_temperatureSensorAddr2)) DataManager::outData().temperatureSensor2 = _temperatureSensor2.getTempC(_temperatureSensorAddr2);

	// Датчик 1
	if (DataManager::config().temperatureFlags1 & ActionsFlag::active)
	{
		if (DataManager::outData().temperatureSensor1 > DataManager::config().temperatureMaxValue1)
		{
			if (DataManager::config().temperatureFlags1 & ActionsFlag::soundSignal)
			{
				Beeper::beep();
			}

			if (DataManager::config().temperatureFlags1 & ActionsFlag::PCShutDown)
			{
				PcPower::on();
			}
		}
	}

	// Датчик 2
	if (DataManager::config().temperatureFlags2 & ActionsFlag::active)
	{
		if (DataManager::outData().temperatureSensor2 > DataManager::config().temperatureMaxValue2)
		{
			if (DataManager::config().temperatureFlags2 & ActionsFlag::soundSignal)
			{
				Beeper::beep();
			}

			if (DataManager::config().temperatureFlags2 & ActionsFlag::PCShutDown)
			{
				PcPower::on();
			}
		}
	}
}
