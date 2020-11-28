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
    DataManager::outData().dustSensor = analogRead(DUST_RES_INT);
    if (DataManager::outData().dustSensor > 250) DataManager::outData().dustSensor = 250;

	if (DataManager::outData().dustSensor > 60)
	{
		if (DataManager::config().dustFlag_pcShutdown)
		{
			PcPower::on();
		}
	}
}
