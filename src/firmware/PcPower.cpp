#include "PcPower.h"

#include <Arduino.h>
#include "TricolorLED.h"

void PcPower::on()
{
	getInstance().runSequence(new Signal[2]{ {HIGH, 300}, {LOW, 300} }, 2);
	TricolorLED::blink(GREEN);
}

void PcPower::off()
{
	if (analogRead(SYS_FAN) > 300)
	{
		getInstance().runSequence(new Signal[2]{ {HIGH, 300}, {LOW, 300} }, 2);
		TricolorLED::blink(RED);
	}
}

void PcPower::forcedOff()
{
	//if (analogRead(SYS_FAN) > 300)
	{
		getInstance().runSequence(new Signal[2]{ {HIGH, 5000}, {LOW, 300} }, 2);
		TricolorLED::blink(RED);
	}
}
