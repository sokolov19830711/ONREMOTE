#include "PcReset.h"

#include <Arduino.h>
#include "Krakeenone_pinout.h"
#include "TricolorLED.h"

PcReset::PcReset()
{
}

PcReset& PcReset::getInstance()
{
	static PcReset instance;
	return instance;
}

void PcReset::init(int pin)
{
	getInstance()._pin = pin;
	pinMode(getInstance()._pin, OUTPUT);
}


void PcReset::update(int dt)
{
	if (getInstance()._isOn)
	{
		getInstance()._timer += dt;
		if (getInstance()._timer > getInstance()._duration)
		{
			getInstance()._timer = 0;
			getInstance()._isOn = false;
			digitalWrite(getInstance()._pin, LOW);
		}
	}
}

void PcReset::on()
{
	if (!getInstance()._isOn)
	{
		getInstance().getInstance()._timer = 0;
		getInstance()._isOn = true;
		digitalWrite(getInstance()._pin, HIGH);
		TricolorLED::blink(GREEN);
	}
}
