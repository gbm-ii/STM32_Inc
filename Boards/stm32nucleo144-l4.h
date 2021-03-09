/*
 * Nucleo-144 L496 & L4R5 board defs
 * gbm 02'18
 */
 
#include "stm32l4yy.h"

#define HSE_VALUE	8000000u

#define LED_PORT	GPIOE	// LEDs on PE8..15
#define LEDR1_BIT	9	// clockwise, top
#define LEDO1_BIT	10
// all LEDs active HIGH
// LD1
#define LEDG_PORT	GPIOC
#define LEDG_BIT	7
// LD2
#define LEDB_PORT	GPIOB
#define LEDB_BIT	7
// LD3
#define LEDR_PORT	GPIOB
#define LEDR_BIT	14

#define LEDG_MSK	(1u << LEDG1_BIT)
#define LEDB_MSK	(1u << LEDB1_BIT)
#define LEDR_MSK	(1u << LEDR1_BIT)

#define LEDG_DUTY	TIM3->CCR2	// or TIM8->CCR2
#define LEDB_DUTY	TIM17->CCR1	// CH1N
#define LEDR_DUTY	TIM15->CCR1	// CH1

#define BTN_PORT	GPIOC
#define BTN_BIT	13

#define BTN_DOWN	(BTN_PORT->IDR >> BTN_BIT & 1)

// GPIOA USART2 pins
#define TX_BIT	2
#define RX_BIT	3
