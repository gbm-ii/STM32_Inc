/*
 * F743 DevEBox STM32H7xx_M ver. 2.0 1907 board defs
 * gbm 07'21
 */
 
#include "stm32f7yy.h"

#define HSE_VALUE	25000000

// LED, active low
#define LED_PORT	GPIOA
#define LED_BIT	1
// may be TIM5CH2, TIM2CH2 or TIM15CH1N
#define LED_TIM	TIM5
#define LED_CCR	CCR2
#define LED_DUTY LED_TIM->LED_CCR

// Key 1, active low
#define K1_PORT	GPIOE
#define K1_BIT	3
// Key 2
#define K2_PORT	GPIOC
#define K2_BIT	5

#define LED_MSK	(1u << LED_BIT)
#define K1_MSK	(1u << K1_BIT)
#define K2_MSK	(1u << K2_BIT)

#define K1_DOWN	(K1_PORT->IDR >> K1_BIT & 1)
#define K2_DOWN	(K2_PORT->IDR >> K2_BIT & 1)

// TFT display on PB12..15(SPI2), PB0 (Blt), PB1 (D/C)

// QSPI BLK1

// USART1 pins (connected to ST-Link VCOM)
#define TX1_PORT GPIOB
#define TX1_BIT	9
#define RX1_PORT GPIOB
#define RX1_BIT	7
