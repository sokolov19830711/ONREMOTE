#include "Led.h"
#include "dataStructures.h"
#include <usbd_cdc_if.h>

extern uint8_t str_rx[32];
extern uint8_t recieved;
extern uint8_t currentLength;

extern "C"
void main_loop()
{
	
}

extern "C"
void update_on_timer()
{
	McuOutData outData;
	CDC_Transmit_FS((uint8_t*)(&outData), sizeof(McuOutData));
	if (recieved && (currentLength == sizeof(McuInData)))
	{
		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
		recieved = 0;
	}
}