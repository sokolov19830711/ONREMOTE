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
    unsigned char totalDays;
    unsigned char totalHours;
    unsigned char totalMinutes;
    unsigned char totalSeconds;

    // Время работы устройства за сессию
	unsigned char sessionDays;
	unsigned char sessionHours;
	unsigned char sessionMinutes;
	unsigned char sessionSeconds;
};  // Итого получаем 15 байт

struct McuInData
{
    unsigned char startMarker1 = START_MARKER1;
    unsigned char startMarker2 = START_MARKER2;

    unsigned char turnOn = 1;
    unsigned char soundOn = 1;
    unsigned char ledOn = 1;

    unsigned char dustFlag_pcShutdown = 0;

    unsigned char temperatureFlag_pcShutdown = 0;
    unsigned char temperatureMaxValue = 10;
    unsigned char temperatureMinValue = 0;

    unsigned char breakInFlag_pcShutdown1 = 0;
    unsigned char breakInFlag_pcShutdown2 = 0;
    unsigned char breakInSensorNormalState1 = 0;
    unsigned char breakInSensorNormalState2 = 0;

    unsigned char powerButtonPwdLevel = 0;
    unsigned char digitInputPeriod = 3;
    unsigned char powerButtonPwdDigit1 = 1;
    unsigned char powerButtonPwdDigit2 = 2;
    unsigned char powerButtonPwdDigit3 = 3;
};

#endif
