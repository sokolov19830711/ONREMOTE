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

void PcPower::init(int pin, int timerPeriod, int duration)
{

	getInstance()._pin = pin;
	getInstance()._timerPeriod = timerPeriod;
	getInstance()._duration = duration;
	getInstance()._cyclesCount = getInstance()._duration / (getInstance()._timerPeriod / 1000);
	pinMode(getInstance()._pin, OUTPUT);
}


void PcPower::update()
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

void PcPower::on()
{
	if (!getInstance()._isOn)
	{
		getInstance().getInstance()._cyclesCounter = 0;
		getInstance()._isOn = true;
		digitalWrite(getInstance()._pin, HIGH);
		TricolorLED::blink(GREEN);
	}
}

void PcPower::off()
{
	if (!getInstance()._isOn && analogRead(SYS_FAN) < 300)
	{
		getInstance().getInstance()._cyclesCounter = 0;
		getInstance()._isOn = true;
		digitalWrite(getInstance()._pin, HIGH);
		TricolorLED::blink(RED);
	}
}
