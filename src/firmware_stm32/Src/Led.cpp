#include "Led.h"
#include <stm32f1xx_hal.h>
#include <stm32_hal_legacy.h>

void Led::blink()
{
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
	HAL_Delay(200);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
	HAL_Delay(200);
}
