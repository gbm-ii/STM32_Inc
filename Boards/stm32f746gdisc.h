/*
 * F743 Discovery board defs
 * gbm 09'14
 */
 
#include "stm32f7yy.h"

#define HSE_VALUE	25000000

#define LD1_PORT	GPIOI
#define LD1_BIT	1
// OTG_FS_Power
#define LD5_PORT	GPIOD
#define LD5_BIT	5
// OTG_FS_OverCurrent
#define LD6_PORT	GPIOD
#define LD6_BIT	4
// OTG_HS_OverCurrent
#define LD3_PORT	GPIOE
#define LD3_BIT	3

#define LD1_MSK	(1u << LD1_BIT)
#define LD3_MSK	(1u << LD3_BIT)
#define LD5_MSK	(1u << LD5_BIT)
#define LD6_MSK	(1u << LD6_BIT)

#define BTN_PORT	GPIOA
#define BTN_BIT	0

#define BTN_DOWN	(BTN_PORT->IDR >> BTN_BIT & 1)

// USART1 pins (connected to ST-Link VCOM)
#define TX1_PORT GPIOB
#define TX1_BIT	9
#define RX1_PORT GPIOB
#define RX1_BIT	7

#define OTG_FS_PWREN_PORT	GPIOC
#define OTG_PWREN_BIT	0
#define OTG_PWREN_MSK	(1u << OTG_PWREN_BIT)
