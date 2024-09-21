/*
	STM32U083C-DK board defs
	gbm 09'2024
*/
#ifndef STM32U0DK_H_
#define STM32U0DK_H_
//========================================================================
// Joystick center shorts PC2 to GND, others may be read using ADC - see the schematic
#define BTN_PORT	GPIOC
#define BTN_BIT		2
#define BTN_MSK		(1u << BTN_BIT)
#define BTN_DOWN	((~BTN_PORT->IDR >> BTN_BIT & 1))

#define LEDR_PORT		GPIOB
#define LEDR_BIT	2
#define LEDR_MSK	(1u << LED_BIT)

#define LEDG_PORT		GPIOC
#define LEDG_BIT	13
#define LEDG_MSK	(1u << LED_BIT)

#define LEDB_PORT		GPIOA
#define LEDB_BIT	5
#define LEDB_MSK	(1u << LED_BIT)

#define LED_PORT		LEDB_PORT
#define LED_BIT	LEDB_BIT
#define LED_MSK	(1u << LED_BIT)

#define LEDR_DUTY	LPTIM1->CCR3
#define LEDG_DUTY	LPTIM1->CCR1
#define LEDB_DUTY	TIM2->CCR1

#define VCP_UART	USART2
#define VCP_PORT	GPIOA
#define VCP_TX_BIT	2	// AF7
#define VCP_RX_BIT	3	// AF7
//========================================================================
#endif
