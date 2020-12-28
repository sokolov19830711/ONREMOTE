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

		if (getInstance().isValueChanged() && getInstance().getCurrentValue() != getInstance().getIdleValue()) // ������ ������ � ���������
		{
			getInstance()._counter++;
		}

		if (getInstance()._timer > DataManager::config().digitInputPeriod * 1000)
		{
			getInstance()._timer = 0;

			int currentDigitValue;
			switch (getInstance()._currentDigit)
			{
			case 1:
				currentDigitValue = DataManager::config().powerButtonPwdDigit1;
				break;
			case 2:
				currentDigitValue = DataManager::config().powerButtonPwdDigit2;
				break;
			case 3:
				currentDigitValue = DataManager::config().powerButtonPwdDigit3;
				break;
			}

			if (getInstance()._counter == currentDigitValue)
			{
				if (getInstance()._currentDigit == DataManager::config().powerButtonPwdLevel) // ��������� ��������� ������
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

			else // �� �������
			{
				getInstance()._isWatching = false;
			}
		}
	}

	else
	{
		if (getInstance().isValueChanged() && getInstance().getCurrentValue() != getInstance().getIdleValue()) // ������ ������ � ���������
		{
			if (DataManager::config().powerButtonPwdLevel && (DataManager::config().turnOn))
			{
				getInstance()._isWatching = true;
				getInstance()._counter = 1;
				getInstance()._timer = 0;
				getInstance()._currentDigit = 1;
			}

			else // ������ �� ������ ������� ��������
			{
				PcPower::on();
			}
		}
	}

	if (getInstance().currentValueTimer() > 5000 && getInstance().getCurrentValue() != getInstance().getIdleValue())
	{
		getInstance().resetCurrentValueTimer();
		PcPower::forcedOff();
	}

	getInstance().resetValueChanged();
}

PowerButton& PowerButton::getInstance()
{
	static PowerButton instance;
	return instance;
}
