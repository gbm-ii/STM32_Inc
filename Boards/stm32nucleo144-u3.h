/*
 * Nucleo-144 U3C5 board defs
 * gbm 11'26
 */
 
#ifndef NUCLEO144_H_
#define NUCLEO144_H_

#include "stm32u3yy.h"

// No HSE!

// all LEDs active HIGH (driven by transistors)
// LD1
#define LEDG_PORT	GPIOA
#define LEDG_BIT	5
// LD2
#define LEDR_PORT	GPIOE
#define LEDR_BIT	14
// LD3
#define LEDB_PORT	GPIOF
#define LEDB_BIT	8

#define LEDG_MSK	(1u << LEDG_BIT)
#define LEDR_MSK	(1u << LEDR_BIT)
#define LEDB_MSK	(1u << LEDB_BIT)

#define LEDG_DUTY	TIM2->CCR1	//
#define LEDR_DUTY	TIM1->CCR4	// 

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
#define STLINK_VCP_UART	USART1
#define STLINK_VCP_PORT GPIOA
#define STLINK_VCP_TX_BIT	9
#define STLINK_VCP_RX_BIT	10

// GPIOD USART3 pins - Arduino D0, D1
#define ATX_BIT	8
#define ARX_BIT	9

#endif
