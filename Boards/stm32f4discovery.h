/*
 * F401 Discovery board defs
 * gbm 09'14
 */
 
#include "stm32f4yy.h"

#define HSE_VALUE	8000000

#define LED_PORT	GPIOD
#define LEDG_BIT	12
#define LEDO_BIT	13
#define LEDR_BIT	14
#define LEDB_BIT	15
#define LEDG_MSK	(1u << LEDG_BIT)
#define LEDO_MSK	(1u << LEDO_BIT)
#define LEDR_MSK	(1u << LEDR_BIT)
#define LEDB_MSK	(1u << LEDB_BIT)
#define TIM_LED		TIM4
#define LEDG_DUTY	TIM4->CCR1
#define LEDO_DUTY	TIM4->CCR2
#define LEDR_DUTY	TIM4->CCR3
#define LEDB_DUTY	TIM4->CCR4

#define BTN_PORT	GPIOA
#define BTN_BIT	0

#define BTN_DOWN	(BTN_PORT->IDR >> BTN_BIT & 1)

// GPIOA USART2 pins
#define TX_BIT	2
#define RX_BIT	3

#define OTG_PWREN_PORT	GPIOC
#define OTG_PWREN_BIT	0
#define OTG_PWREN_MSK	(1u << OTG_PWREN_BIT)
