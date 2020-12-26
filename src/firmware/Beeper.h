#pragma once

#include "PinSingletonInterface.h"

class Beeper : public PinSingletonInterface
{
public:

	static void beep();

private:

	Beeper();
};

