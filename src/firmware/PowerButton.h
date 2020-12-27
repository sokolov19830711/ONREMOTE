#pragma once

#include "PinSingletonInterface.h"
#include "Pinout.h"

class PowerButton : public PinSingletonInterface<PC_POWER_BUTTON, HIGH>
{
public:

	static void process(int dt);
	static void updateConfig();

private:

	PowerButton() {}
	static PowerButton& getInstance();

	int _pwdLevel = 0;
	int _digitInputPeriod = 3000;
	int _digit[3];

	int _timer = 0;
	int _counter = 0;
	int _currentDigit;
	bool _isWatching = false;
};