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

	Pin(int pin, int idleValue = LOW, SignalType signalType = digital, int pinMode = INPUT);
	~Pin();

	int getPin() const;
	void setPin(int pin);

	void setPinMode(int mode);
	void setIdleValue(int value);

	void update(int dt);
	static void updatePins(int dt);

	void process();

	int currentValue() const;
	int currentValueTimer() const;

	void setupSequence(Signal* sequence, int sequenceSize, bool repeat = false);
	void runSequence();

protected:

	int _currentValue = UNDEFINED_VALUE;
	int _idleValue = LOW;
	bool _valueChanged = false;
	int _currentValueTimer; // время, в течение которого текущее значение не изменялось

private:

	int read() const;
	void write(int value) const;

	static Pin* _first;
	Pin* _next = nullptr;
	int _pin;
	SignalType _signalType = digital;
	int _pinMode = INPUT;

	Signal* _signalsSequence = nullptr;
	int _sequenceSize;
	int _sequenceStage;
	bool _isSequenceRunning = false;
	bool _isSequenceRepeated = false;
	int _sequenceStageTimer;
};