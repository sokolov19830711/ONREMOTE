#include "TricolorLED.h"

#include <Arduino.h>

#include "DataManager.h"
#include "Pinout.h"

TricolorLED::TricolorLED()
{
}

TricolorLED& TricolorLED::getInstance()
{
	static TricolorLED instance;
	return instance;
}

void TricolorLED::init()
{
	pinMode(RED, OUTPUT);
	pinMode(BLUE, OUTPUT);
	pinMode(GREEN, OUTPUT);
	digitalWrite(RED, HIGH);
	digitalWrite(BLUE, HIGH);
	digitalWrite(GREEN, HIGH);
}

void TricolorLED::update(int dt)
{
	if (getInstance()._isBlinking)
	{
		getInstance()._timer += dt;

		switch (getInstance()._blinkingState)
		{
		case beforePause:
			if (getInstance()._timer > getInstance()._pauseDuration)
			{
				getInstance()._blinkingState = blinkingOn;
				getInstance()._timer = 0;
				digitalWrite(getInstance()._currentPin, LOW);
			}
			break;

		case blinkingOn:
			if (getInstance()._timer > getInstance()._blinkDuration)
			{
				getInstance()._blinkingState = afterPause;
				getInstance()._timer = 0;
				digitalWrite(getInstance()._currentPin, HIGH);
			}
			break;

		case afterPause:
			if (getInstance()._timer > getInstance()._pauseDuration)
			{
				getInstance()._timer = 0;
				getInstance()._isBlinking = false;
			}
			break;
		}
	}
}

void TricolorLED::blink(int color)
{
	if ( !(DataManager::config().ledOn) )
		return;

	if (!getInstance()._isBlinking)
	{
		getInstance()._currentPin = color;
		getInstance()._timer = 0;
		getInstance()._isBlinking = true;
		getInstance()._blinkingState = beforePause;
		digitalWrite(RED, HIGH);
		digitalWrite(BLUE, HIGH);
		digitalWrite(GREEN, HIGH);
	}
}