#include "PcReset.h"

#include "TricolorLED.h"

void PcReset::on()
{
	getInstance().runSequence(new Signal[2]{ {HIGH, 300}, {LOW, 300} }, 2);
	TricolorLED::blink(GREEN);
}
