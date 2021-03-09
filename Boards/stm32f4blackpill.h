/*
	STM32F4xx BlackPill Board defs
	gbm 11'2019
*/
#ifndef STM32F4BP_H_
#define STM32F4BP_H_
#include "stm32f4yy.h"
// Button - v1.3 and above ===============================================
// active low, requires pullup
#define BTN_PORT	GPIOA
#define BTN_BIT		0
#define BTN_MSK	(1u << BTN_BIT)
#define BTN_DOWN	(~BTN_PORT->IDR >> BTN_BIT & 1)
// LED ===================================================================
#define LED_PORT	GPIOC
#define LED_BIT	13	// active LOW
#define LED_MSK	(1u << LED_BIT)
//#define LED_DUTY	TIM2->CCR2
#define LED_ON	(LED_PORT->BRR = LED_MSK)
#define LED_OFF	(LED_PORT->BSRR = LED_MSK)
// SPI Flash =============================================================
// PA4, 5, 6, 7 - NSS, SCK, MISO, MOSI
#define NSS_PORT	GPIOA
#define NSS_BIT	4
#define FLASH_SPI	SPI1
#define	FLASH_SPI_RX_DMACH DMA1_Channel2
#define	FLASH_SPI_TX_DMACH DMA1_Channel3
#define NSS_MSK	(1u << NSS_BIT)
// UARTS: 1 - PA9/PA10, 2 - PA2/PA3
//========================================================================
#endif
