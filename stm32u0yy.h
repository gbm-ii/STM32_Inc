/*
	STM32U0 series enhanced defs - register/bit defs not present in stm32u0xx.h file
	to be included instead of stm32u0xx.h
	gbm 2024
	
	Incomplete, not verified, copied from stm32g0yy.h
*/

#ifndef __STM32U0YY_H
#define __STM32U0YY_H

#include "stm32u0xx.h"
#include "stm32yyyy.h"

#define RCC_AHBENR_RSTVAL	(RCC_AHBENR_FLASHEN)

// ADC ===================================================================
#define ADC_SMPR_1_5	0u
#define ADC_SMPR_3_5	1u
#define ADC_SMPR_7_5	2u
#define ADC_SMPR_12_5	3u
#define ADC_SMPR_19_5	4u
#define ADC_SMPR_39_5	5u
#define ADC_SMPR_79_5	6u
#define ADC_SMPR_160_5	7u	// 17 us @ 14 MHz - for TS

// internally-connected ADC channels
#define ADCH_TSEN	11u
#define ADCH_VREFINT	12u
#define ADCH_VBAT3	13u
#define ADCH_DACOUT	19u

// Calibration values stored in ROM
#define VREFINT_CAL_mV	3000u	// calibration voltage
#define VREFINT_CAL	(*(uint16_t *)0x1fff6ea4)

#define TS_CAL1	(*(uint16_t *)0x1fff6e68)	// at 30 C, 3 V
#define TS_CAL2	(*(uint16_t *)0x1fff6e8a)	// at 130 C
// DMAMUX ================================================================
enum dmamux_in_ {
	DMAMUX_IN_REQ_GEN0 = 1, DMAMUX_IN_REQ_GEN1, DMAMUX_IN_REQ_GEN2, DMAMUX_IN_REQ_GEN3,
	DMAMUX_IN_ADC,

	DMAMUX_IN_LPUART1_RX = 30, DMAMUX_IN_LPUART1_TX,
	DMAMUX_IN_LPUART2_RX, DMAMUX_IN_LPUART2_TX,
	DMAMUX_IN_LPUART3_RX, DMAMUX_IN_LPUART3_TX,

	DMAMUX_IN_SPI1_RX, DMAMUX_IN_SPI1_TX, DMAMUX_IN_SPI2_RX, DMAMUX_IN_SPI2_TX,
	DMAMUX_IN_SPI3_RX, DMAMUX_IN_SPI3_TX,

	DMAMUX_IN_TIM1_CH1 = 42, DMAMUX_IN_TIM1_CH2, DMAMUX_IN_TIM1_CH3, DMAMUX_IN_TIM1_CH4,
	DMAMUX_IN_TIM1_TRIG_COM, DMAMUX_IN_TIM1_UP,
	DMAMUX_IN_TIM2_CH1, DMAMUX_IN_TIM2_CH2, DMAMUX_IN_TIM2_CH3, DMAMUX_IN_TIM2_CH4,
	DMAMUX_IN_TIM2_TRIG, DMAMUX_IN_TIM2_UP,
	DMAMUX_IN_TIM3_CH1, DMAMUX_IN_TIM3_CH2, DMAMUX_IN_TIM3_CH3, DMAMUX_IN_TIM3_CH4,
	DMAMUX_IN_TIM3_TRIG, DMAMUX_IN_TIM3_UP,
	DMAMUX_IN_TIM6_UP, DMAMUX_IN_TIM7_UP,
	DMAMUX_IN_TIM15_CH1, DMAMUX_IN_TIM15_CH2,
	DMAMUX_IN_TIM15_TRIG_COM, DMAMUX_IN_TIM15_UP,
	DMAMUX_IN_TIM16_CH1, DMAMUX_IN_TIM16_COM, DMAMUX_IN_TIM16_UP,

	DMAMUX_IN_USART1_RX = 70, DMAMUX_IN_USART1_TX, DMAMUX_IN_USART2_RX, DMAMUX_IN_USART2_TX,
	DMAMUX_IN_USART3_RX, DMAMUX_IN_USART3_TX, DMAMUX_IN_USART4_RX, DMAMUX_IN_USART4_TX,
};
// Flash =================================================================
#ifndef FLASH_PAGE_SIZE
#define FLASH_PAGE_SIZE	2048u
#define FLASH_PG_SIZE	2048u
#endif

#define FLASH_SR_BSY	FLASH_SR_BSY1
#define FLASH_CR_PNBV(v)	((v) << FLASH_CR_PNB_Pos & FLASH_CR_PNB_Msk)
#define FLASH_UID	((const uint32_t *)UID_BASE)
// GPIO ==================================================================
#define GPIO_OSPEEDR_LO	0	// 2 MHz
#define GPIO_OSPEEDR_MED	1u		// 10 MHz
#define GPIO_OSPEEDR_HI	2u		// 30 MHz
#define GPIO_OSPEEDR_VHI	3u	// 60 MHz

enum afn_ {AFN_SYS, AFN_USART1_2, AFN_TIM1_2, AFN_USART6,
	AFN_USART3_4, AFN_LPTIM, AFN_UCPD, AFN_COMPOUT,
	AFN_I2C, AFN_SPI3_TIM4, AFN_LPUART2};
// RCC GPIO enable =======================================================
#define IOENR	IOPENR	// IO port enable register alias
#define GPIOIDX(p)	(((uint8_t *)(p) - (uint8_t *)GPIOA) / ((uint8_t *)GPIOB - (uint8_t *)GPIOA))
#define RCC_IOENR_GPIOEN(p) ( (RCC_IOPENR_GPIOAEN) << GPIOIDX(p) )
// RCC =============================================================================
#define RCC_PLLCFGR_PLLMV(x) (((x) - 1u) << RCC_PLLCFGR_PLLM_Pos & RCC_PLLCFGR_PLLM)
#define RCC_PLLCFGR_PLLNV(x) ((x) << RCC_PLLCFGR_PLLN_Pos & RCC_PLLCFGR_PLLN)
#define RCC_PLLCFGR_PLLQV(x) (((x) - 1u) << RCC_PLLCFGR_PLLQ_Pos & RCC_PLLCFGR_PLLQ)
#define RCC_PLLCFGR_PLLRV(x) (((x) - 1u) << RCC_PLLCFGR_PLLR_Pos & RCC_PLLCFGR_PLLR)

#define RCC_CFGR_SW_PLLRCLK	3u
#define RCC_CFGR_SW_LSI		4u

#endif
