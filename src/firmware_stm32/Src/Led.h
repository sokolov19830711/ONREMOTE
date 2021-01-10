#pragma once
#include "UpdatableOnTimer.h"

class Led : public UpdatableOnTimer
{
public:
	
	Led();
	void blink();
	void update();
	
private:
	
	bool _isBlinking = false;
};

