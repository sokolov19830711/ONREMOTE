#include "IButtonManager.h"

#include "Krakeenone_pinout.h"
#include "Beeper.h"
#include "PcPower.h"
#include "TricolorLED.h"

IButtonManager::IButtonManager()
{

}

void IButtonManager::init(InternalMemoryManager* internalMemoryManager)
{
	_btn = OneWire(IBUTTON);
	_internalMemoryManager = internalMemoryManager;
}

bool IButtonManager::update()
{
	if (DataManager::config().writeNewAdminKey)
	{
		_isAdminKeyWriting = true;
		_newKeyInputTimer = 1;
	}

	if (DataManager::config().writeNewUserKey)
	{
		_isAdminKeyWriting = false;
		_newKeyInputTimer = 1;
	}

	if (!_btn.search(_addr))
	{
		_btn.reset_search();
		return false;
	}

	if(_keyInputTimer > 30)
	{
		_keyInputTimer = 0;

		if (_newKeyInputTimer && _newKeyInputTimer < 30) // Если таймер запущен и не истек
		{
			TricolorLED::blink(BLUE);
			_internalMemoryManager->writeNewIButtonKey(_addr, _isAdminKeyWriting);
		}

		else if (_newKeyInputTimer) // Если таймер запущен и истек, сбрасываем его
		{
			_newKeyInputTimer = 0;
		}

		else
		{
			if (_internalMemoryManager->checkIButtonKey(_addr))
			{
				PcPower::on();
			}

			else
			{
				TricolorLED::blink(RED);
			}
		}
	}

	_btn.reset();
	_keyInputTimer++;
	if (_newKeyInputTimer)
	{
		_newKeyInputTimer++;
	}

	return true;
}
