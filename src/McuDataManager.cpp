#include "McuDataManager.h"

#include <QDebug>

McuDataManager::McuDataManager()
{
	
}

McuInData& McuDataManager::inData()
{
	return _mcuInData;
}

McuOutData& McuDataManager::outData()
{
	return _mcuOutData;
}

void McuDataManager::writeMcuOutData(const QByteArray& data)
{
	_prevMcuOutData = _mcuOutData;
	memcpy(&_mcuOutData, data.data(), sizeof(McuOutData));
	update();
}

void McuDataManager::update()
{
	if (_mcuOutData.breakInSensor1 != _prevMcuOutData.breakInSensor1)
	{
		emit breakIn1ValueChanged(_mcuOutData.breakInSensor1);
	}

	if (_mcuOutData.breakInSensor2 != _prevMcuOutData.breakInSensor2)
	{
		emit breakIn2ValueChanged(_mcuOutData.breakInSensor2);
	}

	if (_mcuOutData.temperatureSensor1 != _prevMcuOutData.temperatureSensor1)
	{
		emit temperatureValueChanged(_mcuOutData.temperatureSensor1);
	}

	if (_mcuOutData.dustSensor1 != _prevMcuOutData.dustSensor1)
	{
		emit dustinessValueChanged(_mcuOutData.dustSensor1);
	}
}
