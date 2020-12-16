#include "Beeper.h"

#include <Arduino.h>

Beeper::Beeper()
{
}

Beeper& Beeper::getInstance()
{
	static Beeper instance;
	return instance;
}

void Beeper::init(int pin, int timerPeriod, int duration)
{
	
	getInstance()._pin = pin;
	getInstance()._timerPeriod = timerPeriod;
	getInstance()._duration = duration;
	getInstance()._cyclesCount = getInstance()._duration / (getInstance()._timerPeriod);
	pinMode(getInstance()._pin, OUTPUT);
}


void Beeper::update()
{
	if (getInstance()._isOn)
	{
		getInstance()._cyclesCounter++;
		if (getInstance()._cyclesCounter > getInstance()._cyclesCount)
		{
			getInstance()._cyclesCounter = 0;
			getInstance()._isOn = false;
			digitalWrite(getInstance()._pin, LOW);
		}
	}
}

void Beeper::beep()
{
	if (!getInstance()._isOn)
	{
		getInstance().getInstance()._cyclesCounter = 0;
		getInstance()._isOn = true;
		digitalWrite(getInstance()._pin, HIGH);
	}

}
