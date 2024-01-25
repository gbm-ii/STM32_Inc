/*
 * Nucleo-144 U575 board defs
 * gbm 01'24
 */
 
//#include "stm32u5yy.h"

#define HSE_VALUE	8000000u

// all LEDs active HIGH (driven by transistors)
// LD1
#define LEDG_PORT	GPIOC
#define LEDG_BIT	7
// LD2
#define LEDB_PORT	GPIOB
#define LEDB_BIT	7
// LD3
#define LEDR_PORT	GPIOG
#define LEDR_BIT	2
// USB OTG power switch with status LED
//#define LEDU_PORT	GPIOG
//#define LEDU_BIT	6

#define LEDG_MSK	(1u << LEDG_BIT)
#define LEDB_MSK	(1u << LEDB_BIT)
#define LEDR_MSK	(1u << LEDR_BIT)
//#define LEDU_MSK	(1u << LEDU_BIT)

#define LEDG_DUTY	TIM3->CCR2	// or TIM8->CCR2
#define LEDB_DUTY	TIM17->CCR1	// CH1N
//#define LEDR_DUTY	TIM15->CCR1	// CH1

#define BTN_PORT	GPIOC
#define BTN_BIT	13

#define BTN_DOWN	(BTN_PORT->IDR >> BTN_BIT & 1)

// GPIOA USART1 pins - ST-Link VCP
#define VCP_PORT GPIOA
#define TX_BIT	9
#define RX_BIT	10

// GPIOG LPUART1 pins - Arduino D0, D1
#define ATX_BIT	7
#define ARX_BIT	8
