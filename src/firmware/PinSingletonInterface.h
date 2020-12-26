#pragma once

#include "Pin.h"

class PinSingletonInterface : public Pin
{
public:

	static void init(int pin, int idleValue = LOW, SignalType signalType = digital, int pinMode = INPUT);

protected:

	static PinSingletonInterface& getInstance();

private:

	PinSingletonInterface();
};

