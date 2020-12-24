#include "TricolorLED.h"

#include <Arduino.h>

#include "DataManager.h"
#include "Pinout.h"

TricolorLED::TricolorLED() :
	_redPin(RED),
	_greenPin(GREEN),
	_bluePin(BLUE)
{
	_redPin.setPinMode(OUTPUT);
	_greenPin.setPinMode(OUTPUT);
	_bluePin.setPinMode(OUTPUT);
	_redPin.setIdleValue(HIGH);
	_greenPin.setIdleValue(HIGH);
	_bluePin.setIdleValue(HIGH);
}

TricolorLED& TricolorLED::getInstance()
{
	static TricolorLED instance;
	return instance;
}

//void TricolorLED::init()
//{
//	pinMode(RED, OUTPUT);
//	pinMode(BLUE, OUTPUT);
//	pinMode(GREEN, OUTPUT);
//	digitalWrite(RED, HIGH);
//	digitalWrite(BLUE, HIGH);
//	digitalWrite(GREEN, HIGH);
//}

//void TricolorLED::update(int dt)
//{
//	if (getInstance()._isBlinking)
//	{
//		getInstance()._timer += dt;
//
//		switch (getInstance()._blinkingState)
//		{
//		case beforePause:
//			if (getInstance()._timer > getInstance()._pauseDuration)
//			{
//				getInstance()._blinkingState = blinkingOn;
//				getInstance()._timer = 0;
//				digitalWrite(getInstance()._currentPin, LOW);
//			}
//			break;
//
//		case blinkingOn:
//			if (getInstance()._timer > getInstance()._blinkDuration)
//			{
//				getInstance()._blinkingState = afterPause;
//				getInstance()._timer = 0;
//				digitalWrite(getInstance()._currentPin, HIGH);
//			}
//			break;
//
//		case afterPause:
//			if (getInstance()._timer > getInstance()._pauseDuration)
//			{
//				getInstance()._timer = 0;
//				c_isBlinking = false;
//			}
//			break;
//		}
//	}
//}

void TricolorLED::blink(int color)
{
	if ( !(DataManager::config().ledOn) )
		return;

	switch (color)
	{
	case RED:
		getInstance()._redPin.setupSequence(new Pin::Signal[2]{ {LOW, 300}, {HIGH, 150} }, 2);
		getInstance()._redPin.runSequence();
		break;

	case GREEN:
		getInstance()._greenPin.setupSequence(new Pin::Signal[2]{ {LOW, 300}, {HIGH, 150} }, 2);
		getInstance()._greenPin.runSequence();
		break;

	case BLUE:
		getInstance()._bluePin.setupSequence(new Pin::Signal[2]{ {LOW, 300}, {HIGH, 150} }, 2);
		getInstance()._bluePin.runSequence();
		break;
	}
}