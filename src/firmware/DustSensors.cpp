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

}

void DustSensors::update()
{
    // Встроенный датчик
    DataManager::outData().dustSensor1 = analogRead(DUST_RES_INT);
    if (DataManager::outData().dustSensor1 > 250) DataManager::outData().dustSensor1 = 250;
    if (DataManager::outData().dustSensor1 > DataManager::config().dustMaxValue1)
    {
        if (DataManager::config().dustFlags1 & ActionsFlag::soundSignal)
        {
            Beeper::beep();
        }
    }

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
}
