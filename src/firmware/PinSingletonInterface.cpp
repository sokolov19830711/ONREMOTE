#include "PinSingletonInterface.h"

PinSingletonInterface::PinSingletonInterface() : Pin(0)
{

}

PinSingletonInterface& PinSingletonInterface::getInstance()
{
	static PinSingletonInterface instance;
	return instance;
}

void PinSingletonInterface::init(int pin, int idleValue, SignalType signalType, int pinMode)
{
	getInstance().setPin(pin);
	getInstance().setIdleValue(idleValue);
	getInstance().setSignalType(signalType);
	getInstance().setPinMode(pinMode);
}
