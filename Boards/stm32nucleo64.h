/*
	STM32 Nucleo64 board defs
	gbm 11'2015..10'2024
*/
#ifndef STM32NUCLEO64_H_
#define STM32NUCLEO64_H_

// MCU header should be included BEFORE this file, so that MCU type and family symbols are defined
//========================================================================
// user button - blue
#define BTN_PORT	GPIOC
#define BTN_BIT		13
#define BTN_MSK		(1u << BTN_BIT)

#if defined(STM32G0) || defined(STM32G4) || defined(STM32H5) || defined(STM32U5)
// user button active high
#define BTN_DOWN	((BTN_PORT->IDR >> BTN_BIT & 1u))
#define BTN_PULL	GPIO_PUPDR_PD	// defined in stm32yyyy.h
#else
// user button active low
#define BTN_DOWN	((~BTN_PORT->IDR >> BTN_BIT & 1u))
#define BTN_PULL	GPIO_PUPDR_PU	// defined in stm32yyyy.h
#endif

// green LED, active high - PA5 on all boards
#define LEDG_PORT		GPIOA
#define LEDG_BIT	5
#define LEDG_MSK	(1u << LED_BIT)
#define LEDG_DUTY	TIM2->CCR1	// may not be supported by all MCUs

#define LED_PORT		LEDG_PORT
#define LED_BIT	LEDG_BIT
#define LED_MSK	LEDG_MSK
#define LED_DUTY	LEDG_DUTY

#ifdef STM32C071xx
// blue LED, active low - PC9 on Nucleo-C071
#define LEDB_PORT		GPIOC
#define LEDB_BIT	9
#define LEDB_MSK	(1u << LED_BIT)
//#define LEDB_DUTY	TIM3->CCR4	// also TIM1_CH2
//#define AFN_LEDB_TIM	1u	// TIM3

// BOOT button (small black), may be used as 2nd user button, active high
#define BOOT_PORT	GPIOA
#define BOOT_BIT	14
#define BOOT_MSK	(1u << 14)
#define BOOT_DOWN	((BOOT_PORT->IDR >> BTN_BIT & 1u))
#endif	// C071

// VCP UART
#define VCP_PORT	GPIOA	// All N64 boards

#ifdef STM32U5
#define VCP_TX_BIT	9
#define VCP_RX_BIT	10
#define VCP_UART	USART1

#else
#define VCP_RX_BIT	3

#ifdef STM32H503xx
// H503 only, H533 uses standard PA2, PA3, USART2
#define VCP_TX_BIT	4
#define VCP_UART	USART3

#else	// all except U545, H503
#define VCP_TX_BIT	2

#if defined(STM32G4)
#define VCP_UART	LPUART1
#else
#define VCP_UART	USART2
#endif

#endif	// H503
#endif	// U5

// HSE clock source
#ifdef STM32C0
#define HSE_FREQ	48000000u
#define RCC_CR_HSE_ON	(RCC_CR_HSEON)	// crystal
#elif defined(STM32H5) || defined(STM32G4)
#define HSE_FREQ	24000000u
#define RCC_CR_HSE_ON	(RCC_CR_HSEON)	// crystal
#elif defined(STM32L4)
// no HSE connection by default! (use MSI synchronized to LSE)
#else
// other, "standard" boards - 8 MHz clock from ST-Link - set HSE_BYPASS
#define HSE_FREQ	8000000u
#define RCC_CR_HSE_ON	(RCC_CR_HSEON | RCC_CR_HSEBYP)
#endif
//========================================================================
#endif
