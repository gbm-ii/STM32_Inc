/*
 * Nucleo-144 C5A3 board defs
 * gbm 10'26
 */
 
#ifndef NUCLEO144_H_
#define NUCLEO144_H_

#include "stm32c5yy.h"

#ifndef HSE_VALUE
#define HSE_VALUE	48000000u
#endif

// LD1 active HIGH (driven by transistor)
#define LEDG_PORT	GPIOA
#define LEDG_BIT	5
// LD2 active low
#define LEDR_PORT	GPIOG
#define LEDR_BIT	1
// LD3 active low
#define LEDB_PORT	GPIOG
#define LEDB_BIT	2

#define LEDG_MSK	(1u << LEDG_BIT)
#define LEDB_MSK	(1u << LEDB_BIT)
#define LEDR_MSK	(1u << LEDR_BIT)

#define LEDG_DUTY	TIM2->CCR1	// or TIM1->CCR3
#define LEDB_DUTY	TIM4->CCR2	// 
#define LEDR_DUTY	TIM4->CCR3	// 

#define LED_PORT	LEDG_PORT
#define LED_BIT	LEDG_BIT
#define LED_MSK	LEDG_MSK
#define LED_ACTIVE_LEVEL	1

// Blue User button active high
#define BTN_PORT	GPIOC
#define BTN_BIT	13
#define BTN_DOWN	(BTN_PORT->IDR >> BTN_BIT & 1)
#define BTN_PULL	GPIO_PUPDR_PD

// GPIOA USART2 pins - ST-Link VCP
#define STLINK_VCP_UART	USART2
#define STLINK_VCP_PORT GPIOA
#define STLINK_VCP_TX_BIT	2
#define STLINK_VCP_RX_BIT	3

// GPIOG USART2 pins - Arduino D0, D1
#define ATX_BIT	5
#define ARX_BIT	6

#endif
