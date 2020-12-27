#pragma once

#include "PinSingletonInterface.h"
#include "Pinout.h"

class ResetButton : public PinSingletonInterface<PC_RESET_BUTTON, HIGH>
{
public:

	static void process();

private:

	ResetButton();
};