#include "DataManager.h"

#include <QDebug>
#include <QCoreApplication>
#include <QStandardPaths>
#include <QTime>

DataManager::DataManager()
{
	_appStartedTime = QDateTime::currentDateTime();

	_settings = QSharedPointer<QSettings>::create(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) + "/settings.ini", QSettings::IniFormat);

	_mcuInData.turnOn = _settings->value("turnOn", 1).toUInt();
	_mcuInData.soundOn = _settings->value("soundOn", 1).toUInt();
	_mcuInData.ledOn = _settings->value("ledOn", 1).toUInt();

	_mcuInData.dustFlag_pcShutdown = _settings->value("dustFlag_pcShutdown").toUInt();

	_mcuInData.breakInFlag_pcShutdown1 = _settings->value("breakInFlag_pcShutdown1").toUInt();
	_mcuInData.breakInSensorNormalState1 = _settings->value("breakInSensorNormalState1").toUInt();

	_mcuInData.breakInFlag_pcShutdown2 = _settings->value("breakInFlag_pcShutdown2").toUInt();
	_mcuInData.breakInSensorNormalState2 = _settings->value("breakInSensorNormalState2").toUInt();

	_mcuInData.temperatureFlag_pcShutdown = _settings->value("temperatureFlag_pcShutdown").toUInt();
	_mcuInData.temperatureMinValue = _settings->value("temperatureMinValue").toInt();
	_mcuInData.temperatureMaxValue = _settings->value("temperatureMaxValue").toInt();

	_mcuInData.powerButtonPwdLevel = _settings->value("PWR/powerButtonPwdLevel", 0).toInt();
	_mcuInData.powerButtonPwdDigit1 = _settings->value("PWR/digit1").toInt();
	_mcuInData.powerButtonPwdDigit2 = _settings->value("PWR/digit2").toInt();
	_mcuInData.powerButtonPwdDigit3 = _settings->value("PWR/digit3").toInt();
	_mcuInData.digitInputPeriod = _settings->value("PWR/digitInputPeriod", 3).toInt();
}

DataManager::~DataManager()
{
	updatePcTotalRunningTime();

	QStringList settingsKeys = _settingsMap.keys();
	for (auto & key : settingsKeys)
	{
		if (_settingsMap[key])
		{
			_settings->setValue(key, *_settingsMap[key]);
		}
	}
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
}

void DataManager::setSettingsValue(const QString& valueName, unsigned char value)
{
	if (!_settingsMap.contains(valueName))
	{
		return;
	}

	if(_settingsMap[valueName])
	{
		*_settingsMap[valueName] = value;
	}

	else
	{
		_settings->setValue(valueName, value);
	}
}

void DataManager::setSettingsStringValue(const QString& valueName, const QString& value)
{
	_settings->setValue(valueName, value);
}

unsigned char DataManager::getSettingsValue(const QString& valueName) const
{
	if (!_settingsMap.contains(valueName))
	{
		return 0;
	}

	else if (_settingsMap[valueName])
	{
		return *_settingsMap[valueName];
	}

	else
	{
		return _settings->value(valueName).toUInt();
	}
}

QString DataManager::getSettingsStringValue(const QString& valueName) const
{
	return _settings->value(valueName).toString();
}

unsigned char DataManager::getMcuValue(const QString& valueName) const
{
	if (_mcuValuesMap.contains(valueName))
	{
		return *_mcuValuesMap[valueName];
	}

	return 0;
}

QString DataManager::getDeviceSessionTime() const
{
	int sessionTime;
	memcpy(&sessionTime, &(_mcuOutData.sessionTime1), 4);

	QTime time(0, 0);
	return time.addSecs(sessionTime).toString("hh ч mm мин ss сек");
}

QString DataManager::getDeviceTotalTime() const
{
	int totalTime;
	memcpy(&totalTime, &(_mcuOutData.totalTime1), 4);

	QTime time(0, 0);
	return time.addSecs(totalTime).toString("hh ч mm мин");
}

QString DataManager::getPcTotalTime()
{
	updatePcTotalRunningTime();
	QTime time(0, 0);
	return time.addSecs(_settings->value("OS_totalRunningTime").toUInt()).toString("hh ч mm мин ss сек");
}

void DataManager::updatePcTotalRunningTime()
{
	static unsigned prevSessionTotalRunningTime(_settings->value("OS_totalRunningTime").toUInt());
	unsigned elapsedTime = static_cast<unsigned>(_appStartedTime.secsTo(QDateTime::currentDateTime()));
	_settings->setValue("OS_totalRunningTime", prevSessionTotalRunningTime + elapsedTime);
}
