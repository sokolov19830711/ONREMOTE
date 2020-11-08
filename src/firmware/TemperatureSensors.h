#pragma once

// ���������� ��� ������ � ���������� 1-Wire
#include <OneWire.h>

// ���������� ��� ������ � �������� DS18B20
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

