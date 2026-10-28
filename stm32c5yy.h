/*
	STM32C5 series enhanced defs - register/bit defs not present in stm32g0xx.h file
	to be included instead of stm32c5xx.h
	gbm 2026

	initial version, copied from c0; not checked yet
*/

#ifndef __STM32C5YY_H
#define __STM32C5YY_H

#include "stm32c5xx.h"
#include "stm32yyyy.h"

// ADC ===================================================================
//enum adc_smpr_ {};
#define ADC_SMPR_3	0u
#define ADC_SMPR_5	1u
#define ADC_SMPR_8	2u
#define ADC_SMPR_13	3u
#define ADC_SMPR_25	4u
#define ADC_SMPR_48	5u
#define ADC_SMPR_139	6u
#define ADC_SMPR_289	7u	// 17 us @ 14 MHz - for TS

// internally-connected ADC1 channels
#define ADCH_TSEN	12u
#define ADCH_VREFINT	13u
// System ROM ============================================================
#define SYSROM_BASE	0x0BF80000	// System ROM bootloader

// Calibration values stored in ROM
#define VREFINT_CAL_mV	3300u	// calibration voltage
#define VREFINT_CAL	(*(const uint16_t *)0x08fff810)

#define TS_CAL1_T 30
#define TS_CAL2_T 140
#define TS_CAL1	(*(const uint16_t *)0x08fff814)	// at 30 C
#define TS_CAL2	(*(const uint16_t *)0x08fff818)	// at 140 C
// DMAMUX ================================================================
enum dma_reqsel_ {
	DMA_REQ_ADC1, DMA_REQ_ADC2,
	DMA_REQ_TIM6_UP, DMA_REQ_TIM7_UP,
	DMA_REQ_SPI1_RX, DMA_REQ_SPI1_TX,
	DMA_REQ_SPI2_RX, DMA_REQ_SPI2_TX,
	DMA_REQ_SPI3_RX, DMA_REQ_SPI3_TX,
	DMA_REQ_I2C1_RX = 10, DMA_REQ_I2C1_TX,
	DMA_REQ_USART1_RX, DMA_REQ_USART1_TX,
	DMA_REQ_USART2_RX, DMA_REQ_USART2_TX,
	DMA_REQ_USART3_RX, DMA_REQ_USART3_TX,
/*
	DMAMUX_IN_TIM1_CH1 = 20, DMAMUX_IN_TIM1_CH2, DMAMUX_IN_TIM1_CH3, DMAMUX_IN_TIM1_CH4,
	DMAMUX_IN_TIM1_TRIG_COM, DMAMUX_IN_TIM1_UP,
	DMAMUX_IN_TIM2_CH1, DMAMUX_IN_TIM2_CH2, DMAMUX_IN_TIM2_CH3, DMAMUX_IN_TIM2_CH4,
	DMAMUX_IN_TIM2_TRIG, DMAMUX_IN_TIM2_UP,
	DMAMUX_IN_TIM3_CH1, DMAMUX_IN_TIM3_CH2, DMAMUX_IN_TIM3_CH3, DMAMUX_IN_TIM3_CH4,
	DMAMUX_IN_TIM3_TRIG, DMAMUX_IN_TIM3_UP,
	DMAMUX_IN_TIM16_CH1 = 44, DMAMUX_IN_TIM16_COM, DMAMUX_IN_TIM16_UP,
	DMAMUX_IN_TIM17_CH1, DMAMUX_IN_TIM17_COM, DMAMUX_IN_TIM17_UP,
	DMAMUX_IN_USART1_RX = 50, DMAMUX_IN_USART1_TX, DMAMUX_IN_USART2_RX, DMAMUX_IN_USART2_TX,
*/
};
// Flash =================================================================

#define FLASH_CR_PNBV(v)	((v) << FLASH_CR_PNB_Pos & FLASH_CR_PNB_Msk)
#define FLASH_UID	((const uint32_t *)UID_BASE)
// GPIO ==================================================================
#define GPIO_OSPEEDR_LO	0	// 4 MHz
#define GPIO_OSPEEDR_MED	1u		// 12 MHz
#define GPIO_OSPEEDR_HI	2u		// 50 MHz
#define GPIO_OSPEEDR_VHI	3u	// 96 MHz

enum afn_ {AFN_SYS, AFN_TIM1_2, AFN_TIM3_5,
	AFN_I2C = 4, AFN_USARTx = 7, AFN_UARTx, AFN_EVTOUT = 15,
};
// RCC ===================================================================
#define RCC_AHB1ENR_RSTVAL	(RCC_AHB1ENR_SRAM1EN | RCC_AHB1ENR_SRAM2EN | RCC_AHB1ENR_FLASHEN)
// RCC GPIO enable -------------------------------------------------------
#define IOENR	AHB2ENR	// IO port enable register alias
#define RCC_IOENR_GPIOAEN	RCC_AHB2ENR_GPIOAEN

// RCC->CFGR bitfields ---------------------------------------------------
#define RCC_CFGR1_SW_HSIDIV3	0u
#define RCC_CFGR1_SW_HSIS		1u
#define RCC_CFGR1_SW_HSE	2u
#define RCC_CFGR1_SW_PSIS		3u

#include "stm32util.h"

#endif
