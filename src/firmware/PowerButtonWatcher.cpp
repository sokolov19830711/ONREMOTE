#include "PowerButtonWatcher.h"
#include <Arduino.h>
#include "Krakeenone_pinout.h"
#include "DataManager.h"
#include "TricolorLED.h"
#include "PcPower.h"

PowerButtonWatcher::PowerButtonWatcher()
{
}

void PowerButtonWatcher::update(int dt)
{
	if (!DataManager::config().isPWRavaliable)
		return;

	bool currentButtonState = digitalRead(PC_POWER_BUTTON);
	if (_isWatching)
	{
		_timer += dt;

		if (_isPressed && !currentButtonState) // ������ ������ � ���������
		{
			_counter++;
		}

		if (_timer > _digitInputPeriod)
		{
			_timer = 0;

			if (_counter == _digit[_currentDigit - 1])
			{
				if (_currentDigit == _pwdLevel) // ��������� ��������� ������
				{
					PcPower::on();
					_isWatching = false;
				}

				else
				{
					_currentDigit++;
					_counter = 0;
					TricolorLED::blink(BLUE);
				}
			}

			else // �� �������
			{
				_isWatching = false;
			}
		}
	}

	else
	{
		if (_isPressed && !currentButtonState) // ������ ������ � ���������
		{
			if(_pwdLevel)
			{
				_isWatching = true;
				_counter = 1;
				_timer = 0;
				_currentDigit = 1;
			}

			else // ������ �� ������ ������� ��������
			{
				PcPower::on();
				TricolorLED::blink(GREEN);
			}
		}
	}

	_isPressed = currentButtonState;
}

void PowerButtonWatcher::updateConfig()
{
	_pwdLevel = DataManager::config().powerButtonPwdLevel;
	_digitInputPeriod = DataManager::config().digitInputPeriod * 1000;
	_digit[0] = DataManager::config().powerButtonPwdDigit1;
	_digit[1] = DataManager::config().powerButtonPwdDigit2;
	_digit[2] = DataManager::config().powerButtonPwdDigit3;
}
