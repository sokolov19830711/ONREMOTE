#pragma once

#include "PinSingletonInterface.h"

class Beeper : private PinSingletonInterface
{
public:

	static void init(int pin, int idleValue = LOW, SignalType signalType = digital, int pinMode = INPUT);
	static void beep();

private:

	Beeper();
//	static Beeper& getInstance();
};

