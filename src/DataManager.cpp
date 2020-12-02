#include "DataManager.h"

#include <QDebug>
#include <QCoreApplication>
#include <QStandardPaths>

DataManager::DataManager()
{
	//_settings = QSharedPointer<QSettings>::create(QCoreApplication::applicationDirPath() + "/settings.ini", QSettings::IniFormat);

	_settings = QSharedPointer<QSettings>::create(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) + "/settings.ini", QSettings::IniFormat);

	_mcuInData.functionsFlags = _settings->value("functionsFlags", 72).toUInt();
	/*_mcuInData.breakInFlags1 = _settings->value("breakInFlags").toUInt();
	_mcuInData.dustFlags1 = _settings->value("dustFlags").toUInt();*/

	/*_mcuInData.temperatureFlags1 = _settings->value("temperatureFlags").toUInt();
	_mcuInData.temperatureMinValue1 = _settings->value("temperatureMinValue1").toInt();
	_mcuInData.temperatureMaxValue1 = _settings->value("temperatureMaxValue1").toInt();*/

	/*_mcuInData.moistureFlags = _settings->value("moistureFlags").toUInt();
	_mcuInData.moistureMinValue = _settings->value("moistureMinValue").toInt();
	_mcuInData.moistureMaxValue = _settings->value("moistureMaxValue").toInt();*/

	_mcuInData.powerButtonPwdLevel = _settings->value("PWR/powerButtonPwdLevel", 0).toInt();
	_mcuInData.powerButtonPwdDigit1 = _settings->value("PWR/digit1").toInt();
	_mcuInData.powerButtonPwdDigit2 = _settings->value("PWR/digit2").toInt();
	_mcuInData.powerButtonPwdDigit3 = _settings->value("PWR/digit3").toInt();
	_mcuInData.digitInputPeriod = _settings->value("PWR/digitInputPeriod", 3).toInt();
}

DataManager::~DataManager()
{
	_settings->setValue("functionsFlags", _mcuInData.functionsFlags);
	/*_settings->setValue("breakInFlags", _mcuInData.breakInFlags1);
	_settings->setValue("dustFlags", _mcuInData.dustFlags1);

	_settings->setValue("temperatureFlags", _mcuInData.temperatureFlags1);
	_settings->setValue("temperatureMinValue1", _mcuInData.temperatureMinValue1);
	_settings->setValue("temperatureMaxValue1", _mcuInData.temperatureMaxValue1);

	_settings->setValue("moistureFlags", _mcuInData.moistureFlags);
	_settings->setValue("moistureMinValue", _mcuInData.moistureMinValue);
	_settings->setValue("moistureMaxValue", _mcuInData.moistureMaxValue);*/

	_settings->setValue("PWR/powerButtonPwdLevel", _mcuInData.powerButtonPwdLevel);
	_settings->setValue("PWR/digit1", _mcuInData.powerButtonPwdDigit1);
	_settings->setValue("PWR/digit2", _mcuInData.powerButtonPwdDigit2);
	_settings->setValue("PWR/digit3", _mcuInData.powerButtonPwdDigit3);

	_settings->setValue("PWR/digitInputPeriod", _mcuInData.digitInputPeriod);
}

McuInData& DataManager::inData()
{
	return _mcuInData;
}

McuOutData& DataManager::outData()
{
	return _mcuOutData;
}

QSharedPointer<QSettings> DataManager::settings()
{
	return _settings;
}

void DataManager::writeMcuOutData(const QByteArray& data)
{
	_prevMcuOutData = _mcuOutData;
	memcpy(&_mcuOutData, data.data(), sizeof(McuOutData));
	update();
}

//--- Геттеры --------------------------------------------------------------------

bool DataManager::isDeviceActive() const
{
	return _mcuInData.functionsFlags & FunctionsFlag::turnOn;
}

bool DataManager::isStartOnBoot() const
{
	return _settings->value("startOnBoot").toBool();
}

bool DataManager::isLockOS() const
{
	return _settings->value("lockOS").toBool();
}

bool DataManager::isLedActive() const
{
	return _mcuInData.functionsFlags & FunctionsFlag::led;
}

int DataManager::powerButtonPwdLevel() const
{
	return _mcuInData.powerButtonPwdLevel;
}

int DataManager::digitInputPeriod() const
{
	return _mcuInData.digitInputPeriod;
}

int DataManager::powerButtonPwdDigit1() const
{
	return _mcuInData.powerButtonPwdDigit1;
}

int DataManager::powerButtonPwdDigit2() const
{
	return _mcuInData.powerButtonPwdDigit2;
}

int DataManager::powerButtonPwdDigit3() const
{
	return _mcuInData.powerButtonPwdDigit3;
}

//------------------------------------------------------------------------------------------------

void DataManager::update()
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

//--- public slots ----------------------------------------------------------------------------

void DataManager::setDeviceActive(bool state)
{
	setBit(_mcuInData.functionsFlags, FunctionsFlag::turnOn, state);
	emit deviceActiveChanged(state);
}

void DataManager::setLedActive(bool state)
{
	setBit(_mcuInData.functionsFlags, FunctionsFlag::led, state);
	emit ledActiveChanged(state);
}

void DataManager::setPowerButtonPwdLevel(int value)
{
	if(_mcuInData.powerButtonPwdLevel != value)
		_mcuInData.powerButtonPwdLevel = value;
}

void DataManager::setDigitInputPeriod(int value)
{
	if(_mcuInData.digitInputPeriod != value)
		_mcuInData.digitInputPeriod = value;
}

void DataManager::setPowerButtonPwdDigit1(int value)
{
	if (_mcuInData.powerButtonPwdDigit1 != value)
		_mcuInData.powerButtonPwdDigit1 = value;
}

void DataManager::setPowerButtonPwdDigit2(int value)
{
	if (_mcuInData.powerButtonPwdDigit2 != value)
		_mcuInData.powerButtonPwdDigit2 = value;
}

void DataManager::setPowerButtonPwdDigit3(int value)
{
	if (_mcuInData.powerButtonPwdDigit3 != value)
		_mcuInData.powerButtonPwdDigit3 = value;
}
