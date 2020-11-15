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

	Q_INVOKABLE bool isDeviceActive() const;
	Q_INVOKABLE bool isStartOnBoot() const;
	Q_INVOKABLE bool isLockOS() const;
	Q_INVOKABLE bool isLedActive() const;
	Q_INVOKABLE int powerButtonPwdLevel() const;
	Q_INVOKABLE int digitInputPeriod() const;
	Q_INVOKABLE int powerButtonPwdDigit1() const;
	Q_INVOKABLE int powerButtonPwdDigit2() const;
	Q_INVOKABLE int powerButtonPwdDigit3() const;

public slots:

	void setDeviceActive(bool state);
	void setLedActive(bool state);
	void setPowerButtonPwdLevel(int value);
	void setDigitInputPeriod(int value);
	void setPowerButtonPwdDigit1(int value);
	void setPowerButtonPwdDigit2(int value);
	void setPowerButtonPwdDigit3(int value);

signals:

	void deviceActiveChanged(bool state);
	void ledActiveChanged(bool state);
	void breakIn1ValueChanged(int value);
	void breakIn2ValueChanged(int value);
	void temperatureValueChanged(int value);
	void dustinessValueChanged(int value);

private:

	void update();

	QSharedPointer<QSettings> _settings;

	McuInData _mcuInData;
	McuOutData _mcuOutData;
	McuOutData _prevMcuOutData;
};