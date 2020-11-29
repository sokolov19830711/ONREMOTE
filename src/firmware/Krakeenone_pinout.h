#pragma once

#include <Arduino.h>

// Цифровые вводы/выводы:

// Датчики температуры
const int TEMP1 = 7;
const int TEMP2 = 6;

const int BREAK_IN_SENSOR_INT = 5; // Встроенный датчик вскрытия

const int TERMINAL_SWITCH1 = 4;

const int PC_POWER = A3;
const int PC_RESET = A4;

const int DEFAULT_PIN = 3;

const int PC_POWER_BUTTON = 2;
const int PC_RESET_BUTTON = 3;

const int BEEPER = A2;

// Аналоговые вводы/выводы:

const int DUST_RES_INT = A1; // Приемник встроенного датчика пыли
const int SYS_FAN = A7;

// ШИМ
const int RED = 10;
const int GREEN = 9;
const int BLUE = 8;