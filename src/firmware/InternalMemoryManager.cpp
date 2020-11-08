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
    if (eeprom_read_byte(0) == 123 && digitalRead(DEFAULT_PIN))
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

bool InternalMemoryManager::checkIButtonKey(const byte* key)
{
    if (key[7] == 0xA7)
        return true;
    byte currAdminKey[8];
    byte currUserKey[8];

    eeprom_read_block((void*)(&currAdminKey), 100, 8);
    eeprom_read_block((void*)(&currUserKey), 108, 8);

    if (!memcmp(key, &currAdminKey, 8) || !memcmp(key, &currUserKey, 8))
    {
        return true;
    }

    return false;
}

void InternalMemoryManager::writeNewIButtonKey(const byte* key, bool isAdminKey)
{
    int address = isAdminKey ? 100 : 108;
    eeprom_write_block((void*)(key), address, 8);
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
	Beeper::beep();
}
