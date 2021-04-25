/*
 * Nucleo-144 L496 & L4R5 board defs
 * gbm 02'18..04'21
 */
 
#include "stm32l4yy.h"

#define HSE_VALUE	8000000u

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
// USB OTG power switch with status LED
#define LEDU_PORT	GPIOG
#define LEDU_BIT	6

#define LEDG_MSK	(1u << LEDG_BIT)
#define LEDB_MSK	(1u << LEDB_BIT)
#define LEDR_MSK	(1u << LEDR_BIT)
#define LEDU_MSK	(1u << LEDU_BIT)

#define LEDG_DUTY	TIM3->CCR2	// or TIM8->CCR2
#define LEDB_DUTY	TIM17->CCR1	// CH1N
#define LEDR_DUTY	TIM15->CCR1	// CH1

#define BTN_PORT	GPIOC
#define BTN_BIT	13

#define BTN_DOWN	(BTN_PORT->IDR >> BTN_BIT & 1)

// GPIOG LPUART1 pins
#define TX_BIT	7
#define RX_BIT	8
