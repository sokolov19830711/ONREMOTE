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

	void writeMcuOutData(const QByteArray& data);

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