#include "TemperatureSensors.h"
#include "DataManager.h"
#include "Pinout.h"
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

	_temperatureSensor1 = DallasTemperature(&_oneWire1);

	// начинаем работу с датчиками температуры
	_temperatureSensor1.begin();

	// устанавливаем разрешение датчиков, от 9 до 12 бит
	_temperatureSensor1.setResolution(9);

	_temperatureSensor1.getAddress(_temperatureSensorAddr1, 0);
}

void TemperatureSensors::update()
{
	if (_temperatureSensor1.requestTemperaturesByAddress(_temperatureSensorAddr1)) DataManager::outData().temperatureSensor = _temperatureSensor1.getTempC(_temperatureSensorAddr1);

	// Датчик 1
	
	if (DataManager::outData().temperatureSensor > DataManager::config().temperatureMaxValue || DataManager::outData().temperatureSensor < DataManager::config().temperatureMinValue)
	{
		if (DataManager::config().temperatureFlag_pcShutdown)
		{
			PcPower::off();
		}
	}
}
