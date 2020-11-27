#pragma once

// библиотека для работы с протоколом 1-Wire
#include <OneWire.h>

// библиотека для работы с датчиком DS18B20
#include <DallasTemperature.h>

class TemperatureSensors
{
public:

	TemperatureSensors();
	void init();
	void update();

private:

	OneWire _oneWire1;
	OneWire _oneWire2;
	OneWire _oneWire3;

	DallasTemperature _temperatureSensor1;
	DallasTemperature _temperatureSensor2;
	DallasTemperature _temperatureSensor3;

	DeviceAddress _temperatureSensorAddr1;
	DeviceAddress _temperatureSensorAddr2;
	DeviceAddress _temperatureSensorAddr3;
};

