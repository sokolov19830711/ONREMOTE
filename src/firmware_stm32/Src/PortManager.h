#pragma once
#include "UpdatableOnTimer.h"

class PortManager : public UpdatableOnTimer
{
public:
	
	PortManager();
	
	void update();
	
private:
	
	bool _isBlinking;
};

extern PortManager portManager;