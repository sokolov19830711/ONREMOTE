#pragma once
class Beeper
{
public:

	static void init(int pin, int timerPeriod, int duration);
	static void update();
	static void beep();

private:

	Beeper();
	static Beeper& getInstance();

	int _pin;
	int _timerPeriod; // ������ ������ ������� � �������������
	int _duration; // ������������ ��������� ������� � ������������
	int _cyclesCount;
	int _cyclesCounter = 0;
	bool _isOn = false;
};

