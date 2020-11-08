#pragma once
class TricolorLED
{
public:

	static void init(int pin, int timerPeriod, int duration);
	static void update();
	static void blink(int color);

private:

	TricolorLED();
	static TricolorLED& getInstance();

	int _pin;
	int _timerPeriod; // ������ ������ ������� � �������������
	int _duration; // ������������ ��������� ������� � ������������
	int _cyclesCount;
	int _cyclesCounter = 0;
	bool _isOn = false;
};

