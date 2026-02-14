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
// STM32F0x register/bit defs not present in stm32f0xx.h file

#ifndef HSI_VALUE
#define HSI_VALUE	8000000u
#endif
#define INIT_HCLK_FREQ	HSI_VALUE

#define RCC_AHBENR_RSTVAL	(RCC_AHBENR_FLITFEN | RCC_AHBENR_SRAMEN)

#define IOENR	AHBENR	// RCC register containing GPIO enable bits
#define RCC_IOENR_GPIOENBIT(idx) ( (RCC_AHBENR_GPIOAEN) << (idx) )

#define GPIO_OSPEEDR_LOW	0u
#define GPIO_OSPEEDR_MED	1u
#define GPIO_OSPEEDR_HI	3u

#define ADC_SMPR_71_5	6
#define ADC_SMPR_239_5	7	// 17 us @ 14 MHz - for TS

#if defined STM32F042x6
#define SYSROM_BASE 0x1fffc400u
#endif
#if defined STM32F072xB
#define SYSROM_BASE 0x1fffc800u
#endif
#define BOOT_ADDR SYSROM_BASE

#define BOOTVEC ((union vectab_ *)BOOT_ADDR)

// Calibration values stored in ROM
#define VREFINT_CAL	(*(const uint16_t *)0x1ffff7ba)
#define TS_CAL1	(*(const uint16_t *)0x1ffff7b8)
#define TS_CAL2	(*(const uint16_t *)0x1ffff7c2)

#define TS_CAL1_T	30
#define TS_CAL2_T	110

#define FLASH_END	FLASH_BANK1_END

#ifndef FLASH_PAGE_SIZE
#if defined(STM32F072xB) || defined(STM32F334x8) || defined(STM32F030x8)
#define FLASH_PAGE_SIZE	2048u
#elif defined (STM32F051) || defined(STM32F030) || defined STM32F10X_MD || defined(STM32F042x6)
#define FLASH_PAGE_SIZE	1024u
#endif
#endif

#define SYSCFG_CFGR1_MEM_SYS	1u
#define SYSCFG_CFGR1_MEM_RAM	3u

enum afn_ {AFN_SPI, AFN_USART12, AFN_TIM3 = AFN_USART12, AFN_I2C1 = AFN_USART12, AFN_TIM12, AFN_TSC, AFN_USART34, AFN_TIM1X};

#include "stm32util.h"

#endif	// included
