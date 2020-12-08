#pragma once

#include "dataStructures.h"

class SerialPortManager
{
public:

	enum Mode {normal, timeSet};

	SerialPortManager();
	void init(int baudRate);
	void update(int dt);

	bool needToUpdateConfig() const;
	void setConfigUpdated();
	Mode mode() const;
	const McuInData* inData() const;

private:

	const int _updateInterval = 500;
	int _counter = 0;
	Mode _mode = normal;
	bool _needToUpdateSettings = false;
	McuInData _inData;
};

