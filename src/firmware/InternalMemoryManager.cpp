#include "InternalMemoryManager.h"

#include <string.h>
#include <Arduino.h>

#include "DataManager.h"
#include "Beeper.h"
#include "Krakeenone_pinout.h"

InternalMemoryManager::InternalMemoryManager()
{

}

void InternalMemoryManager::initConfig()
{
    if (eeprom_read_byte(0) == 123 && digitalRead(PC_POWER_BUTTON))
    {
        eeprom_read_block((void*)(&DataManager::config()), 1, sizeof(McuInData));
    }
    else
    {
        eeprom_write_byte(0, 123);
        eeprom_write_block((void*)(0U), 96, sizeof(unsigned int));
        saveConfig();
    }
}

void InternalMemoryManager::saveConfig()
{
    Beeper::beep();
    eeprom_write_block((void*)(&DataManager::config()), 1, sizeof(McuInData));
}

unsigned InternalMemoryManager::lastTotalRunningTimeValue() const
{
    unsigned val;
    eeprom_read_block((void*)(&val), 96, sizeof(unsigned));
    return val;
}

void InternalMemoryManager::saveTotalRunningTimeValue(unsigned value) const
{
	eeprom_write_block((void*)(&value), 96, sizeof(unsigned));
}
