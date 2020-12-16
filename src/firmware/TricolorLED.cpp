#include "TricolorLED.h"

#include <Arduino.h>

#include "DataManager.h"
#include "Krakeenone_pinout.h"

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
	getInstance()._cyclesCount = getInstance()._duration / (getInstance()._timerPeriod);

	pinMode(getInstance()._pin, OUTPUT);
	digitalWrite(getInstance()._pin, HIGH);

	getInstance()._pin = BLUE;
	pinMode(getInstance()._pin, OUTPUT);
	digitalWrite(getInstance()._pin, HIGH);

	getInstance()._pin = GREEN;
	pinMode(getInstance()._pin, OUTPUT);
	digitalWrite(getInstance()._pin, HIGH);

	getInstance()._pin = RED;
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
			digitalWrite(getInstance()._pin, HIGH);
		}
	}
}

void TricolorLED::blink(int color)
{
	if ( !(DataManager::config().ledOn) )
		return;

	if (!getInstance()._isOn)
	{
		getInstance()._pin = color;
		getInstance().getInstance()._cyclesCounter = 0;
		getInstance()._isOn = true;
		digitalWrite(getInstance()._pin, LOW);
	}
}