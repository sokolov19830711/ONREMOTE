#include "ResetButtonWatcher.h"
#include <Arduino.h>
#include "Krakeenone_pinout.h"
#include "DataManager.h"
#include "TricolorLED.h"
#include "PcReset.h"

ResetButtonWatcher::ResetButtonWatcher()
{
}

void ResetButtonWatcher::update()
{
	bool currentButtonState = digitalRead(PC_RESET_BUTTON);


	if (_isPressed && !currentButtonState) // ������ ������ � ���������
	{
		PcReset::on();
	}

	_isPressed = currentButtonState;
}
