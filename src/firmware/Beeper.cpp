#include "Beeper.h"

void Beeper::beep()
{
	getInstance().runSequence(new Signal[2]{ {HIGH, 150}, {LOW, 150} }, 2);
}
