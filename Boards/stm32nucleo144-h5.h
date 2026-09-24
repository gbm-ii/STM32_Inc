/*
 * Nucleo-144 H5xx board defs
 * gbm 09'26
 */

#ifndef NUCLEO144_H
#define NUCLEO144_H
//#include "stm32h5yy.h"

#ifdef STM32H5E5xx
// Nucleo-H5E5ZI
#define HSE_VALUE	48000000u
// all LEDs active HIGH
// LD1 (driven by transistor)
#define LEDG_PORT	GPIOA
#define LEDG_BIT	3
// LD2
#define LEDR_PORT	GPIOF
#define LEDR_BIT	0
// LD3
#define LEDB_PORT	GPIOE
#define LEDB_BIT	5
#define LEDB_MSK	(1u << LEDB_BIT)
#else
// Nucleo-H563Z
#define HSE_VALUE	25000000u

// all LEDs active HIGH (driven by transistors)
// LD1
#define LEDG_PORT	GPIOB
#define LEDG_BIT	0
// LD2
#define LEDY_PORT	GPIOF
#define LEDY_BIT	4
#define LEDY_MSK	(1u << LEDY_BIT)
// LD3
#define LEDR_PORT	GPIOG
#define LEDR_BIT	4
// USB OTG power switch with status LED
//#define LEDU_PORT	GPIOG
//#define LEDU_BIT	6
// GPIOB LPUART1 pins - Arduino D0, D1
#define ATX_BIT	6
#define ARX_BIT	7

#endif

#define LEDG_MSK	(1u << LEDG_BIT)
#define LEDR_MSK	(1u << LEDR_BIT)
//#define LEDU_MSK	(1u << LEDU_BIT)

//#define LEDG_DUTY	TIM3->CCR2	// or TIM8->CCR2
//#define LEDB_DUTY	TIM17->CCR1	// CH1N
//#define LEDR_DUTY	TIM15->CCR1	// CH1

// Blue User button
#define BTN_PORT	GPIOC
#define BTN_BIT	13
#define BTN_DOWN	(BTN_PORT->IDR >> BTN_BIT & 1)

// GPIOD USART1 pins - ST-Link VCP
#define VCP_PORT GPIOD
#define TX_BIT	8
#define RX_BIT	9
#define VCP_UART	USART3

#endif // NUCLEO144_H
