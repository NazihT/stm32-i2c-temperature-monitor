#include "pwm.h"
#include "stm32f407xx.h"
#include "main.h"
#define PWM_MAX 65000
void setPWM(float* temp )
{
	if (*temp < 15 )
	{
		TIM3->CCR3 = 0; // duty cycle  0%
	}

	else if (*temp>=15 && *temp <20)
	{
		TIM3->CCR3=PWM_MAX*0.25; //duty cycle 25%
	}
	else if (*temp>=20 && *temp <25)
		{
			TIM3->CCR3=PWM_MAX*0.5; //duty cycle 50%
		}
	else if (*temp>=25 && *temp <30)
		{
			TIM3->CCR3=PWM_MAX*0.1; //duty cycle 75%
		}
	else TIM3->CCR3=PWM_MAX;  // roughly 100%
}


void setLEDS(float* temp)
{
	if (*temp < 15 )

	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, 1);            //BLUE ON  COLD
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, 0);            //GREEN OFF
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, 0);            //RED OFF
	}
	else if (*temp >= 15  && *temp < 30 )
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, 0);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, 1);             //GREEN ON , MODERATE
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, 0);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, 0);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, 0);             //RED ON , HOT
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, 1);
	}
}
