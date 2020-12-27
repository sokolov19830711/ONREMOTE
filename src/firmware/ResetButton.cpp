#include "ResetButton.h"
#include "PcReset.h"
#include "TricolorLED.h"
#include "Beeper.h"

void ResetButton::process()
{
	if (getInstance().isValueChanged() && getInstance().getCurrentValue() != getInstance().getIdleValue())
	{
		PcReset::on();
	}

	getInstance().resetValueChanged();
}
