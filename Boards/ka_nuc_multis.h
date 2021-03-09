/*
	Kamami KA-Nucleo-Multisensor board defs
	gbm 12'2016
*/
#ifndef STM32N64COMP1_H_
#define STM32N64COMP1_H_
#include "stm32nucleo64.h"
//========================================================================
// CPX on PB6..9
#define CPX_PORT GPIOB
#define CPX_LED0_BIT 6
#define CPX_LED0_MSK (1u << CPX_LED0_BIT)
#define CPX_LED1_BIT 7
#define CPX_LED1_MSK (1u << CPX_LED1_BIT)
#define CPX_LED2_BIT 8
#define CPX_LED2_MSK (1u << CPX_LED2_BIT)
#define CPX_LED3_BIT 9
#define CPX_LED3_MSK (1u << CPX_LED3_BIT)

#define CPX_BSRR_OFF	((CPX_LED0_MSK | CPX_LED1_MSK | CPX_LED2_MSK | CPX_LED3_MSK) << 16)
#define CPX_MODER_OFF	(BF2A(CPX_LED0_BIT, GPIO_MODER_IN) & BF2A(CPX_LED1_BIT, GPIO_MODER_IN) \
	& BF2A(CPX_LED2_BIT, GPIO_MODER_IN) & BF2A(CPX_LED3_BIT, GPIO_MODER_IN))

// 4-digit, 7-segment display on PC0..11
#define LEDMpx_PORT	GPIOC

#define SEG_A_MSK (1u << 6)
#define SEG_B_MSK (1u << 4)
#define SEG_C_MSK (1u << 3)
#define SEG_D_MSK (1u << 1)
#define SEG_E_MSK (1u << 2)
#define SEG_F_MSK (1u << 5)
#define SEG_G_MSK (1u << 0)
#define SEG_DP_MSK (1u << 7)
#define SEG_MSK 0xffu

#define DIG0_MSK (1u << 8)
#define DIG1_MSK (1u << 9)
#define DIG2_MSK (1u << 10)
#define DIG3_MSK (1u << 11)
#define DIG_MSK (0xfu << 8)
#define LEDMpx_DigMask	DIG_MSK

#define COMMON_CATHODE
#ifdef COMMON_CATHODE	// CC, no amplifiers
#define SegActLevel	1
#define DigActLevel	0
#else	// CA, no amplifiers
#define SegActLevel	0
#define DigActLevel	1
#endif

// BSRR mask shift values
#define LEDMpx_SegOnShift	((!SegActLevel) * 16)
#define LEDMpx_SegOffShift	(SegActLevel * 16)
#define LEDMpx_DigOnShift	((!DigActLevel) * 16)
#define LEDMpx_DigOffShift	(DigActLevel * 16)

#define DigAct(x)	((x) << LEDMpx_DigOnShift | (DIG_MSK ^ (x)) << LEDMpx_DigOffShift)
#define SegAct(x)	((x) << LEDMpx_SegOnShift | (SEG_MSK ^ (x)) << LEDMpx_SegOffShift)

// OneWire - hardware control possible using TIM3CH1
#define OW_PORT	GPIOB
#define	OW_BIT	4
#define OW_MSK	(1u << OW_BIT)

// TWI(I2C) on PB10, PB11
//========================================================================
// SPI on PB3, PA4, PA6, PA7
#define LIS35_NSS_PORT	GPIOA
#define LIS35_NSS_BIT	4
#define LIS35_NSS_MSK	(1u << LIS35_NSS_BIT)
#define LIS35_SPI	SPI1
//========================================================================

// tact switches on PB0, PB5
#define KEY_PORT	GPIOB
#define KEYL_BIT	0
#define KEYR_BIT	5

#define KEYL_DOWN	(~KEY_PORT->IDR >> KEYL_BIT & 1)
#define KEYR_DOWN	(~KEY_PORT->IDR >> KEYR_BIT & 1)

// LDR on PA1
#define LDR_BIT	1
#define ADCH_LDR	6

//========================================================================
#endif
