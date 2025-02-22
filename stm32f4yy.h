/*
	STM32F4 series enhanced defs
	gbm 09'2014

	To be included instead of original stm32f4xx.h.
*/

#ifndef __STM32F4YY_H
#define __STM32F4YY_H

#include "stm32f4xx.h"
#include "stm32yyyy.h"	// add defs common to STM32 family

// STM32F4x register/bit defs not present in stm32f4xx.h file

#define FLASH_CR_SNBV(v)	((v) << FLASH_CR_SNB_Pos & FLASH_CR_SNB_Msk)
#define FLASH_CR_PSIZEV(v)	((v) << FLASH_CR_PSIZE_Pos & FLASH_CR_PSIZE_Msk)
#define FLASH_CR_PSIZE32	FLASH_CR_PSIZEV(2)

#ifndef HSI_VALUE
#define HSI_VALUE	16000000u
#endif

#define RCC_CFGR_PLLMULV(a)	(((a - 2) & 0xf) << 18)

#define  RCC_PLLCFGR_RSVD	0xf0bc8000

#define  RCC_PLLCFGR_PLLMV(v)	((v) & 0x3f)	// 2..63
#define  RCC_PLLCFGR_PLLNV(v)	(((v) & 0x1ff) << RCC_PLLCFGR_PLLN_Pos)	// must be in range 50..432                     ((uint32_t)0x00007FC0)
#define  RCC_PLLCFGR_PLLPV(v)	(((((v) >> 1) - 1) & 3) << RCC_PLLCFGR_PLLP_Pos)	// 2, 4, 6, 8
#define  RCC_PLLCFGR_PLLQV(v)	(((v) & 0xf) << RCC_PLLCFGR_PLLQ_Pos)	// 2..15
#define  RCC_PLLCFGR_PLLRV(v)	(((v) & 0x7) << RCC_PLLCFGR_PLLR_Pos)	// 2..15

#define GPIO_OSPEEDR_LOW	0u
#define GPIO_OSPEEDR_MED	1u
#define GPIO_OSPEEDR_HI		2u
#define GPIO_OSPEEDR_VHI	3u

#define GPIOA_MODER_DEFAULT	0xa8000000	// value speified in RefMan is incorrect!
#define GPIOA_OSPEEDR_DEFAULT	0x0c000000
#define GPIOB_MODER_DEFAULT	0x0280
#define GPIOB_OSPEEDR_DEFAULT	0xc0
#define GPIOA_PUPDR_DEFAULT	0x64000000
//#define GPIOA_PUPDR_SWD	0x24000000

#define BSRRH(p)	(((uint16_t *)&(p->BSRR))[1])	// Bit Reset Register - upper halfword of BSRR
// RCC GPIO enable =======================================================
#define IOENR	AHB1ENR	// IO port enable register alias
#define RCC_IOENR_GPIOEN(p) ( (RCC_AHB1ENR_GPIOAEN) << GPIOIDX(p) )

#define PWR_CR_PLSV(a)	(((a) & 7) << 5)     /*!< Bit 0 */

#define DMA_SxCR_CHSELV(ch)	(((ch) & 7) << 25)
#define DMA_SxCR_MSIZE16	DMA_SxCR_MSIZE_0
#define DMA_SxCR_MSIZE32	DMA_SxCR_MSIZE_1
#define DMA_SxCR_PSIZE16	DMA_SxCR_PSIZE_0
#define DMA_SxCR_PSIZE32	DMA_SxCR_PSIZE_1
#define DMA_SxCR_DIR_P2M	0
#define DMA_SxCR_DIR_M2P	DMA_SxCR_DIR_0
#define DMA_SxCR_DIR_M2M	DMA_SxCR_DIR_1
#define DMA_LIFCR_CALLF0	0x3f
#define DMA_LIFCR_CALLF1	(0x3f << 6)
#define DMA_LIFCR_CALLF2	(0x3f << 16)
#define DMA_LIFCR_CALLF3	(0x3f << 22)
#define DMA_HIFCR_CALLF4	0x3f
#define DMA_HIFCR_CALLF5	(0x3f << 6)
#define DMA_HIFCR_CALLF6	(0x3f << 16)
#define DMA_HIFCR_CALLF7	(0x3f << 22)

// Calibration values stored in ROM
#define VREFINT_CAL_mV	3300u
#define VREFINT_CAL	(*(const uint16_t *)0x1fff7a2a)	// @ 3.3V

#define TS_CAL1_T	30
#define TS_CAL2_T	110
#define TS_CAL1	(*(const uint16_t *)0x1fff7a2c)
#define TS_CAL2	(*(const uint16_t *)0x1fff7a2e)

#define ADCH_VREF	17
#define	ADCH_TSEN	18

#define	ADC_SMPR_480	7

enum afn_ {AFN_SYS, AFN_TIM1_2, AFN_TIM3, AFN_TIM9,
	AFN_I2C, AFN_SPI1, AFN_SPI3, AFN_USART1_2,
	AFN_USART6, AFN_I2C2_3, AFN_USB};

#include "stm32util.h"

#endif
