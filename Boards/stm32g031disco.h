/*
	STM32G031J6 8-pin DISCOVERY board defs
	gbm 10'2019
*/
#ifndef STM32G031DISCO_H_
#define STM32G031DISCO_H_
#include "stm32g0yy.h"
//========================================================================
#define BTN_PORT	GPIOA	// PA0/1/2, PF2
#define BTN_BIT		0

#define BTN_DOWN	((~BTN_PORT->IDR >> BTN_BIT & 1))

#define LED_PORT		GPIOA
#define LED_BIT	12
#define LED_MSK	(1u << LED_BIT)

#define LED_DUTY	TIM1->CCR3	// requires PA10 remap
//========================================================================
#endif
