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
	if (_mcuOutData.temperatureSensor1 != _prevMcuOutData.temperatureSensor1)
	{
		emit temperatureValueChanged(_mcuOutData.temperatureSensor1);
	}
}
