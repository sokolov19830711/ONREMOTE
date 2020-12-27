#include "PowerButton.h"
#include "PcPower.h"
#include "TricolorLED.h"
#include "Beeper.h"
#include "DataManager.h"

void PowerButton::process(int dt)
{
	if (getInstance()._isWatching)
	{
		getInstance()._timer += dt;

		if (getInstance().isValueChanged() && getInstance().getCurrentValue() != getInstance().getIdleValue()) // кнопку нажали и отпустили
		{
			getInstance()._counter++;
		}

		if (getInstance()._timer > getInstance()._digitInputPeriod)
		{
			getInstance()._timer = 0;

			if (getInstance()._counter == getInstance()._digit[getInstance()._currentDigit - 1])
			{
				if (getInstance()._currentDigit == getInstance()._pwdLevel) // Проверили последний разряд
				{
					PcPower::on();
					getInstance()._isWatching = false;
				}

				else
				{
					getInstance()._currentDigit++;
					getInstance()._counter = 0;
					TricolorLED::blink(BLUE);
				}
			}

			else // Не угадали
			{
				getInstance()._isWatching = false;
			}
		}
	}

	else
	{
		if (getInstance().isValueChanged() && getInstance().getCurrentValue() != getInstance().getIdleValue()) // кнопку нажали и отпустили
		{
			if (getInstance()._pwdLevel && (DataManager::config().turnOn))
			{
				getInstance()._isWatching = true;
				getInstance()._counter = 1;
				getInstance()._timer = 0;
				getInstance()._currentDigit = 1;
			}

			else // Пароль на кнопку питания отключен
			{
				PcPower::on();
			}
		}
	}

	/*if (getInstance().isValueChanged() && getInstance().getCurrentValue() != getInstance().getIdleValue())
	{
		Beeper::beep();
	}*/
	getInstance().resetValueChanged();
}

PowerButton& PowerButton::getInstance()
{
	static PowerButton instance;
	return instance;
}

void PowerButton::updateConfig()
{
	getInstance()._pwdLevel = DataManager::config().powerButtonPwdLevel;
	getInstance()._digitInputPeriod = DataManager::config().digitInputPeriod * 1000;
	getInstance()._digit[0] = DataManager::config().powerButtonPwdDigit1;
	getInstance()._digit[1] = DataManager::config().powerButtonPwdDigit2;
	getInstance()._digit[2] = DataManager::config().powerButtonPwdDigit3;
}
