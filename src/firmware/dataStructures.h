#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#define START_MARKER1 123
#define START_MARKER2 124
#define CONTROL_MARKER 111

// Данные от микроконтроллера к управляющей программе
struct  McuOutData
{
    unsigned char startMarker1 = START_MARKER1;
    unsigned char startMarker2 = START_MARKER2;
    

    unsigned char dustSensor; // Данные с датчика запыленности
    
    unsigned char temperatureSensor; // Значение температуры с датчика
    
    unsigned char breakInSensor1; // Состояние датчика вскрытия 1
    unsigned char breakInSensor2; // Состояние датчика вскрытия 2
    
    unsigned char controlMarker = CONTROL_MARKER;

    // Суммарное время работы устройства
    unsigned char totalTime1;
    unsigned char totalTime2;
    unsigned char totalTime3;
    unsigned char totalTime4;

    // Время работы устройства за сессию
	unsigned char sessionTime1;
	unsigned char sessionTime2;
	unsigned char sessionTime3;
	unsigned char sessionTime4;
};

struct McuInData
{
    unsigned char startMarker1 = START_MARKER1;
    unsigned char startMarker2 = START_MARKER2;

    unsigned char turnOn = 1;
    unsigned char soundOn = 1;
    unsigned char ledOn = 1;

    unsigned char dustFlag_pcShutdown = 0;

    unsigned char temperatureFlag_pcShutdown = 0;
    unsigned char temperatureMaxValue = 40;
    unsigned char temperatureMinValue = 10;

    unsigned char breakInFlag_pcShutdown1 = 0;
    unsigned char breakInFlag_pcShutdown2 = 0;
    unsigned char breakInSensorNormalState1 = 0;
    unsigned char breakInSensorNormalState2 = 0;

    unsigned char powerButtonPwdLevel = 0;
    unsigned char digitInputPeriod = 3;
    unsigned char powerButtonPwdDigit1 = 1;
    unsigned char powerButtonPwdDigit2 = 1;
    unsigned char powerButtonPwdDigit3 = 1;
    unsigned char attempts = 0;
    unsigned char attemptsResetTime = 1;

    unsigned char shutdownPc = 0;
    unsigned char resetPc = 0;
};

#endif
