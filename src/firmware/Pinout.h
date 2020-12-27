#pragma once

#include <Arduino.h>

// Цифровые вводы/выводы:

// Датчики температуры
#define TEMP1 7
#define TEMP2 6

#define BREAK_IN_SENSOR_INT 5 // Встроенный датчик вскрытия

#define TERMINAL_SWITCH1 4

#define PC_POWER 17
#define PC_RESET 18

#define PC_POWER_BUTTON 2
#define PC_RESET_BUTTON 3

#define BEEPER A2

// Аналоговые вводы/выводы:

#define DUST_RES_INT A1 // Приемник встроенного датчика пыли
#define SYS_FAN A7

// Трехцветный светодиод
#define RED 10
#define GREEN 9
#define BLUE 8