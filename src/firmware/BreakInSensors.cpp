#include "BreakInSensors.h"

#include <Arduino.h>
#include "DataManager.h"
#include "Pinout.h"
#include "Beeper.h"
#include "PcPower.h"

BreakInSensors::BreakInSensors()
{

}

void BreakInSensors::init()
{

}

void BreakInSensors::update()
{
	// Встроенный датчик вскрытия

	int sensor = digitalRead(BREAK_IN_SENSOR_INT);
	DataManager::outData().breakInSensor1 = sensor;

	if (sensor != DataManager::config().breakInSensorNormalState1)
	{
		if (DataManager::config().breakInFlag_pcShutdown1)
		{
			PcPower::off();
		}
	}

	// Концевые выключатели
	int switch1 = digitalRead(TERMINAL_SWITCH1);
	DataManager::outData().breakInSensor2 = switch1;

	if (switch1 != DataManager::config().breakInSensorNormalState2)
	{
		if (DataManager::config().breakInFlag_pcShutdown2)
		{
			PcPower::off();
		}
	}
}

