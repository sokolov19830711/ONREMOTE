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
	
	unsigned lastTotalRunningTimeValue() const;
	void saveTotalRunningTimeValue(unsigned value) const;
};

