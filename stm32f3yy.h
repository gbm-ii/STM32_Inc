/*
	STM32F3 series enhanced defs
	gbm 01'2015
*/

#ifndef __STM32F3YY_H
#define __STM32F3YY_H

#include "stm32f3xx.h"
#include "stm32fyyy.h"
#include "stm32util.h"

// STM32F3x register/bit defs not present in stm32f0xx.h file
#define HSI_VALUE	8000000

#define RCC_AHBENR_RSTVAL	(RCC_AHBENR_FLITFEN | RCC_AHBENR_SRAMEN)
#define RCC_CFGR_PLLMULV(a)	(((a - 2) & 0xf) << 18)

#define GPIOA_MODER_UART1	(BF2(10, GPIO_MODER_AF) | BF2(9, GPIO_MODER_AF)) // UART on 10-RX, 9-TX

#define TSC_CR_CTPHV(v)	((v & 0xf) << 28)
#define TSC_CR_CTPLV(v)	((v & 0xf) << 24)
#define TSC_CR_PGPSCV(v)	((v & 7) << 12)
#define TSC_CR_MCVV(v)	((v & 7) << 5)

#define TSC_IR_EOA	(1 << 0)
#define TSC_IR_MCE	(1 << 1)

#define DMA_CCR_MSIZE16	DMA_CCR_MSIZE_0
#define DMA_CCR_MSIZE32	DMA_CCR_MSIZE_1
#define DMA_CCR_PSIZE16	DMA_CCR_PSIZE_0
#define DMA_CCR_PSIZE32	DMA_CCR_PSIZE_1
#define DMA_CCR_DIR_P2M	0
#define DMA_CCR_DIR_M2P	DMA_CCR_DIR

#define ADC_SMPR_71_5	6
#define ADC_SMPR_239_5	7	// 17 us @ 14 MHz - for TS

// Calibration values stored in ROM
#define VREFINT_CAL	(*(uint16_t *)0x1ffff7ba)
#define TS_CAL1	(*(uint16_t *)0x1ffff7b8)
#define TS_CAL2	(*(uint16_t *)0x1ffff7c2)

#define T_CAL1	30
#define T_CAL2	110

#endif
