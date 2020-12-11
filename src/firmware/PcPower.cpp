#include "PcPower.h"

#include <Arduino.h>
#include "Krakeenone_pinout.h"
#include "TricolorLED.h"

PcPower::PcPower()
{
}

PcPower& PcPower::getInstance()
{
	static PcPower instance;
	return instance;
}

void PcPower::init(int pin)
{
	getInstance()._pin = pin;
	pinMode(getInstance()._pin, OUTPUT);
}


void PcPower::update(int dt)
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

	if (getInstance()._offDelayTimer)
	{
		getInstance()._offDelayTimer += dt;
		if (getInstance()._offDelayTimer > getInstance()._offDelayPeriod)
		{
			getInstance()._offDelayTimer = 0;
		}
	}
}

void PcPower::on()
{
	if (!getInstance()._isOn)
	{
		getInstance().getInstance()._timer = 0;
		getInstance()._isOn = true;
		digitalWrite(getInstance()._pin, HIGH);
		TricolorLED::blink(GREEN);
	}
}

void PcPower::off()
{
	if (!getInstance()._isOn && !getInstance()._offDelayTimer /*&& analogRead(SYS_FAN) > 300*/)
	{
		getInstance().getInstance()._timer = 0;
		getInstance()._offDelayTimer = 1;
		getInstance()._isOn = true;
		digitalWrite(getInstance()._pin, HIGH);
		TricolorLED::blink(RED);
	}
}
