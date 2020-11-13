#include <GyverTimers.h>

#include "SerialPortManager.h"
#include "DataManager.h"
#include "InternalMemoryManager.h"
//#include "TemperatureSensors.h"
//#include "MoistureSensors.h"
//#include "DustSensors.h"
//#include "PositionVibrationSensors.h"
//#include "BreakInSensors.h"
#include "PowerButtonWatcher.h"
//#include "IButtonManager.h"

#include "Beeper.h"
#include "PcPower.h"
#include "TricolorLED.h"

#include "Krakeenone_pinout.h"

static SerialPortManager portManager;
static InternalMemoryManager internalMemoryManager;
//static TemperatureSensors temperatureSensors;
//static MoistureSensors moistureSensors;
//static DustSensors dustSensors;
//static PositionVibrationSensors positionVibrationSensors;
//static BreakInSensors breakInSensors;
//static IButtonManager iButtonManager;
static PowerButtonWatcher powerButtonWatcher;

static int loopsCounter = 0; // счетчик кол-ва вызовов функции loop()
const int LOOPS_COUNT = 100; // кол-во циклов, через которое мы снимаем показания с "тяжелых" датчиков.
const int TIMER_PERIOD = 20000; // в микросекундах
const int RUNNING_TIME_FIXING_PERIOD = 660; // С какой периодичностью обновляется запись о суммарном кол-ве отработаннного времени, в сек

void setup()
{
    portManager.init(19200);
    DataManager::init();
    Beeper::init(BEEPER, TIMER_PERIOD, 100);
    PcPower::init(PC_POWER, TIMER_PERIOD, 300);
    TricolorLED::init(RED, TIMER_PERIOD, 200);

    internalMemoryManager.initConfig();
    //iButtonManager.init(&internalMemoryManager);

    Timer2.setPeriod(TIMER_PERIOD); // Устанавливаем период таймера 20000 мкс -> 50 гц
    Timer2.enableISR(CHANNEL_A); // Или просто.enableISR(), запускаем прерывание на канале А таймера

    Serial.begin(19200);

    //temperatureSensors.init();
    //moistureSensors.init();
    //dustSensors.init();
    //positionVibrationSensors.init();
    powerButtonWatcher.updateConfig();

    DataManager::outData().totalRunningTime = internalMemoryManager.lastTotalRunningTimeValue();
}

void loop()
{
  // Сохраняем текущее время с последнего запуска устройства
    DataManager::outData().sessionRunningTime = millis() / 1000;

    static unsigned timeElapsed(0U);
    int currentElapsedTime = DataManager::outData().sessionRunningTime - timeElapsed;

    if (currentElapsedTime > RUNNING_TIME_FIXING_PERIOD)
    {
        timeElapsed = DataManager::outData().sessionRunningTime;
        internalMemoryManager.saveTotalRunningTimeValue(internalMemoryManager.lastTotalRunningTimeValue() + currentElapsedTime);
        DataManager::outData().totalRunningTime = internalMemoryManager.lastTotalRunningTimeValue();
    }

    if(loopsCounter > LOOPS_COUNT)
    {
      loopsCounter = 0;
      
      // Влажность
      //moistureSensors.update();

      // Температура
      //temperatureSensors.update();

      // Датчик пыли
      //dustSensors.update();

      // Датчики вскрытия
      //breakInSensors.update();

      //Пока датчики не работают, не забыть потом убрать!!!
      delay(500);
    }

    else
    {
        loopsCounter++;

        //positionVibrationSensors.update();


        portManager.update();

        if (portManager.mode() == SerialPortManager::Mode::normal && portManager.needToUpdateConfig())
        {
            DataManager::config() = *(portManager.inData());
			internalMemoryManager.saveConfig();
			powerButtonWatcher.updateConfig();
        }

        //iButtonManager.update();
    }
}

// Прерывание А таймера 5
ISR(TIMER2_A)
{
    Beeper::update();
    PcPower::update();
    TricolorLED::update();
    powerButtonWatcher.update(TIMER_PERIOD / 1000);
}
