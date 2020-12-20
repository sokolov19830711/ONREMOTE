#include "ResetButtonPin.h"
#include "Pinout.h"
#include "PcReset.h"

ResetButtonPin::ResetButtonPin(int pin) : Pin(pin)
{

}

void ResetButtonPin::process()
{
	if (_valueChanged)
	{
		PcReset::on();
	}
	_valueChanged = false;
}
