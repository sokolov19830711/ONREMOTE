#include "Led.h"
#include "PortManager.h"
#include "UpdatableOnTimer.h"
#include "dataStructures.h"
#include <usbd_cdc_if.h>

Led led;
PortManager portManager;

extern "C"
void main_loop()
{
	led.update();
	portManager.update();
}

extern "C"
void update_on_timer(int dt)
{
	UpdatableOnTimer::updateAll(dt);
}