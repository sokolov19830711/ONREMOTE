#pragma once

#include "Pin.h"

class ResetButtonPin : public Pin
{
public:

	ResetButtonPin(int pin);

	void process();
};