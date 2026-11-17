/*
	STM32G4 series enhanced defs
	gbm 2026

	To be included instead of the original stm32l5xx.h file.
*/

#ifndef __STM32G4YY_H
#define __STM32G4YY_H

#include "stm32g4xx.h"
#include "stm32yyyy.h"	// add defs common to STM32 family

#define SYSROM_BASE	0x1fff0000

// STM32G4x register/bit defs not present in stm32f4xx.h file

#define FLASH_CR_PNBV(v)	(((v) & 0x1ff) << 3)
//#define FLASH_CR_PSIZEV(v)	(((v) & 3) << 8)
//#define FLASH_CR_PSIZE32	(2 << 8)

#undef	RCC_CFGR_SW_PLL
#define RCC_CFGR_SW_PLL			(RCC_CFGR_SW_1 | RCC_CFGR_SW_0)

enum afn_ {AFN_TIM2 = 1, AFN_I2C = 4, AFN_SPI, AFN_SPI3, AFN_USART = 7,
	AFN_UART4};

// RCC GPIO enable =======================================================
#define IOENR	AHB2ENR	// IO port enable register alias
#define RCC_IOENR_GPIOAEN	RCC_AHB2ENR_GPIOAEN

#define GPIOA_MODER_DEFAULT	0xabffffff	// ok, not needed
#define GPIOA_OSPEEDR_DEFAULT	0x0c000000	// ok
#define GPIOB_MODER_DEFAULT	0xfffffebf
#define GPIOA_PUPDR_DEFAULT	0x64000000
#define GPIOB_PUPDR_DEFAULT	0x100

#define GPIO_OSPEEDR_LOW	0u
#define GPIO_OSPEEDR_MED	1u
#define GPIO_OSPEEDR_HI		2u
#define GPIO_OSPEEDR_VHI	3u

#define  PWR_CR2_PLSV(a)	(((a) & 7) << 1)     /*!< Bit 0 */

#define DMA_CCR_MSIZE16	DMA_CCR_MSIZE_0
#define DMA_CCR_MSIZE32	DMA_CCR_MSIZE_1
#define DMA_CCR_PSIZE16	DMA_CCR_PSIZE_0
#define DMA_CCR_PSIZE32	DMA_CCR_PSIZE_1
#define DMA_CCR_DIR_P2M	0
#define DMA_CCR_DIR_M2P	DMA_CCR_DIR

// Calibration values stored in ROM
#define VREFINT_CAL_mV	3000
#define VREFINT_CAL	(*(uint16_t *)0x1fff75aa)	// @ 3.0V
#define TS_CAL1	(*(int16_t *)0x1fff75a8)
#define TS_CAL2	(*(int16_t *)0x1fff75ca)

#define T_CAL1	30
#define T_CAL2	130

#define ADCH_VREF	18u
#define	ADCH_TSEN	16u
#define	ADCH_VBAT3	17u

enum adc_smpt_ {ADC_SMPT_2, ADC_SMPT_6, ADC_SMPT_12, ADC_SMPT_24, ADC_SMPT_47, ADC_SMPT_92, ADC_SMPT_247, ADC_SMPT_640};

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

#include "stm32util.h"

#endif
