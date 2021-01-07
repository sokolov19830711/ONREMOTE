#include "Led.h"
#include "dataStructures.h"
#include <usbd_cdc_if.h>

extern uint8_t str_rx[32];
extern uint8_t recieved;
extern uint8_t currentLength;

extern "C"
void main_loop()
{
	McuOutData outData;
	CDC_Transmit_FS((uint8_t*)(&outData), sizeof(McuOutData));
	HAL_Delay(500);
	if(recieved && (currentLength == sizeof(McuInData)))
	{
		Led::blink();
		recieved = 0;
	}
}