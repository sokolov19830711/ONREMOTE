#pragma once

#include <Arduino.h>

class Pin
{
public:

	enum SignalType {digital, analog};

	Pin(int pin, SignalType signalType = digital, int pinMode = INPUT);

	void update(int dt);
	static void updatePins(int dt);

	void process();

	int currentValueTimer() const;

protected:

	bool _valueChanged = false;

private:

	static Pin* _first;
	Pin* _next = nullptr;
	int _pin;
	SignalType _signalType = analog;
	int _pinMode = INPUT;
	int _currentValue;
	int _currentValueTimer; // время, в течение которого текущее значение не изменялось
};