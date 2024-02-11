/*
	STM32F0 & L0 series enhanced defs
	gbm 11'2015
*/

#ifndef __STM32Y0YY_H
#define __STM32Y0YY_H

#include "stm32yyyy.h"

// STM32F0x/L0x register/bit defs not present in stm32f0xx.h file

#define RCC_CFGR_PLLDIVV(a)	(((a - 1) & 3) << 22)	// L0
#define RCC_CFGR_PLLMULV(a)	(((a - 2) & 0xf) << 18)	// F0 only

#define GPIOA_MODER_UART1	(BF2(10, GPIO_MODER_AF) | BF2(9, GPIO_MODER_AF)) // UART on 10-RX, 9-TX

#define TSC_CR_CTPHV(v)	((v & 0xf) << 28)
#define TSC_CR_CTPLV(v)	((v & 0xf) << 24)
#define TSC_CR_PGPSCV(v)	((v & 7) << 12)
#define TSC_CR_MCVV(v)	((v & 7) << 5)

//#define DMA_CCR_CHSELV(ch)	(((ch) & 7) << 25)

#define ADC_SMPR_71_5	6
#define ADC_SMPR_239_5	7	// 17 us @ 14 MHz - for TS

// Calibration values stored in ROM - moved to series-specific file
//#define VREFINT_CAL	(*(uint16_t *)0x1ffff7ba)
//#define TS_CAL1	(*(uint16_t *)0x1ffff7b8)
//#define TS_CAL2	(*(uint16_t *)0x1ffff7c2)

#define T_CAL1	30
#define T_CAL2	110

#endif
