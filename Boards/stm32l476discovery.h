/*
 * L476 Discovery board defs
 * gbm 06'17
 */
 
#include "stm32l4yy.h"

#define HSE_VALUE	8000000

#define LEDR_PORT	GPIOB
#define LEDG_PORT	GPIOE
//#define LED_PORT	GPIOD
#define LEDG_BIT	8
#define LEDR_BIT	2
#define LEDG_MSK	(1u << LEDG_BIT)
#define LEDR_MSK	(1u << LEDR_BIT)
#define TIM_LED		TIM1
#define LEDG_DUTY	TIM_LED->CCR1	// CH1N out
#define LEDR_DUTY	TIM_LED->CCR2	// using DMA

// joystick - active high, direction buttons require pull-down
#define JOY_PORT	GPIOA
#define BTN_PORT	GPIOA
#define BTN_BIT	0
#define JOY_UP_BIT	3
#define JOY_RIGHT_BIT	2
#define JOY_LEFT_BIT	1
#define JOY_DOWN_BIT	5

#define BTN_DOWN	(BTN_PORT->IDR >> BTN_BIT & 1)
#define JOY_UP	(JOY_PORT->IDR >> JOY_ÙP_BIT & 1)
#define JOY_RIGHT	(JOY_PORT->IDR >> JOY_RIGHT_BIT & 1)
#define JOY_LEFT	(JOY_PORT->IDR >> JOY_LEFT_BIT & 1)
#define JOY_DOWN	(JOY_PORT->IDR >> JOY_DOWN_BIT & 1)

// GPIOA USART2 pins
#define TX_BIT	2
#define RX_BIT	3

#define OTG_PWREN_PORT	GPIOC
#define OTG_PWREN_BIT	9
#define OTG_PWREN_MSK	(1u << OTG_PWREN_BIT)

// PC11 - VBUS sense, PC12 - ID
