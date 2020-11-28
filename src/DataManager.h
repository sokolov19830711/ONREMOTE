#pragma once

#include "firmware/dataStructures.h"

#include <QObject>
#include <QSettings>
#include <QSharedPointer>

class DataManager : public QObject
{
	Q_OBJECT

public:

	DataManager();
	virtual ~DataManager();

	McuInData& inData();
	McuOutData& outData();
	QSharedPointer<QSettings> settings();

	void writeMcuOutData(const QByteArray& data);

	Q_INVOKABLE void setSettingsValue(const QString& valueName, unsigned char value);
	Q_INVOKABLE unsigned char getSettingsValue(const QString& valueName) const;
	Q_INVOKABLE unsigned char getMcuValue(const QString& valueName) const;

private:

	QSharedPointer<QSettings> _settings;

	McuInData _mcuInData;
	McuOutData _mcuOutData;
	McuOutData _prevMcuOutData;

	// Тут мы храним имена переменных, используемых для настроек
	// Если настройка используется только на стороне ПК, указываем на нее nullptr
	QMap<QString, unsigned char*> _settingsMap
	{
		{"turnOn", &_mcuInData.turnOn},
		{"soundOn", &_mcuInData.soundOn},
		{"ledOn", &_mcuInData.ledOn},

		{"dustFlag_pcShutdown", &_mcuInData.dustFlag_pcShutdown},

		{"temperatureFlag_pcShutdown", &_mcuInData.temperatureFlag_pcShutdown},
		{"temperatureMinValue", &_mcuInData.temperatureMinValue},
		{"temperatureMaxValue", &_mcuInData.temperatureMaxValue},

		{"breakInFlag_pcShutdown1", &_mcuInData.breakInFlag_pcShutdown1},
		{"breakInSensorNormalState1", &_mcuInData.breakInSensorNormalState1},

		{"breakInFlag_pcShutdown2", &_mcuInData.breakInFlag_pcShutdown2},
		{"breakInSensorNormalState2", &_mcuInData.breakInSensorNormalState2},

		{"PWR/powerButtonPwdLevel", &_mcuInData.powerButtonPwdLevel},
		{"PWR/digit1", &_mcuInData.powerButtonPwdDigit1},
		{"PWR/digit2", &_mcuInData.powerButtonPwdDigit2},
		{"PWR/digit3", &_mcuInData.powerButtonPwdDigit3},
		{"PWR/digitInputPeriod", &_mcuInData.digitInputPeriod},

		{"SerialPort/name", nullptr}

	};

	QMap<QString, unsigned char*> _mcuValuesMap
	{
		{"dustSensor", &_mcuOutData.dustSensor},
		{"temperatureSensor", &_mcuOutData.temperatureSensor},
		{"breakInSensor1", &_mcuOutData.breakInSensor1},
		{"breakInSensor2", &_mcuOutData.breakInSensor2},
		{"totalDays", &_mcuOutData.totalDays},
		{"totalHours", &_mcuOutData.totalHours},
		{"totalMinutes", &_mcuOutData.totalMinutes},
		{"totalSeconds", &_mcuOutData.totalSeconds},
		{"sessionDays", &_mcuOutData.sessionDays},
		{"sessionHours", &_mcuOutData.sessionHours},
		{"sessionMinutes", &_mcuOutData.sessionMinutes},
		{"sessionSeconds", &_mcuOutData.sessionSeconds}
	};

};