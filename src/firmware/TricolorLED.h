#pragma once

#include "Pin.h"
#include "Pinout.h"

//enum BlinkingState{beforePause, blinkingOn, afterPause};
class TricolorLED
{
public:

	//static void init();
	//static void update(int dt);
	static void blink(int color);

private:

	TricolorLED();
	static TricolorLED& getInstance();

	Pin _redPin;
	Pin _greenPin;
	Pin _bluePin;

	//int _currentPin;
	//int _timer = 0;
	//const int _blinkDuration = 300; // ������������ �������� � ������������
	//const int _pauseDuration = 200; // ������������ ����� ����� � ����� �������� � ������������
	//BlinkingState _blinkingState = beforePause;
	//bool _isBlinking = false;
};

