/*
	STM32G0 series enhanced defs
	gbm 01'2020
*/

#ifndef __STM32F0YY_H
#define __STM32F0YY_H

#include "stm32g0xx.h"
#include "stm32y0yy.h"
#include "stm32yyyy.h"
#include "stm32util.h"

// STM32G0x register/bit defs not present in stm32g0xx.h file

#define RCC_AHBENR_RSTVAL	(RCC_AHBENR_FLITFEN | RCC_AHBENR_SRAMEN)

#define ADC_SMPR_71_5	6
#define ADC_SMPR_239_5	7	// 17 us @ 14 MHz - for TS

// Calibration values stored in ROM
#define VREFINT_CAL	(*(uint16_t *)0x1ffff7ba)
#define TS_CAL1	(*(uint16_t *)0x1ffff7b8)
#define TS_CAL2	(*(uint16_t *)0x1ffff7c2)

#define T_CAL1	30
#define T_CAL2	110

#ifndef FLASH_PAGE_SIZE
#define FLASH_PAGE_SIZE	2048u
#define FLASH_PG_SIZE	2048u
#endif

#define FLASH_SR_BSY	FLASH_SR_BSY1
#define FLASH_CR_PNBV(v)	((v) << FLASH_CR_PNB_Pos & FLASH_CR_PNB_Msk)


#endif
