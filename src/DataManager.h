#pragma once

#include "firmware/dataStructures.h"

#include <QObject>
#include <QSettings>
#include <QSharedPointer>
#include <QDateTime>

class DataManager : public QObject
{
	Q_OBJECT

public:

	enum LicenseType {full, button_only, dust_only};
	DataManager();
	virtual ~DataManager();

	McuInData& inData();
	McuOutData& outData();
    QSharedPointer<QSettings>& settings();

	void writeMcuOutData(const QByteArray& data);

	Q_INVOKABLE void setSettingsValue(const QString& valueName, unsigned char value);
	Q_INVOKABLE void setSettingsStringValue(const QString& valueName, const QString& value);
	Q_INVOKABLE unsigned char getSettingsValue(const QString& valueName) const;
	Q_INVOKABLE QString getSettingsStringValue(const QString& valueName) const;
	Q_INVOKABLE unsigned char getMcuValue(const QString& valueName) const;
	Q_INVOKABLE void resetToDefault();

	Q_INVOKABLE void sendCommand(const QString& commandName);
	void clearCommands();

	Q_INVOKABLE QString getDeviceSessionTime() const;
	Q_INVOKABLE QString getDeviceTotalTime() const;
	Q_INVOKABLE QString getPcTotalTime();

    unsigned int getDeviceTotalTimeSec() const;
    unsigned int getPcTotalTimeSec();
    unsigned int getDeviceSessionTimeSec() const;

public slots:

	void updatePcTotalRunningTime();

private:

	QDateTime _appStartedTime;
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
		{"dustFlag_notification", nullptr},

		{"temperatureFlag_pcShutdown", &_mcuInData.temperatureFlag_pcShutdown},
		{"temperatureFlag_notification", nullptr},
		{"temperatureMinValue", &_mcuInData.temperatureMinValue},
		{"temperatureMaxValue", &_mcuInData.temperatureMaxValue},

		{"breakInFlag_pcShutdown1", &_mcuInData.breakInFlag_pcShutdown1},
		{"breakInFlag_notification1", nullptr},
		{"breakInSensorNormalState1", &_mcuInData.breakInSensorNormalState1},

		{"breakInFlag_pcShutdown2", &_mcuInData.breakInFlag_pcShutdown2},
		{"breakInFlag_notification2", nullptr},
		{"breakInSensorNormalState2", &_mcuInData.breakInSensorNormalState2},

		{"PWR/powerButtonPwdLevel", &_mcuInData.powerButtonPwdLevel},
		{"PWR/digit1", &_mcuInData.powerButtonPwdDigit1},
		{"PWR/digit2", &_mcuInData.powerButtonPwdDigit2},
		{"PWR/digit3", &_mcuInData.powerButtonPwdDigit3},
		{"PWR/digitInputPeriod", &_mcuInData.digitInputPeriod},
		{"PWR/attempts", &_mcuInData.attempts},
		{"PWR/attemptsResetTime", &_mcuInData.attemptsResetTime},

		{"appLocked", nullptr},
		{"startOnBoot", nullptr},
		{"lockOS", nullptr},
		{"lockApp", nullptr},
		{"SerialPort/name", nullptr},

		{"SMTP/server", nullptr},
		{"SMTP/port", nullptr},
		{"SMTP/user", nullptr},
		{"SMTP/password", nullptr},
		{"SMTP/recipient", nullptr},
		{"SMTP/deviceName", nullptr},
		{"SMTP/ssl", nullptr},

		{"OS_totalRunningTime", nullptr},

		{"totalHwHoursNotification", nullptr},
		{"totalHwMinutesNotification", nullptr},
		{"totalHwSecondsNotification", nullptr},

		{"sessionHwHoursNotification", nullptr},
		{"sessionHwMinutesNotification", nullptr},
		{"sessionHwSecondsNotification", nullptr},

		{"totalSwHoursNotification", nullptr},
		{"totalSwMinutesNotification", nullptr},
		{"totalSwSecondsNotification", nullptr},

		{"license/activated", nullptr},
		{"license/type", nullptr}
	};

	QMap<QString, unsigned char*> _mcuValuesMap
	{
		{"dustSensor", &_mcuOutData.dustSensor},
		{"temperatureSensor", &_mcuOutData.temperatureSensor},
		{"breakInSensor1", &_mcuOutData.breakInSensor1},
		{"breakInSensor2", &_mcuOutData.breakInSensor2},
	};

	QMap<QString, unsigned char*> _commandsMap
	{
		{"shutdownPc", &_mcuInData.shutdownPc},
		{"resetPc", &_mcuInData.resetPc}
	};
};
