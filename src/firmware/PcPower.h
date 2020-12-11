#pragma once
class PcPower
{
public:

	static void init(int pin);
	static void update(int dt);
	static void on();
	static void off();

private:

	PcPower();
	static PcPower& getInstance();

	int _pin;
	int _timer = 0;
	const int _duration = 300; // ������������ ������ ������� �� ������� � ������������

	int _offDelayTimer = 0; // ������ �������� ����� �������� ������� �� ����������
	const int _offDelayPeriod = 5000;
	bool _isOn = false;
};

