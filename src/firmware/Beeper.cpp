#include "Beeper.h"

#include <Arduino.h>

Beeper::Beeper() : Pin(0)
{
}

Beeper& Beeper::getInstance()
{
	static Beeper instance;
	return instance;
}

void Beeper::init(int pin)
{
	getInstance().setPin(pin);
	getInstance().setPinMode(OUTPUT);
	getInstance().setupSequence(new Signal[2]{
		{HIGH, 150},
		{LOW, 150}
		/*{HIGH, 150},
		{LOW, 150},
		{HIGH, 150},
		{LOW, 150},
		{HIGH, 500},
		{LOW, 150},
		{HIGH, 500},
		{LOW, 150},
		{HIGH, 500},
		{LOW, 150}*/
		}, 2);
}

void Beeper::beep()
{
	getInstance().runSequence();
}
