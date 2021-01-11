#include "PortManager.h"
#include "dataStructures.h"
#include "Led.h"

#include <usbd_cdc_if.h>

uint8_t str_rx[128];
uint8_t recieved = 0;
uint8_t currentLength = 0;

PortManager::PortManager()
	: UpdatableOnTimer(500)
{
	
}

void PortManager::update()
{
	if (!isTimerExpired())
	{
		return;
	}
	
	McuOutData outData;
	CDC_Transmit_FS((uint8_t*)(&outData), sizeof(McuOutData));
	
	if (recieved && (currentLength == sizeof(McuInData)))
	{
		led.blink();
		recieved = 0;
	}
	
	resetTimer();
}