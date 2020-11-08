#include "MoistureSensors.h"
#include "DataManager.h"
#include "Krakeenone_pinout.h"
#include "Beeper.h"
#include "PcPower.h"

MoistureSensors::MoistureSensors()
{
}

MoistureSensors::~MoistureSensors()
{
	delete _dht;
}

void MoistureSensors::init()
{
	//создаём объект для работы с DHT11
	_dht = new DHT(DHT_PIN, DHT11);
	//старт DHT11
	_dht->begin();
}

void MoistureSensors::update()
{
	DataManager::outData().moistureSensor = _dht->readHumidity();
	if (DataManager::outData().moistureSensor > DataManager::config().moistureMaxValue ||
		DataManager::outData().moistureSensor < DataManager::config().moistureMinValue)
	{
		if (DataManager::config().moistureFlags & ActionsFlag::soundSignal)
		{
			Beeper::beep();
		}

		if (DataManager::config().moistureFlags & ActionsFlag::PCShutDown)
		{
			PcPower::on();
		}
	}
}
