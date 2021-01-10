#include "Led.h"
#include "UpdatableOnTimer.h"
#include "dataStructures.h"
#include <usbd_cdc_if.h>

extern uint8_t str_rx[32];
extern uint8_t recieved;
extern uint8_t currentLength;
Led led;

extern "C"
void main_loop()
{
	led.update();
}

extern "C"
void update_on_timer(int dt)
{
	UpdatableOnTimer::updateAll(dt);
	
	static int counter = 0;
	counter += dt;
	
	if (counter > 499)
	{
		counter = 0;
		McuOutData outData;
		CDC_Transmit_FS((uint8_t*)(&outData), sizeof(McuOutData));
		if (recieved && (currentLength == sizeof(McuInData)))
		{
			led.blink();
			recieved = 0;
		}
	}

}