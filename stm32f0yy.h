/*
	STM32F0 series enhanced defs
	gbm 01'2015
*/

#ifndef __STM32F0YY_H
#define __STM32F0YY_H

#include <stdbool.h>
#include "stm32f0xx.h"
#include "stm32y0yy.h"
#include "stm32yyyy.h"
#include "stm32util.h"

// STM32F0x register/bit defs not present in stm32f0xx.h file

#ifndef HSI_VALUE
#define HSI_VALUE	8000000u
#endif

#define RCC_AHBENR_RSTVAL	(RCC_AHBENR_FLITFEN | RCC_AHBENR_SRAMEN)

#define RCC_IOENR_GPIOEN(p) ( (RCC_AHBENR_GPIOAEN) << GPIOIDX(p) )

#define GPIO_OSPEEDR_LOW	0u
#define GPIO_OSPEEDR_MED	1u
#define GPIO_OSPEEDR_HI	3u

#define ADC_SMPR_71_5	6
#define ADC_SMPR_239_5	7	// 17 us @ 14 MHz - for TS

// Calibration values stored in ROM
#define VREFINT_CAL	(*(uint16_t *)0x1ffff7ba)
#define TS_CAL1	(*(uint16_t *)0x1ffff7b8)
#define TS_CAL2	(*(uint16_t *)0x1ffff7c2)

#define T_CAL1	30
#define T_CAL2	110

#ifndef FLASH_PAGE_SIZE
#if defined(STM32F072xB) || defined(STM32F334x8) || defined(STM32F030x8)
#define FLASH_PAGE_SIZE	2048u
#elif defined (STM32F051) || defined(STM32F030) || defined STM32F10X_MD || defined(STM32F042x6)
#define FLASH_PAGE_SIZE	1024u
#endif
#endif

#if defined STM32F042x6
#define BOOT_ADDR 0x1fffc400u
#endif
#if defined STM32F072xB
#define BOOT_ADDR 0x1fffc800u
#endif

#define BOOTVEC ((union vectab_ *)BOOT_ADDR)

#define SYSCFG_CFGR1_MEM_SYS	1u
#define SYSCFG_CFGR1_MEM_RAM	3u

enum afn_ {AFN_SPI, AFN_USART12, AFN_TIM3 = AFN_USART12, AFN_I2C1 = AFN_USART12, AFN_TIM12, AFN_TSC, AFN_USART34, AFN_TIM1X};

#endif	// included
