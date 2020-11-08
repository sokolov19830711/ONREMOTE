#include "McuDataManager.h"

#include <QDebug>
#include <QCoreApplication>

McuDataManager::McuDataManager()
{
	_settings = QSharedPointer<QSettings>::create(QCoreApplication::applicationDirPath() + "/settings.ini", QSettings::IniFormat);

	_mcuInData.breakInFlags1 = _settings->value("breakInFlags").toUInt();
	_mcuInData.dustFlags1 = _settings->value("dustFlags").toUInt();

	_mcuInData.temperatureFlags1 = _settings->value("temperatureFlags").toUInt();
	_mcuInData.temperatureMinValue1 = _settings->value("temperatureMinValue1").toInt();
	_mcuInData.temperatureMaxValue1 = _settings->value("temperatureMaxValue1").toInt();

	_mcuInData.moistureFlags = _settings->value("moistureFlags").toUInt();
	_mcuInData.moistureMinValue = _settings->value("moistureMinValue").toInt();
	_mcuInData.moistureMaxValue = _settings->value("moistureMaxValue").toInt();

	_mcuInData.powerButtonPwdLevel = _settings->value("PWR/powerButtonPwdLevel").toInt();
	_mcuInData.powerButtonPwdDigit1 = _settings->value("PWR/digit1").toInt();
	_mcuInData.powerButtonPwdDigit2 = _settings->value("PWR/digit2").toInt();
	_mcuInData.powerButtonPwdDigit3 = _settings->value("PWR/digit3").toInt();
	_mcuInData.digitInputPeriod = _settings->value("PWR/digitInputPeriod", 3).toInt();
}

McuDataManager::~McuDataManager()
{
	_settings->setValue("breakInFlags", _mcuInData.breakInFlags1);
	_settings->setValue("dustFlags", _mcuInData.dustFlags1);

	_settings->setValue("temperatureFlags", _mcuInData.temperatureFlags1);
	_settings->setValue("temperatureMinValue1", _mcuInData.temperatureMinValue1);
	_settings->setValue("temperatureMaxValue1", _mcuInData.temperatureMaxValue1);

	_settings->setValue("moistureFlags", _mcuInData.moistureFlags);
	_settings->setValue("moistureMinValue", _mcuInData.moistureMinValue);
	_settings->setValue("moistureMaxValue", _mcuInData.moistureMaxValue);

	_settings->setValue("PWR/powerButtonPwdLevel", _mcuInData.powerButtonPwdLevel);
	_settings->setValue("PWR/digit1", _mcuInData.powerButtonPwdDigit1);
	_settings->setValue("PWR/digit2", _mcuInData.powerButtonPwdDigit2);
	_settings->setValue("PWR/digit3", _mcuInData.powerButtonPwdDigit3);

	_settings->setValue("PWR/digitInputPeriod", _mcuInData.digitInputPeriod);
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
