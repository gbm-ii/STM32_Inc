/*
	STM32F NUCLEO64 board defs
	gbm 11'2015
*/
#ifndef STM32NUCLEO64_H_
#define STM32NUCLEO64_H_
//========================================================================
#define BTN_PORT	GPIOC
#define BTN_BIT		13

#define BTN_DOWN	((~BTN_PORT->IDR >> BTN_BIT & 1))

#define LED_PORT		GPIOA
#define LED_BIT	5
#define LED_MSK	(1u << LED_BIT)

#define LED_DUTY	TIM2->CCR1
//========================================================================
#endif
