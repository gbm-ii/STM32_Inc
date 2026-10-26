/*
 * Nucleo-144 C5A3 board defs
 * gbm 10'26
 */
 
#include "stm32c5yy.h"

#ifndef HSE_VALUE
#define HSE_VALUE	48000000u
#endif

// all LEDs active HIGH (driven by transistors)
// LD1
#define LEDG_PORT	GPIOA
#define LEDG_BIT	5
// LD2
#define LEDR_PORT	GPIOG
#define LEDR_BIT	1
// LD3
#define LEDB_PORT	GPIOG
#define LEDB_BIT	2
// USB OTG power switch with status LED
//#define LEDU_PORT	GPIOG
//#define LEDU_BIT	6

#define LEDG_MSK	(1u << LEDG_BIT)
#define LEDB_MSK	(1u << LEDB_BIT)
#define LEDR_MSK	(1u << LEDR_BIT)
//#define LEDU_MSK	(1u << LEDU_BIT)

//#define LEDG_DUTY	TIM3->CCR2	// or TIM8->CCR2
//#define LEDB_DUTY	TIM17->CCR1	// CH1N
//#define LEDR_DUTY	TIM15->CCR1	// CH1

#define LED_PORT	LEDG_PORT
#define LED_BIT	LEDG_BIT
#define LED_MSK	LEDG_MSK
#define LED_ACTIVE_LEVEL	1

// active high
#define BTN_PORT	GPIOC
#define BTN_BIT	13

#define BTN_DOWN	(BTN_PORT->IDR >> BTN_BIT & 1)
#define BTN_PULL	GPIO_PUPDR_PD

// GPIOA USART2 pins - ST-Link VCP
#define VCP_UART	USART2
#define VCP_PORT GPIOA
#define TX_BIT	2
#define RX_BIT	3

// GPIOG USART2 pins - Arduino D0, D1
#define ATX_BIT	5
#define ARX_BIT	6
