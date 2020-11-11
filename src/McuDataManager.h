#pragma once

#include "firmware/dataStructures.h"

#include <QObject>
#include <QSettings>
#include <QSharedPointer>

class McuDataManager : public QObject
{
	Q_OBJECT

public:

	McuDataManager();
	virtual ~McuDataManager();

	McuInData& inData();
	McuOutData& outData();
	QSharedPointer<QSettings> settings();

	void writeMcuOutData(const QByteArray& data);

	Q_INVOKABLE int powerButtonPwdLevel() const;
	Q_INVOKABLE int digitInputPeriod() const;
	Q_INVOKABLE int powerButtonPwdDigit1() const;
	Q_INVOKABLE int powerButtonPwdDigit2() const;
	Q_INVOKABLE int powerButtonPwdDigit3() const;

public slots:

	void setPowerButtonPwdLevel(int value);
	void setDigitInputPeriod(int value);
	void setPowerButtonPwdDigit1(int value);
	void setPowerButtonPwdDigit2(int value);
	void setPowerButtonPwdDigit3(int value);

signals:

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