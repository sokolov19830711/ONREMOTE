#pragma once
class PcPower
{
public:

	static void init(int pin, int timerPeriod, int duration);
	static void update();
	static void on();

private:

	PcPower();
	static PcPower& getInstance();

	int _pin;
	int _timerPeriod; // ������ ������ ������� � �������������
	int _duration; // ������������ ������ ������� �� ������� � ������������
	int _cyclesCount;
	int _cyclesCounter = 0;
	bool _isOn = false;
};

