#include "UpdatableOnTimer.h"
#include "main.h"

UpdatableOnTimer* UpdatableOnTimer::_first = nullptr;

UpdatableOnTimer::UpdatableOnTimer(int period) :
	_period(period)
{
	if (!UpdatableOnTimer::_first)
	{
		UpdatableOnTimer::_first = this;
	}

	else
	{
		UpdatableOnTimer* currentUpdatable = UpdatableOnTimer::_first;
		while (currentUpdatable)
		{
			if (!currentUpdatable->_next)
			{
				currentUpdatable->_next = this;
				break;
			}

			currentUpdatable = currentUpdatable->_next;
		}
	}
}


void UpdatableOnTimer::updateOnTimer(int dt)
{
	_counter += dt;
	if (_counter > _period)
	{
		_counter = 0;
		_isTimerExpired = true;
	}
}


void UpdatableOnTimer::updateAll(int dt)
{
	UpdatableOnTimer* current = UpdatableOnTimer::_first;
	while (current)
	{
		current->updateOnTimer(dt);
		if (current->_next)
		{
			current = current->_next;
		}

		else
		{
			break;
		}
	}
}


void UpdatableOnTimer::resetTimer()
{
	_counter = 0;
	_isTimerExpired = false;
}


bool UpdatableOnTimer::isTimerExpired() const
{
	return _isTimerExpired;
}
