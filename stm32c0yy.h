/*
	STM32G0 series enhanced defs - register/bit defs not present in stm32g0xx.h file
	to be included instead of stm32g0xx.h
	gbm 2020..2024
*/

#ifndef __STM32C0YY_H
#define __STM32C0YY_H

#include "stm32c0xx.h"
#include "stm32yyyy.h"

// same as G0 series
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

// different from G0
// internally-connected ADC channels
#define ADCH_TSEN	9u
#define ADCH_VREFINT	10u
#define ADCH_VDDA	15u
#define ADCH_VSSA	16u

// Calibration values stored in ROM
#define VREFINT_CAL_mV	3000u	// calibration voltage
#define VREFINT_CAL	(*(uint16_t *)0x1fff756a)

#define TS_CAL1	(*(uint16_t *)0x1fff7568)	// at 30 C

#define BOOT_ADDR	0x1fff0000	// System ROM bootloader

// DMAMUX ================================================================
enum dmamux_in_ {
	DMAMUX_IN_REQ_GEN0 = 1, DMAMUX_IN_REQ_GEN1, DMAMUX_IN_REQ_GEN2, DMAMUX_IN_REQ_GEN3,
	DMAMUX_IN_ADC,

	DMAMUX_IN_LPUART1_RX = 14, DMAMUX_IN_LPUART1_TX,
	DMAMUX_IN_SPI1_RX, DMAMUX_IN_SPI1_TX, DMAMUX_IN_SPI2_RX, DMAMUX_IN_SPI2_TX,
	DMAMUX_IN_TIM1_CH1, DMAMUX_IN_TIM1_CH2, DMAMUX_IN_TIM1_CH3, DMAMUX_IN_TIM1_CH4,
	DMAMUX_IN_TIM1_TRIG_COM, DMAMUX_IN_TIM1_UP,
	DMAMUX_IN_TIM2_CH1, DMAMUX_IN_TIM2_CH2, DMAMUX_IN_TIM2_CH3, DMAMUX_IN_TIM2_CH4,
	DMAMUX_IN_TIM2_TRIG, DMAMUX_IN_TIM2_UP,
	DMAMUX_IN_TIM3_CH1, DMAMUX_IN_TIM3_CH2, DMAMUX_IN_TIM3_CH3, DMAMUX_IN_TIM3_CH4,
	DMAMUX_IN_TIM3_TRIG, DMAMUX_IN_TIM3_UP,
	DMAMUX_IN_TIM6_UP, DMAMUX_IN_TIM7_UP,
	DMAMUX_IN_TIM15_CH1, DMAMUX_IN_TIM15_CH2,
	DMAMUX_IN_TIM15_TRIG_COM, DMAMUX_IN_TIM15_UP,
	DMAMUX_IN_TIM16_CH1, DMAMUX_IN_TIM16_COM, DMAMUX_IN_TIM16_UP,
	DMAMUX_IN_TIM17_CH1, DMAMUX_IN_TIM17_COM, DMAMUX_IN_TIM17_UP,
	DMAMUX_IN_USART1_RX = 50, DMAMUX_IN_USART1_TX, DMAMUX_IN_USART2_RX, DMAMUX_IN_USART2_TX,
#if 0
// G0 series stuff - verify then enable
	DMAMUX_IN_USART3_RX, DMAMUX_IN_USART3_TX, DMAMUX_IN_USART4_RX, DMAMUX_IN_USART4_TX,

	DMAMUX_IN_LPUART2_RX = 64, DMAMUX_IN_LPUART2_TX,
	DMAMUX_IN_SPI3_RX, DMAMUX_IN_SPI3_TX,
	DMAMUX_IN_TIM4_CH1, DMAMUX_IN_TIM4_CH2, DMAMUX_IN_TIM4_CH3, DMAMUX_IN_TIM4_CH4,
	DMAMUX_IN_TIM4_TRIG, DMAMUX_IN_TIM4_UP,
	DMAMUX_IN_USART5_RX, DMAMUX_IN_USART5_TX, DMAMUX_IN_USART6_RX, DMAMUX_IN_USART6_TX,
#endif
};
// Flash =================================================================
#ifndef FLASH_PAGE_SIZE
#define FLASH_PAGE_SIZE	2048u
//#define FLASH_PG_SIZE	2048u
#endif

#define FLASH_SR_BSY	FLASH_SR_BSY1
#define FLASH_CR_PNBV(v)	((v) << FLASH_CR_PNB_Pos & FLASH_CR_PNB_Msk)
#define FLASH_UID	((const uint32_t *)UID_BASE)
// GPIO ==================================================================
#define GPIO_OSPEEDR_VLO	0	// 2 MHz
#define GPIO_OSPEEDR_LO	1u		// 10 MHz
#define GPIO_OSPEEDR_HI	2u		// 30 MHz
#define GPIO_OSPEEDR_VHI	3u	// 60 MHz

enum afn_ {AFN_SYS, AFN_USART1_2, AFN_TIM1, AFN_TIM2,
	AFN_USARTx, AFN_TIMx, AFN_I2C, AFN_EVTOUT,
};
// RCC GPIO enable =======================================================
#define IOENR	IOPENR	// IO port enable register alias
#define GPIOIDX(p)	(((uint8_t *)(p) - (uint8_t *)GPIOA) / ((uint8_t *)GPIOB - (uint8_t *)GPIOA))
#define RCC_IOENR_GPIOEN(p) ( (RCC_IOPENR_GPIOAEN) << GPIOIDX(p) )

#define RCC_CFGR_SW_HSISYS	0u
#define RCC_CFGR_SW_HSE		1u
#define RCC_CFGR_SW_HSIUSB	2u
#define RCC_CFGR_SW_LSI		3u
#define RCC_CFGR_SW_LSE		4u

#endif
