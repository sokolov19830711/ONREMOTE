#pragma once

#include "Pinout.h"
#include "PinSingletonInterface.h"

class PcPower : public PinSingletonInterface<PC_POWER, LOW, Pin::SignalType::digital, OUTPUT>
{
public:

	static void on();
	static void off();
	static void forcedOff();

private:

	PcPower();
};

