#include <Arduino.h>

#include "DustSensors.h"
#include "DataManager.h"
#include "Krakeenone_pinout.h"
#include "Beeper.h"
#include "PcPower.h"

DustSensors::DustSensors()
{

}

void DustSensors::init()
{
    digitalWrite(DUST_LED_INT, HIGH);
}

void DustSensors::update()
{
    // Встроенный датчик
    DataManager::outData().dustSensor1 = analogRead(A3);
    if (DataManager::outData().dustSensor1 > 250) DataManager::outData().dustSensor1 = 250;
    if (DataManager::outData().dustSensor1 > DataManager::config().dustMaxValue1)
    {
        if (DataManager::config().dustFlags1 & ActionsFlag::soundSignal)
        {
            Beeper::beep();
        }
    }

    // Выносной датчик Sharp

	digitalWrite(DUST_LED_SHARP, LOW); // вкл внутренний светик в датчике
	delayMicroseconds(280); //выждали, это важно

	float voltsMeasured = analogRead(DUST_RES_SHARP); // считали значение

	delayMicroseconds(40);// выждать тоже важно
	digitalWrite(DUST_LED_SHARP, HIGH); // выкл светик

    DataManager::outData().dustSensor2 = (0.17f * voltsMeasured * (4.096f / 1024.0f) - 0.1f) * 1000.f;

	if (DataManager::outData().dustSensor1 > DataManager::config().dustMaxValue1)
	{
		if (DataManager::config().dustFlags1 & ActionsFlag::soundSignal)
		{
			Beeper::beep();
		}

		if (DataManager::config().dustFlags1 & ActionsFlag::PCShutDown)
		{
			PcPower::on();
		}
	}

	if (DataManager::outData().dustSensor2 > DataManager::config().dustMaxValue2)
	{
		if (DataManager::config().dustFlags2 & ActionsFlag::soundSignal)
		{
			Beeper::beep();
		}

		if (DataManager::config().dustFlags2 & ActionsFlag::PCShutDown)
		{
			PcPower::on();
		}
	}
}
