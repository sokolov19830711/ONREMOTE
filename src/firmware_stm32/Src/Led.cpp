#include "Led.h"
#include <stm32f1xx_hal.h>
#include <stm32_hal_legacy.h>

Led::Led() : UpdatableOnTimer(100)
{
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
}

void Led::blink()
{
	if(!_isBlinking)
	{
		_isBlinking = true;
		resetTimer();
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
	}
}


void Led::update()
{
	if (_isBlinking)
	{
		if (isTimerExpired())
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
			_isBlinking = false;
			resetTimer();
		}
	}
}
