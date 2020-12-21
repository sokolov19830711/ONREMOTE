#pragma once

#include <Arduino.h>

class Pin
{
public:

	struct Signal
	{
		int value;
		int duration;
	};

	enum SignalType {digital, analog};
	const int UNDEFINED_VALUE = -1; // значение пина при начальной инициализации устройства

	Pin(int pin, SignalType signalType = digital, int pinMode = INPUT);

	void update(int dt);
	static void updatePins(int dt);

	void process();

	int currentValueTimer() const;

protected:

	void runSequence(Signal* sequence, int sequenceSize, bool repeat = false);
	bool _valueChanged = false;
	int _currentValueTimer; // время, в течение которого текущее значение не изменялось

private:

	static Pin* _first;
	Pin* _next = nullptr;
	int _pin;
	SignalType _signalType = analog;
	int _pinMode = INPUT;
	int _currentValue = UNDEFINED_VALUE;
	Signal* _signalsSequence = nullptr;
	int _sequenceSize;
	int _sequenceStage;
	bool _isSequenceRepeated;
	int _sequenceStageTimer;
};