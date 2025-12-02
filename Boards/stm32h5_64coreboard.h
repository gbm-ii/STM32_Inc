/*
	STM32H523xx BlackPill Board defs
	https://github.com/WeActStudio/WeActStudio.STM32H5_64Pin_CoreBoard
	gbm 11'2025
*/
#ifndef STM32H5CB_H_
#define STM32H5CB_H_
#include "stm32h5yy.h"

#define HSE_VALUE	8'000'000u
// Button ================================================================
// active high, requires pulldown
#define BTN_PORT	GPIOC
#define BTN_BIT		13
#define BTN_MSK	(1u << BTN_BIT)
#define BTN_DOWN	(BTN_PORT->IDR & 1u << BTN_BIT)
// LED ===================================================================
#define LED_PORT	GPIOB
#define LED_BIT	2	// active high
#define LED_MSK	(1u << LED_BIT)
//#define LED_DUTY	TIM2->CCR2
#define LED_ON	(LED_PORT->BSRR = LED_MSK)
#define LED_OFF	(LED_PORT->BRRR = LED_MSK)
// microSD ===============================================================
// PC8..12, PD2, det on PA8
#define USD_NDET_PORT	GPIOA
#define USD_NDET_BIT	8
#define FLASH_SPI	SPI1
#define USD_NDET_MSK	(1u << USD_NDET_BIT)
// UARTS: 1 - PA9/PA10 available at pgm connector, 2 - PA2/PA3
//========================================================================
#endif
