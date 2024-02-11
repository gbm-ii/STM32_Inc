/*
	STM32G0 series enhanced defs - register/bit defs not present in stm32g0xx.h file
	to be included instead of stm32g0xx.h
	gbm 2020..2024
*/

#ifndef __STM32G0YY_H
#define __STM32G0YY_H

#include "stm32g0xx.h"
#include "stm32yyyy.h"

#define RCC_AHBENR_RSTVAL	(RCC_AHBENR_FLASHEN)

#define ADC_SMPR_1_5	0u
#define ADC_SMPR_3_5	1u
#define ADC_SMPR_7_5	2u
#define ADC_SMPR_12_5	3u
#define ADC_SMPR_19_5	4u
#define ADC_SMPR_39_5	5u
#define ADC_SMPR_79_5	6u
#define ADC_SMPR_160_5	7u	// 17 us @ 14 MHz - for TS

// Calibration values stored in ROM
#define VREFINT_CAL_mV	3000u	// calibration voltage
#define VREFINT_CAL	(*(uint16_t *)0x1fff75aa)

#define TS_CAL1	(*(uint16_t *)0x1fff75a8)	// at 30 C
#define TS_CAL2	(*(uint16_t *)0x1fff75ca)	// at 110 C

#ifndef FLASH_PAGE_SIZE
#define FLASH_PAGE_SIZE	2048u
#define FLASH_PG_SIZE	2048u
#endif

#define FLASH_SR_BSY	FLASH_SR_BSY1
#define FLASH_CR_PNBV(v)	((v) << FLASH_CR_PNB_Pos & FLASH_CR_PNB_Msk)
#define FLASH_UID	((const uint32_t *)UID_BASE)

#define GPIO_OSPEEDR_VLO	0u
#define GPIO_OSPEEDR_LO		1u
#define GPIO_OSPEEDR_HI		2u
#define GPIO_OSPEEDR_VHI	3u

#define RCC_PLLCFGR_PLLMV(x) (((x) - 1u) << RCC_PLLCFGR_PLLM_Pos & RCC_PLLCFGR_PLLM)
#define RCC_PLLCFGR_PLLNV(x) ((x) << RCC_PLLCFGR_PLLN_Pos & RCC_PLLCFGR_PLLN)
#define RCC_PLLCFGR_PLLQV(x) (((x) - 1u) << RCC_PLLCFGR_PLLQ_Pos & RCC_PLLCFGR_PLLQ)
#define RCC_PLLCFGR_PLLRV(x) (((x) - 1u) << RCC_PLLCFGR_PLLR_Pos & RCC_PLLCFGR_PLLR)

#define RCC_CFGR_SW_PLLRCLK	2u
#define RCC_CFGR_SW_LSI		3u

#define RCC_IOPENR_GPIOEN(a)	(RCC_IOPENR_GPIOAEN << ((a) - GPIOA))

#endif
