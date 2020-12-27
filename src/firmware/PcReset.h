#pragma 

#include "Pinout.h"
#include "PinSingletonInterface.h"

class PcReset : public PinSingletonInterface<PC_RESET, LOW, Pin::SignalType::digital, OUTPUT>
{
public:

	static void on();

private:

	PcReset();
};

