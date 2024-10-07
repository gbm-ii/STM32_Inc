/*
	STM32C071 Nucleo64 board defs
	gbm 10'2024
*/
#ifndef STM32NUCLEO_C071_H_
#define STM32NUCLEO_C071_H_
//========================================================================
#define BTN_PORT	GPIOC
#define BTN_BIT		13
#define BTN_MSK		(1u << BTN_BIT)
#define BTN_DOWN	((~BTN_PORT->IDR >> BTN_BIT & 1))	// active low

#define LED_PORT	GPIOA
#define LED_BIT		5
#define LED_MSK		(1u << LED_BIT)
// active high
#define LED_DUTY	TIM2->CCR1

#define VCP_UART	USART2
#define VCP_PORT	GPIOA
#define VCP_TX_BIT	2	// AF4
#define VCP_RX_BIT	3	// AF4
//========================================================================
#endif
