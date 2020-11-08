#pragma once

#include <OneWire.h>

#include "DataManager.h"
#include "InternalMemoryManager.h"

class IButtonManager
{
public:
	IButtonManager();
	void init(InternalMemoryManager* internalMemoryManager);
	bool update();

private:

	bool _isAdminKeyWriting = false;
	InternalMemoryManager* _internalMemoryManager;
	int _keyInputTimer;
	int _newKeyInputTimer = 0;
	OneWire _btn;
	byte _addr[8];
};

