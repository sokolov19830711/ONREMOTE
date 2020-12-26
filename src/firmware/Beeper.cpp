#include "Beeper.h"

#include <Arduino.h>
#include "Pinout.h"

//Beeper::Beeper() : Pin(BEEPER, LOW, Pin::SignalType::digital, OUTPUT)
//{
//
//}
//
//Beeper& Beeper::getInstance()
//{
//	static Beeper instance;
//	return instance;
//}
//
void Beeper::init(int pin, int idleValue, SignalType signalType, int pinMode)
{
	PinSingletonInterface::init(pin, idleValue, signalType, pinMode);
	//getInstance().setupSequence(new Signal[2]{
	//	{HIGH, 150},
	//	{LOW, 150}
	//	/*{HIGH, 150},
	//	{LOW, 150},
	//	{HIGH, 150},
	//	{LOW, 150},
	//	{HIGH, 500},
	//	{LOW, 150},
	//	{HIGH, 500},
	//	{LOW, 150},
	//	{HIGH, 500},
	//	{LOW, 150}*/
	//	}, 2);
}

void Beeper::beep()
{
	getInstance().setupSequence(new Signal[2]{ {HIGH, 150}, {LOW, 150} }, 2);
	getInstance().runSequence();
}
