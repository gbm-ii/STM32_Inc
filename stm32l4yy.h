/*
	STM32L4 series enhanced defs
	gbm 03'2016-07'2021

	To be included instead of the original stm32f4xx.h file.
*/

#ifndef __STM32L4YY_H
#define __STM32L4YY_H

#include <stdbool.h>
#include "stm32l4xx.h"
#include "stm32yyyy.h"	// add defs common to STM32 family
#include "stm32util.h"

#ifdef OCTOSPI1
#define STM32L4PLUS
#endif

#ifndef FLASH_PAGE_SIZE

#ifdef STM32L4PLUS
#define FLASH_PAGE_SIZE	4096u
#else
#define FLASH_PAGE_SIZE	2048u
#endif

#endif

// STM32L4x register/bit defs not present in stm32f4xx.h file

#define FLASH_CR_PNBV(v)	(((v) & 0x1ff) << 3)
//#define FLASH_CR_PSIZEV(v)	(((v) & 3) << 8)
//#define FLASH_CR_PSIZE32	(2 << 8)

#define RCC_CFGR_PLLMULV(a)	(((a - 2) & 0xf) << 18)

#define  RCC_PLLCFGR_PLLMV(v)	(((v - 1) & 7) << 4)	// prediv 1..8 to get 4..16 MHz PLL input
#define  RCC_PLLCFGR_PLLNV(v)	((v & 0x7f) << 8)	// must be in range 8..86
#define  RCC_PLLCFGR_PLLRV(v)	((((v >> 1) - 1) & 3) << 25)	// 2, 4, 6, 8
#define  RCC_PLLCFGR_PLLQV(v)	((((v >> 1) - 1) & 3) << 21)	// 2, 4, 6, 8

#define GPIOA_MODER_DEFAULT	0xabffffff	// ok, not needed
#define GPIOA_OSPEEDR_DEFAULT	0x0c000000	// ok
#define GPIOB_MODER_DEFAULT	0xfffffebf
#define GPIOA_PUPDR_DEFAULT	0x64000000
#define GPIOB_PUPDR_DEFAULT	0x100

#define GPIO_OSPEEDR_LOW	0u
#define GPIO_OSPEEDR_MED	1u
#define GPIO_OSPEEDR_HI		2u
#define GPIO_OSPEEDR_VHI	3u

#define IOENR	AHB2ENR	// IO port enable register alias

#define GPIOIDX(p)	(((uint8_t *)(p) - (uint8_t *)GPIOA) / ((uint8_t *)GPIOB - (uint8_t *)GPIOA))
#define RCC_IOENR_GPIOEN(p) ( (RCC_AHB2ENR_GPIOAEN) << GPIOIDX(p) )

//#define BRR(p)	(((uint16_t *)&(p->BSRR))[1])	// Bit Reset Register - upper halfword of BSRR

enum afn_ {AFN_TIM1 = 1, AFN_USB = 10, AFN_OCTOSPI = 10, AFN_TIM15_17 = 14};

#define  PWR_CR2_PLSV(a)	(((a) & 7) << 1)     /*!< Bit 0 */

//#define	PR	PR1	// EXTI
#define	EXTI_RTSR_TR16	EXTI_RTSR1_RT16

#define DMA_CCR_MSIZE16	DMA_CCR_MSIZE_0
#define DMA_CCR_MSIZE32	DMA_CCR_MSIZE_1
#define DMA_CCR_PSIZE16	DMA_CCR_PSIZE_0
#define DMA_CCR_PSIZE32	DMA_CCR_PSIZE_1
#define DMA_CCR_DIR_P2M	0
#define DMA_CCR_DIR_M2P	DMA_CCR_DIR

#ifdef DMA1_CSELR
#define DMArq_ADC	0u
#define DMArq_SPI12	1u
#define DMArq_USART	2u
#endif

//#define VREFINT_mV	1210

// Calibration values stored in ROM
#define VREFINT_CAL_mV	3000
#define VREFINT_CAL	(*(uint16_t *)0x1fff75aa)	// @ 3.0V
#define TS_CAL1	(*(int16_t *)0x1fff75a8)
#define TS_CAL2	(*(int16_t *)0x1fff75ca)

#define T_CAL1	30
#if defined(STM32L412xx) || defined(STM32L496xx) || defined(STM32L4PLUS)
// newer models are calibrated at 130
#define T_CAL2	130
#else
#define xT_CAL2	110
#endif

#define ADCH_VREF	0
#define	ADCH_TSEN	17
#define	ADCH_VBAT	18

enum adc_smpt_ {ADC_SMPT_2, ADC_SMPT_6, ADC_SMPT_12, ADC_SMPT_24, ADC_SMPT_47, ADC_SMPT_92, ADC_SMPT_247, ADC_SMPT_640};
#define	ADC_SMPT_MAX	7

// 4 bit field only in the lower half of a 32-bit register
#define BF4_LHW(b,v)	((uint16_t)(v) << ((b & 3) * 4))

#define	QUADSPI_CCR_IMODE1	(QUADSPI_CCR_IMODE_0)
#define	QUADSPI_CCR_IMODE2	(QUADSPI_CCR_IMODE_1)
#define	QUADSPI_CCR_IMODE4	(QUADSPI_CCR_IMODE_1 | QUADSPI_CCR_IMODE_0)
#define	QUADSPI_CCR_ADMODE1	(QUADSPI_CCR_ADMODE_0)
#define	QUADSPI_CCR_ADMODE2	(QUADSPI_CCR_ADMODE_1)
#define	QUADSPI_CCR_ADMODE4	(QUADSPI_CCR_ADMODE_1 | QUADSPI_CCR_ADMODE_0)
#define	QUADSPI_CCR_ADSIZE16	(1u << QUADSPI_CCR_ADSIZE_Pos)
#define	QUADSPI_CCR_ADSIZE24	(2u << QUADSPI_CCR_ADSIZE_Pos)
#define	QUADSPI_CCR_ADSIZE32	(3u << QUADSPI_CCR_ADSIZE_Pos)
#define	QUADSPI_CCR_ABMODE1	(QUADSPI_CCR_ABMODE_0)
#define	QUADSPI_CCR_ABMODE2	(QUADSPI_CCR_ABMODE_1)
#define	QUADSPI_CCR_ABMODE4	(QUADSPI_CCR_ABMODE_1 | QUADSPI_CCR_ABMODE_0)
#define	QUADSPI_CCR_DMODE1	(QUADSPI_CCR_DMODE_0)
#define	QUADSPI_CCR_DMODE2	(QUADSPI_CCR_DMODE_1)
#define	QUADSPI_CCR_DMODE4	(QUADSPI_CCR_DMODE_1 | QUADSPI_CCR_DMODE_0)

#define	QUADSPI_CCR_FMODE_IW	(0u << QUADSPI_CCR_FMODE_Pos)
#define	QUADSPI_CCR_FMODE_IR	(1u << QUADSPI_CCR_FMODE_Pos)
#define	QUADSPI_CCR_FMODE_AP	(2u << QUADSPI_CCR_FMODE_Pos)
#define	QUADSPI_CCR_FMODE_MM	(3u << QUADSPI_CCR_FMODE_Pos)

#define	OCTOSPI_CCR_IMODE1	(OCTOSPI_CCR_IMODE_0)
#define	OCTOSPI_CCR_IMODE2	(OCTOSPI_CCR_IMODE_1)
#define	OCTOSPI_CCR_IMODE4	(OCTOSPI_CCR_IMODE_1 | OCTOSPI_CCR_IMODE_0)
#define	OCTOSPI_CCR_ADMODE1	(OCTOSPI_CCR_ADMODE_0)
#define	OCTOSPI_CCR_ADMODE2	(OCTOSPI_CCR_ADMODE_1)
#define	OCTOSPI_CCR_ADMODE4	(OCTOSPI_CCR_ADMODE_1 | OCTOSPI_CCR_ADMODE_0)
#define	OCTOSPI_CCR_ADSIZE16	(1u << OCTOSPI_CCR_ADSIZE_Pos)
#define	OCTOSPI_CCR_ADSIZE24	(2u << OCTOSPI_CCR_ADSIZE_Pos)
#define	OCTOSPI_CCR_ADSIZE32	(3u << OCTOSPI_CCR_ADSIZE_Pos)
#define	OCTOSPI_CCR_ABMODE1	(OCTOSPI_CCR_ABMODE_0)
#define	OCTOSPI_CCR_ABMODE2	(OCTOSPI_CCR_ABMODE_1)
#define	OCTOSPI_CCR_ABMODE4	(OCTOSPI_CCR_ABMODE_1 | OCTOSPI_CCR_ABMODE_0)
#define	OCTOSPI_CCR_DMODE1	(OCTOSPI_CCR_DMODE_0)
#define	OCTOSPI_CCR_DMODE2	(OCTOSPI_CCR_DMODE_1)
#define	OCTOSPI_CCR_DMODE4	(OCTOSPI_CCR_DMODE_1 | OCTOSPI_CCR_DMODE_0)

#define	OCTOSPI_CR_FMODE_IW	(0u << OCTOSPI_CR_FMODE_Pos)
#define	OCTOSPI_CR_FMODE_IR	(1u << OCTOSPI_CR_FMODE_Pos)
#define	OCTOSPI_CR_FMODE_AP	(2u << OCTOSPI_CR_FMODE_Pos)
#define	OCTOSPI_CR_FMODE_MM	(3u << OCTOSPI_CR_FMODE_Pos)

#define OCTOSPI_FCR_CTOF	OCTOSPI_FCR_TOF	// correct header file error
#endif
