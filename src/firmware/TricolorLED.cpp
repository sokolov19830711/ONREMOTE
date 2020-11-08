#include "TricolorLED.h"

#include <Arduino.h>

TricolorLED::TricolorLED()
{
}

TricolorLED& TricolorLED::getInstance()
{
	static TricolorLED instance;
	return instance;
}

void TricolorLED::init(int pin, int timerPeriod, int duration)
{

	getInstance()._pin = pin;
	getInstance()._timerPeriod = timerPeriod;
	getInstance()._duration = duration;
	getInstance()._cyclesCount = getInstance()._duration / (getInstance()._timerPeriod / 1000);
	pinMode(getInstance()._pin, OUTPUT);
}


void TricolorLED::update()
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

void TricolorLED::blink(int color)
{
	if (!getInstance()._isOn)
	{
		getInstance()._pin = color;
		getInstance().getInstance()._cyclesCounter = 0;
		getInstance()._isOn = true;
		digitalWrite(getInstance()._pin, HIGH);
	}

}