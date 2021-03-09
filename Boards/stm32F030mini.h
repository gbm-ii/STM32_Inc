/*
	STM32F030F4P6 chinese board
	gbm 04'2016
*/
#include "stm32f0yy.h"
//========================================================================
#define LED_PORT		GPIOA
#define LED_BIT	4
#define LED_MSK	(1u << LED_BIT)

#define LED_DUTY	TIM14->CCR1
//========================================================================

