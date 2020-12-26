#include "Beeper.h"

void Beeper::beep()
{
	getInstance().setupSequence(new Signal[2]{ {HIGH, 150}, {LOW, 150} }, 2);
	getInstance().runSequence();
}
