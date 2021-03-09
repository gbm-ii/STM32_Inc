/*
 * F3 Discovery board defs (STM32F303VCT6)
 * gbm 02'16
 */
 
#include "stm32f3yy.h"

#define HSE_VALUE	8000000

#define LED_PORT	GPIOE	// LEDs on PE8..15
#define LEDR1_BIT	9	// clockwise, top
#define LEDO1_BIT	10
#define LEDG1_BIT	11
#define LEDB1_BIT	12
#define LEDR2_BIT	13
#define LEDO2_BIT	14
#define LEDG2_BIT	15
#define LEDB2_BIT	8
#define LEDR1_MSK	(1u << LEDR1_BIT)
#define LEDO1_MSK	(1u << LEDO1_BIT)
#define LEDG1_MSK	(1u << LEDG1_BIT)
#define LEDB1_MSK	(1u << LEDB1_BIT)
#define LEDR2_MSK	(1u << LEDR2_BIT)
#define LEDO2_MSK	(1u << LEDO2_BIT)
#define LEDG2_MSK	(1u << LEDG2_BIT)
#define LEDB2_MSK	(1u << LEDB2_BIT)

#define TIM_LED		TIM1
#define LEDR1_DUTY	TIM1->CCR1
#define LEDO2_DUTY	TIM1->CCR4
#define LEDG1_DUTY	TIM1->CCR2
#define LEDR2_DUTY	TIM1->CCR3
// other leds may be controlled via DMA, TIM4_CH1..3, TIM3_CH1 or 3

#define BTN_PORT	GPIOA
#define BTN_BIT	0

#define BTN_DOWN	(BTN_PORT->IDR >> BTN_BIT & 1)

// GPIOA USART2 pins
#define TX_BIT	2
#define RX_BIT	3
