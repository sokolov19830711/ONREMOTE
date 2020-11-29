#pragma once
class PcPower
{
public:

	static void init(int pin, int timerPeriod, int duration);
	static void update();
	static void on();
	static void off();

private:

	PcPower();
	static PcPower& getInstance();

	int _pin;
	int _timerPeriod; // период вызова таймера в микросекундах
	int _duration; // длительность подачи сигнала на питание в милисекундах
	int _cyclesCount;
	int _cyclesCounter = 0;
	bool _isOn = false;
};

