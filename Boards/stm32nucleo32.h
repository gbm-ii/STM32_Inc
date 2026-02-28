/*
	STM32F Nucleo-32 board defs
	gbm 11'2021
*/
#ifndef STM32NUCLEO32_H_
#define STM32NUCLEO32_H_
//========================================================================
// There is no button on Nucleo-32 but a jumper on CN3 between GND pin 4
// and PA12 pin 5 is supposed to act as one.
#define BTN_PORT	GPIOA
#define BTN_BIT		12	// jumper position
#define BTN_PULL	GPIO_PUPDR_PU

#define BTN_DOWN	((~BTN_PORT->IDR >> BTN_BIT & 1))

#define LED_PORT	GPIOB
#define LED_BIT	3
#define LED_ACTIVE_LEVEL	1u
#define LED_MSK	(1u << LED_BIT)

#define LED_DUTY	TIM2->CCR2	// L011, AF2

#define VCP_UART	USART2
#define VCP_PORT	GPIOA
#define VCP_TX_BIT	2	// AF4
#define VCP_RX_BIT	15	// AF4
//========================================================================
#endif
