#pragma once

#include <Arduino.h>

// �������� �����/������:

// ������� �����������
const int TEMP1 = 25;
const int TEMP2 = 26;
const int TEMP3 = 27;

const int DHT_PIN = 28; // DHT (���������)
const int IBUTTON = 29;
const int DUST_LED_INT = 24; // ��������� ����������� ������� ����
const int BREAK_IN_SENSOR_INT = 22; // ���������� ������ ��������

// �������� �����������
const int TERMINAL_SWITCH1 = 30;
const int TERMINAL_SWITCH2 = 31;
const int TERMINAL_SWITCH3 = 32;

const int PC_POWER = 33;
const int PC_RESET = 34;

const int SYS_FAN = 35;

const int DEFAULT_PIN = 36;

const int PC_POWER_BUTTON = 2;
const int PC_RESET_BUTTON = 3;

const int DUST_LED_SHARP = 39; // ��������� ��������� ������� ����
const int BEEPER = 38;

const int HDD = 41;

// ���������� �����/������:

// ������ ���������
const int Z_POS = A0;
const int Y_POS = A1;
const int X_POS = A2;

const int DUST_RES_INT = A3; // �������� ���������� ������� ����
const int DUST_RES_SHARP = A5; // �������� ��������� ������� ����

const int USELESS_ANALOG = A4;

// ������� ��������
const int VIBRO1 = A6;
const int VIBRO2 = A7;
const int VIBRO3 = A8;

// ���
const int RED = 13;
const int GREEN = 12;
const int BLUE = 11;