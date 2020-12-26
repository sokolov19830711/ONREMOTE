#include "Pin.h"
#include "Pinout.h"
#include "TricolorLED.h"

Pin* Pin::_first = nullptr;

Pin::Pin(int pin, int idleValue, SignalType signalType, int pinMode) :
	_pin(pin),
	_idleValue(idleValue),
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

			currentPin = currentPin->_next;
		}
	}

	setPinMode(pinMode);

	switch (_pinMode)
	{
	case INPUT:
		// считываем начальное состояние пина
		_currentValue = read();
		break;

	case OUTPUT:
		write(_idleValue);
		break;
	}
}

Pin::~Pin()
{
	delete[] _signalsSequence;
}

int Pin::getPin() const
{
	return _pin;
}

void Pin::setPin(int pin)
{
	_pin = pin;
}

void Pin::setSignalType(SignalType signalType)
{
	_signalType = signalType;
}

void Pin::setPinMode(int mode)
{
	_pinMode = mode;
	pinMode(_pin, mode);
}

void Pin::setIdleValue(int value)
{
	_idleValue = value;
	write(_idleValue);
}

void Pin::update(int dt)
{
	if(_pinMode == INPUT)
	{
		int currentValue = read();

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
	}

	else if (_pinMode == OUTPUT)
	{
		if (_isSequenceRunning)
		{
			_sequenceStageTimer += dt;
			if (_sequenceStageTimer > _signalsSequence->duration)
			{
				if (_sequenceStage < _sequenceSize) // переходим к следующему сигналу в последовательности
				{
					_signalsSequence++;
					_sequenceStage++;
					_sequenceStageTimer = 0;
					write(_signalsSequence->value);
				}

				else // дошли до конца последовательности
				{
					_signalsSequence -= _sequenceSize - 1;
					_sequenceStage = 1;
					_sequenceStageTimer = 0;

					if (!_isSequenceRepeated)
					{
						_isSequenceRunning = false;
						write(_idleValue);
					}

					else
					{
						write(_signalsSequence->value);
					}
				}
			}
		}
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

int Pin::currentValue() const
{
	return _currentValue;
}

int Pin::currentValueTimer() const
{
	return _currentValueTimer;
}

void Pin::setupSequence(Signal* sequence, int sequenceSize, bool repeat)
{
	delete[] _signalsSequence;
	_signalsSequence = sequence;
	_sequenceSize = sequenceSize;
	_isSequenceRepeated = repeat;
}

void Pin::runSequence()
{
	if (_isSequenceRunning)
	{
		return;
	}

	_sequenceStage = 1;
	_sequenceStageTimer = 0;
	_isSequenceRunning = true;

	write(_signalsSequence->value);
}

int Pin::read() const
{
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
	return currentValue;
}

void Pin::write(int value) const
{
	switch (_signalType)
	{
	case Pin::digital:
		digitalWrite(_pin, value);
		break;
	case Pin::analog:
		analogWrite(_pin, value);
		break;
	}
}
