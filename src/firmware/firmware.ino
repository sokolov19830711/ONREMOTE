#include <GyverTimers.h>

#include "SerialPortManager.h"
#include "DataManager.h"
#include "InternalMemoryManager.h"
#include "TemperatureSensors.h"
#include "DustSensors.h"
#include "BreakInSensors.h"
#include "PowerButtonWatcher.h"

#include "Beeper.h"
#include "PcPower.h"
#include "TricolorLED.h"

#include "Krakeenone_pinout.h"

static SerialPortManager portManager;
static InternalMemoryManager internalMemoryManager;
static TemperatureSensors temperatureSensors;
static DustSensors dustSensors;
static BreakInSensors breakInSensors;
static PowerButtonWatcher powerButtonWatcher;

static int loopsCounter = 0; // счетчик кол-ва вызовов функции loop()
const int LOOPS_COUNT = 50; // кол-во циклов, через которое мы снимаем показания с "тяжелых" датчиков.
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

    Timer2.setPeriod(TIMER_PERIOD); // Устанавливаем период таймера 20000 мкс -> 50 гц
    Timer2.enableISR(CHANNEL_A); // Или просто.enableISR(), запускаем прерывание на канале А таймера

    Serial.begin(19200);

    temperatureSensors.init();
    dustSensors.init();
    powerButtonWatcher.updateConfig();
}

void loop()
{
    unsigned long sessionRunningTime = millis() / 1000;
  // Сохраняем текущее время с последнего запуска устройства
    memcpy(&DataManager::outData().sessionTime1, &sessionRunningTime, 4);

    static unsigned timeElapsed(0U);
    int currentElapsedTime = sessionRunningTime - timeElapsed;

    if (currentElapsedTime > RUNNING_TIME_FIXING_PERIOD)
    {
        timeElapsed = sessionRunningTime;
        internalMemoryManager.saveTotalRunningTimeValue(internalMemoryManager.lastTotalRunningTimeValue() + currentElapsedTime);
        unsigned long totalRunningTime = internalMemoryManager.lastTotalRunningTimeValue();
        memcpy(&DataManager::outData().totalTime1, &totalRunningTime, 4);
    }

    if(loopsCounter > LOOPS_COUNT)
    {
      loopsCounter = 0;
      
      // Температура
      temperatureSensors.update();

      // Датчик пыли
      dustSensors.update();

      // Датчики вскрытия
      breakInSensors.update();

      portManager.update();

      if (portManager.mode() == SerialPortManager::Mode::normal && portManager.needToUpdateConfig())
      {
          DataManager::config() = *(portManager.inData());
          internalMemoryManager.saveConfig();
          powerButtonWatcher.updateConfig();
      }
    }

    else
    {
        loopsCounter++;
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
