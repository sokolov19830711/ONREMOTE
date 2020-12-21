#include "Pin.h"

Pin* Pin::_first = nullptr;

Pin::Pin(int pin, SignalType signalType, int pinMode) : 
	_pin(pin),
	_signalType(signalType),
	_pinMode(pinMode)
{
	if (!Pin::_first)
	{
		Pin::_first = this;
	}

	else
	{
		Pin* currentPin = Pin::_first;
		while (currentPin)
		{
			if (!currentPin->_next)
			{
				currentPin->_next = this;
				break;
			}

			currentPin++;
		}
	}

	// считываем начальное состояние пина
	switch (_signalType)
	{
	case Pin::digital:
		_currentValue = digitalRead(_pin);
		break;
	case Pin::analog:
		_currentValue = analogRead(_pin);
		break;
	}
}

void Pin::update(int dt)
{
	switch (_pinMode)
	{
	case INPUT:
		int currentValue;
		switch (_signalType)
		{
		case Pin::digital:
			currentValue = digitalRead(_pin);
			break;
		case Pin::analog:
			currentValue = analogRead(_pin);
			break;
		}

		if (_currentValue != currentValue) // значение на пине поменялось с прошлого измерения
		{
			_currentValue = currentValue;
			_currentValueTimer = 0;
			_valueChanged = true;
		}

		else
		{
			_currentValueTimer += dt;
		}

		break; // INPUT mode

	case OUTPUT:
		if (_signalsSequence)
		{

		}
		break; // OUTPUT mode
	}
}

void Pin::updatePins(int dt)
{
	Pin* currentPin = Pin::_first;
	while (currentPin)
	{
		currentPin->update(dt);
		if (currentPin->_next)
		{
			currentPin = currentPin->_next;
		}

		else
		{
			break;
		}
	}
}

void Pin::process()
{
	_valueChanged = false;
}

int Pin::currentValueTimer() const
{
	return _currentValueTimer;
}

void Pin::runSequence(Signal* sequence, int sequenceSize, bool repeat)
{
	if (_signalsSequence)
	{
		return;
	}

	_signalsSequence = sequence;
	_sequenceSize = sequenceSize;
	_sequenceStage = 0;
	_isSequenceRepeated = repeat;
	_sequenceStageTimer = 0;

	switch (_signalType)
	{
	case Pin::digital:
		digitalWrite(_pin, _signalsSequence->value);
		break;
	case Pin::analog:
		analogWrite(_pin, _signalsSequence->value);
		break;
	}
}
