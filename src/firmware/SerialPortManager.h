#pragma once

#include "dataStructures.h"

class SerialPortManager
{
public:

	enum Mode {normal, timeSet};

	SerialPortManager();
	void init(int baudRate);
	void update();

	bool needToUpdateConfig() const;
	Mode mode() const;
	const McuInData* inData() const;

private:

	Mode _mode = normal;
	bool _needToUpdateSettings = false;
	McuInData _inData;
};

