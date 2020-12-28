#include <GyverTimers.h>

#include "SerialPortManager.h"
#include "DataManager.h"
#include "InternalMemoryManager.h"
#include "TemperatureSensors.h"
#include "DustSensors.h"
#include "BreakInSensors.h"
#include "ResetButton.h"
#include "PowerButton.h"

#include "Beeper.h"
#include "PcPower.h"
#include "PcReset.h"
#include "TricolorLED.h"

#include "Pinout.h"

static SerialPortManager portManager;
static InternalMemoryManager internalMemoryManager;
static TemperatureSensors temperatureSensors;
static DustSensors dustSensors;
static BreakInSensors breakInSensors;

const int TIMER_PERIOD = 20; // в милисекундах
const int RUNNING_TIME_FIXING_PERIOD = 660; // С какой периодичностью обновляется запись о суммарном кол-ве отработаннного времени, в сек

void setup()
{
    portManager.init(19200);
    DataManager::init();
    internalMemoryManager.initConfig();

    Timer2.setPeriod(TIMER_PERIOD * 1000); // Устанавливаем период таймера в мкс
    Timer2.enableISR(CHANNEL_A); // запускаем прерывание на канале А таймера

    temperatureSensors.init();
    dustSensors.init();
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
      
      // Температура
      temperatureSensors.update();

      // Датчик пыли
      dustSensors.update();

      // Датчики вскрытия
      breakInSensors.update();

      ResetButton::process();

      if (portManager.mode() == SerialPortManager::Mode::normal && portManager.needToUpdateConfig())
      {
          DataManager::config() = *(portManager.inData());
          internalMemoryManager.saveConfig();
          portManager.setConfigUpdated();
      }
}

// Прерывание А таймера 2
ISR(TIMER2_A)
{
    Pin::updatePins(TIMER_PERIOD);
    portManager.update(TIMER_PERIOD);
    PowerButton::process(TIMER_PERIOD);
}
