/*
	STM32F0 series enhanced defs
	gbm 01'2015
*/

#ifndef __STM32L0YY_H
#define __STM32L0YY_H

#include "stm32l0xx.h"
#include "stm32y0yy.h"
#include "stm32yyyy.h"
#include "stm32util.h"

#ifndef HSI_VALUE
#define HSI_VALUE	16000000
#endif

// STM32L0x register/bit defs not present in stm32f0xx.h file

#define RCC_AHBENR_RSTVAL	(RCC_AHBENR_MIFEN)
#define RCC_CFGR_PLLMULV(a)	(((a - 2) & 0xf) << 18)

#define GPIOA_MODER_UART1	(BF2(10, GPIO_MODER_AF) | BF2(9, GPIO_MODER_AF)) // UART on 10-RX, 9-TX

#define TSC_CR_CTPHV(v)	((v & 0xf) << 28)
#define TSC_CR_CTPLV(v)	((v & 0xf) << 24)
#define TSC_CR_PGPSCV(v)	((v & 7) << 12)
#define TSC_CR_MCVV(v)	((v & 7) << 5)

#define ADC_SMPR_79_5	6
#define ADC_SMPR_160_5	7	// 17 us @ 14 MHz - for TS

#ifndef FLASH_PDKEY1
#define FLASH_PDKEY1	0x04152637
#define FLASH_PDKEY2	0xfafbfcfd
#define FLASH_PEKEY1	0x89abcdef
#define FLASH_PEKEY2	0x02030405
#define FLASH_PRGKEY1	0x8c9daebf
#define FLASH_PRGKEY2	0x13141516
#define FLASH_OPTKEY1	0xfbead9c8
#define FLASH_OPTKEY2	0x24252627
#endif

#define DMA_CSEL(c,v)	BF4((c - 1), v)

// Calibration values stored in ROM
#define VREFINT_CAL_mV	3000
#define VREFINT_CAL	(*(uint16_t *)0x1ff80078)
#define TS_CAL1	(*(uint16_t *)0x1ff8007a)
#define TS_CAL2	(*(uint16_t *)0x1ff8007e)

#define T_CAL1	30
#define T_CAL2	110

#endif
