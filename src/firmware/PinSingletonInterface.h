#pragma once

#include "Pin.h"

template<int pin, int idleValue = LOW, Pin::SignalType signalType = Pin::SignalType::digital, int pinMode = INPUT>
class PinSingletonInterface : public Pin
{
//public:
//
//	static void init(int pin, int idleValue = LOW, SignalType signalType = digital, int pinMode = INPUT);

protected:

	static PinSingletonInterface& getInstance()
	{
		static PinSingletonInterface instance;
		return instance;
	}
	PinSingletonInterface() : Pin(pin, idleValue, signalType, pinMode) {}

private:

};

