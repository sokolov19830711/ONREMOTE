#pragma once

#include "PinSingletonInterface.h"
#include "Pinout.h"

class Beeper : public PinSingletonInterface<BEEPER, LOW, Pin::SignalType::digital, OUTPUT>
{
public:

	static void beep();

private:

	Beeper();
};

