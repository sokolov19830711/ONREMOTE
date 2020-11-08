#include "BreakInSensors.h"

#include <Arduino.h>
#include "DataManager.h"
#include "Krakeenone_pinout.h"
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
	// ���������� ������ ��������

	int sensor = !digitalRead(BREAK_IN_SENSOR_INT);
	DataManager::outData().breakInSensor1 = sensor;

	if (sensor != DataManager::config().breakInSensorNormalState1)
	{
		if (DataManager::config().breakInFlags1 & ActionsFlag::soundSignal)
		{
			Beeper::beep();
		}

		if (DataManager::config().breakInFlags1 & ActionsFlag::PCShutDown)
		{
			PcPower::on();
		}
	}

	// �������� �����������
	int switch1 = !digitalRead(TERMINAL_SWITCH1);
	DataManager::outData().breakInSensor2 = switch1;

	if (switch1 != DataManager::config().breakInSensorNormalState2)
	{
		if (DataManager::config().breakInFlags2 & ActionsFlag::soundSignal)
		{
			Beeper::beep();
		}

		if (DataManager::config().breakInFlags2 & ActionsFlag::PCShutDown)
		{
			PcPower::on();
		}
	}

	int switch2 = !digitalRead(TERMINAL_SWITCH2);
	DataManager::outData().breakInSensor3 = switch2;

	if (switch2 != DataManager::config().breakInSensorNormalState3)
	{
		if (DataManager::config().breakInFlags3 & ActionsFlag::soundSignal)
		{
			Beeper::beep();
		}

		if (DataManager::config().breakInFlags3 & ActionsFlag::PCShutDown)
		{
			PcPower::on();
		}
	}
}

