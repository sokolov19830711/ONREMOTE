#pragma once

#include <Arduino.h>

// Цифровые вводы/выводы:

// Датчики температуры
const int TEMP1 = 25;
const int TEMP2 = 26;
const int TEMP3 = 27;
//
//const int DHT_PIN = 28; // DHT (влажность)
//const int IBUTTON = 29;
const int DUST_LED_INT = 24; // Светодиод встроенного датчика пыли
const int BREAK_IN_SENSOR_INT = 22; // Встроенный датчик вскрытия

// Концевые выключатели
const int TERMINAL_SWITCH1 = 30;
const int TERMINAL_SWITCH2 = 31;
//const int TERMINAL_SWITCH3 = 32;
//
const int PC_POWER = A3;
//const int PC_RESET = 34;
//
//const int SYS_FAN = 35;
//
const int DEFAULT_PIN = 3;

const int PC_POWER_BUTTON = 2;
//const int PC_RESET_BUTTON = 3;

//const int DUST_LED_SHARP = 39; // Светодиод выносного датчика пыли
const int BEEPER = A2;

//const int HDD = 41;

// Аналоговые вводы/выводы:

// Датчик положения
//const int Z_POS = A0;
//const int Y_POS = A1;
//const int X_POS = A2;
//
//const int DUST_RES_INT = A3; // Приемник втроенного датчика пыли
//const int DUST_RES_SHARP = A5; // Приемник выносного датчика пыли
//
//const int USELESS_ANALOG = A4;

// Датчики вибрации
//const int VIBRO1 = A6;
//const int VIBRO2 = A7;
//const int VIBRO3 = A8;

// ШИМ
const int RED = 10;
const int GREEN = 9;
const int BLUE = 8;