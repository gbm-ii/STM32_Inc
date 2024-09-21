/*
	STM32U5 series enhanced defs
	gbm 01'2024

	To be included instead of original stm32h5xx.h.
*/

#ifndef __STM32U5YY_H
#define __STM32U5YY_H

#include <stdbool.h>
#include "stm32u5xx.h"
#include "stm32yyyy.h"	// add defs common to STM32 family
//#include "stm32util.h"

// STM32H5x register/bit defs not present in stm32h5xx.h file

#define GPIO_OSPEEDR_LO	0	// 2 MHz
#define GPIO_OSPEEDR_MED	1u		// 10 MHz
#define GPIO_OSPEEDR_HI	2u		// 30 MHz
#define GPIO_OSPEEDR_VHI	3u	// 60 MHz

enum afn_ {AFN_SYS, AFN_TIM1_2, AFN_LPTIM1_TIM3, AFN_LPTIM2,
	AFN_USART1_2, AFN_SPI1, AFN_SPI2, AFN_SPI23_UART,
	AFN_I2C2, AFN_USART23, AFN_USB, AFN_I2C1,
	AFN_COMP, AFN_USART23x, AFN_TIM123, AFN_EVT};

#define	RCC_PLLxCFGR_PLLxSRC_HSI	RCC_PLL1CFGR_PLL1SRC_0
#define	RCC_PLLxCFGR_PLLxSRC_HSE	RCC_PLL1CFGR_PLL1SRC

#define RCC_CFGR1_SW_PLL1	RCC_CFGR1_SW

#define IOENR	AHB2ENR1	// IO port enable register alias

#define GPIOIDX(p)	(((uint8_t *)(p) - (uint8_t *)GPIOA) / ((uint8_t *)GPIOB - (uint8_t *)GPIOA))
#define RCC_IOENR_GPIOEN(p) ( (RCC_AHB2ENR1_GPIOAEN) << GPIOIDX(p) )

#define  PWR_CR_PLSV(a)	(((a) & 7) << 5)     /*!< Bit 0 */

// Calibration values stored in ROM
//#define VREFINT_mV	3300u
//#define VREFINT_CAL	(*(uint16_t *)0x08fff810)	// @ 3.3V
// 14-bit cal values
#define VREFINT_mV	3000u
#define VREFINT_CAL	(*(uint16_t *)0x0bfa07a5)	// @ 3.0V
#define TS_CAL1	(*(uint16_t *)0x0bfa0710)	// @ 3.0V
#define TS_CAL2	(*(uint16_t *)0x0bfa0742)	// @ 3.0V
#define T_CAL1	30u
#define T_CAL2	130u

#define ADCH_VREF	17

#define	ADC_SMPR_480	7


#endif
