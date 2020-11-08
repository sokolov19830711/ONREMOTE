#pragma once

#include <Arduino.h>
#include <avr/eeprom.h>
#include "dataStructures.h"

class InternalMemoryManager
{
public:
	InternalMemoryManager();
	void initConfig();
	void saveConfig();
	bool checkIButtonKey(const byte* key);
	void writeNewIButtonKey(const byte* key, bool isAdminKey = false);
	
	unsigned lastTotalRunningTimeValue() const;
	void saveTotalRunningTimeValue(unsigned value) const;
};

