#include "ResetButtonWatcher.h"
#include <Arduino.h>
#include "Pinout.h"
#include "DataManager.h"
#include "TricolorLED.h"
#include "PcReset.h"

ResetButtonWatcher::ResetButtonWatcher()
{
}

void ResetButtonWatcher::update()
{
	bool currentButtonState = digitalRead(PC_RESET_BUTTON);


	if (_isPressed && !currentButtonState) // кнопку нажали и отпустили
	{
		PcReset::on();
	}

	_isPressed = currentButtonState;
}
