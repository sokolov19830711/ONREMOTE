#pragma once
class PcReset
{
public:

	static void init(int pin);
	static void update(int dt);
	static void on();

private:

	PcReset();
	static PcReset& getInstance();

	int _pin;
	int _timer = 0;
	const int _duration = 300; // ������������ ������ ������� �� ������� � ������������

	bool _isOn = false;
};

