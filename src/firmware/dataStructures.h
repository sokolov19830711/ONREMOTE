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

    unsigned char vibrationSensor1; // Значение с датчика вибрации 1
    unsigned char vibrationSensor2; // Значение с датчика вибрации 2
    unsigned char vibrationSensor3; // Значение с датчика вибрации 3
    unsigned char vibrationSensor4; // Значение с датчика вибрации 4
    
    unsigned char positionSensorX; // X координата датчика положения
    unsigned char positionSensorY; // Y координата датчика положения
    unsigned char positionSensorZ; // Z координата датчика положения
    
    unsigned char controlMarker = CONTROL_MARKER;
    unsigned char reserved1;
    unsigned char reserved2;
    unsigned char reserved3;

    unsigned char dustSensor1; // Данные с датчика запыленности 1
    unsigned char dustSensor2; // Данные с датчика запыленности 2
    unsigned char dustSensor3; // Данные с датчика запыленности 3
    
    unsigned char moistureSensor; // Значение влажности
   
    unsigned char temperatureSensor1; // Значение температуры с датчика 1
    unsigned char temperatureSensor2; // Значение температуры с датчика 2
    unsigned char temperatureSensor3; // Значение температуры с датчика 3
    
    unsigned char breakInSensor1; // Состояние датчика вскрытия 1
    unsigned char breakInSensor2; // Состояние датчика вскрытия 2
    unsigned char breakInSensor3; // Состояние датчика вскрытия 3
    
    unsigned char iButton; // Состояние IBUTTON

    unsigned long totalRunningTime; // Суммарное время работы устройства, в секундах (должно хватить на 136 лет)
    unsigned long sessionRunningTime = 0; // Время работы устройства за сессию, в секундах
    unsigned long OS_totalRunningTime; // Суммарное время работы ОС, в секундах
    unsigned long OS_sessionRunningTime; // Время работы ОС за сессию, в секундах
};  // Итого получаем 36 байт

enum FunctionsFlag {startOnBoot = 0x1, lockOS = 0x2, lockApp = 0x4, turnOn = 0x8, sound = 0x10, popupNotification = 0x20};
enum ActionsFlag {notification = 0x1, soundSignal = 0x2, PCShutDown = 0x4, active = 0x8};
enum IButtonFlag { iButtonActive = 0x1, reset = 0x2, shutDown = 0x4 };

struct McuInData
{
    unsigned char startMarker1 = START_MARKER1;
    unsigned char startMarker2 = START_MARKER2;

    unsigned char functionsFlags = 0;

    unsigned char vibrationFlags1 = 0;
    unsigned char vibrationFlags2 = 0;
    unsigned char vibrationFlags3 = 0;
    unsigned char vibrationFlags4 = 0;
    unsigned char vibrationMaxValue1 = 0;
    unsigned char vibrationMaxValue2 = 0;
    unsigned char vibrationMaxValue3 = 0;
    unsigned char vibrationMaxValue4 = 0;

    unsigned char positionFlags = 0;
	unsigned char positionXnormal = 0;
	unsigned char positionYnormal = 0;
	unsigned char positionZnormal = 0;
    unsigned char positionXdeviation = 0;
    unsigned char positionYdeviation = 0;
    unsigned char positionZdeviation = 0;

    unsigned char dustFlags1 = 0;
    unsigned char dustFlags2 = 0;
    unsigned char dustFlags3 = 0;
    unsigned char dustMaxValue1 = 0;
    unsigned char dustMaxValue2 = 0;
    unsigned char dustMaxValue3 = 0;

    unsigned char moistureFlags = 0;
    unsigned char moistureMaxValue = 0;
    unsigned char moistureMinValue = 0;

    unsigned char temperatureFlags1 = 0;
    unsigned char temperatureFlags2 = 0;
    unsigned char temperatureFlags3 = 0;
    unsigned char temperatureMaxValue1 = 10;
    unsigned char temperatureMaxValue2 = 0;
    unsigned char temperatureMaxValue3 = 0;
    unsigned char temperatureMinValue1 = 0;
    unsigned char temperatureMinValue2 = 0;
    unsigned char temperatureMinValue3 = 0;

    unsigned char breakInFlags1 = 0;
    unsigned char breakInFlags2 = 0;
    unsigned char breakInFlags3 = 0;
    unsigned char breakInSensorNormalState1 = 0;
    unsigned char breakInSensorNormalState2 = 0;
    unsigned char breakInSensorNormalState3 = 0;

    unsigned char powerButtonPwdLevel = 0;
    unsigned char digitInputPeriod = 3;
    unsigned char powerButtonPwdDigit1 = 1;
    unsigned char powerButtonPwdDigit2 = 2;
    unsigned char powerButtonPwdDigit3 = 3;

    unsigned char iButtonFlags = 0;
    unsigned char wrongKeyUsageForPowerOff = 1;
    unsigned char wrongKeyUsageForReset = 1;
    unsigned char writeNewAdminKey = 0;
    unsigned char writeNewUserKey = 0;

    unsigned char isPWRavaliable = 1;
    unsigned char isRSTavaliable = 1;
};

template<typename T>
inline void setBit(T& var, int flag, bool state = true)
{
    if(state) var |= static_cast<T>(flag);
    else var &= static_cast<T>(~flag);
}

inline int getMax(int buf[], int sizeBuf)
{
    int maximum = buf[0];
    for (char i = 1; i < sizeBuf; i++)
    {
        maximum = maximum > buf[i] ? maximum : buf[i];
    }
    return maximum;
}

#endif
