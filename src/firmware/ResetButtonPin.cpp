#include "ResetButtonPin.h"
#include "Pinout.h"
#include "PcReset.h"
#include "TricolorLED.h"
#include "Beeper.h"

ResetButtonPin::ResetButtonPin(int pin) : Pin(pin, HIGH)
{

}

void ResetButtonPin::process()
{
	if (_valueChanged && _currentValue != _idleValue)
	{
		PcReset::on();
		Beeper::beep();
	}

	if (currentValueTimer() > 3000 && _currentValue != _idleValue)
	{
		TricolorLED::blink(RED);
		_currentValueTimer = 0;
	}
	_valueChanged = false;
}
