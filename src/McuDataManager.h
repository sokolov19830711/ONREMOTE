#pragma once

#include "firmware/dataStructures.h"

#include <QObject>

class McuDataManager : public QObject
{
	Q_OBJECT

public:

	McuDataManager();

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

	McuInData _mcuInData;
	McuOutData _mcuOutData;
	McuOutData _prevMcuOutData;
};