#pragma once

#include "Pin.h"

class Beeper : public Pin
{
public:

	static void init(int pin);
	static void beep();

private:

	Beeper();
	static Beeper& getInstance();
};

