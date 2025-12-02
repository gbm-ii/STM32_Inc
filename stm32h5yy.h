/*
	STM32H5 series enhanced defs
	gbm 01'2024

	To be included instead of the original stm32h5xx.h.
*/

#ifndef __STM32H5YY_H
#define __STM32H5YY_H

#include <stdbool.h>
#include "stm32h5xx.h"

// Flash parameters
#define FLASH_PAGE_SIZE	FLASH_SECTOR_SIZE
#define	FLASH_FKEY1	0x45670123
#define	FLASH_FKEY2	0xCDEF89AB

#define BOOT_ADDR	0x0BF87000

// Default clock after reset
	// initial MCU clock after reset is HSI divided by 2 -> 32 MHz
	// BUT ST-supplied SystemInit resets the divisor, so the clock freq is 64 MHz!
#ifndef HSI_VALUE
#define HSI_VALUE	64000000u
#endif

#define	INIT_HCLK_FREQ	HSI_VALUE

// STM32H5x register/bit defs not present in stm32h5xx.h file
#define GPIO_OSPEEDR_LO	0	// 2 MHz
#define GPIO_OSPEEDR_MED	1u		// 10 MHz
#define GPIO_OSPEEDR_HI	2u		// 30 MHz
#define GPIO_OSPEEDR_VHI	3u	// 60 MHz

enum afn_ {AFN_SYS, AFN_TIM1_2, AFN_LPTIM1_TIM3, AFN_LPTIM2,
	AFN_USART1_2, AFN_SPI1, AFN_SPI2, AFN_SPI23_UART,
	AFN_I2C2, AFN_USART23, AFN_USB, AFN_I2C1,
	AFN_COMP, AFN_USART23x, AFN_TIM123, AFN_EVT};

#define RCC_CCIPR3_SPISEL_PER	4u

#define	RCC_PLLxCFGR_PLLxSRC_HSI	RCC_PLL1CFGR_PLL1SRC_0
#define	RCC_PLLxCFGR_PLLxSRC_HSE	RCC_PLL1CFGR_PLL1SRC

#define RCC_CFGR1_SW_PLL1	RCC_CFGR1_SW

#define IOENR	AHB2ENR	// IO port enable register alias

#define GPIOIDX(p)	(((uint8_t *)(p) - (uint8_t *)GPIOA) / ((uint8_t *)GPIOB - (uint8_t *)GPIOA))
#define RCC_IOENR_GPIOEN(p) ( (RCC_AHB2ENR_GPIOAEN) << GPIOIDX(p) )

#define PWR_CR_PLSV(a)	(((a) & 7) << 5)     /*!< Bit 0 */

// Calibration values stored in ROM
#define VREFINT_mV	3300u
#define VREFINT_CAL	(*(const uint16_t *)0x08fff810)	// @ 3.3V

// System ROM locations
#define T_CAL1	30
#define T_CAL2	130
#define TS_CAL1	(*(const uint16_t *)0x08fff814)	// @ 3.3V, 30 deg C
#define TS_CAL2	(*(const uint16_t *)0x08fff818)	// @ 3.3V, 130 deg C

#define ADCH_VBAT4	2u
#define ADCH_VDDCORE	6u
#define ADCH_VSENSE	16u
#define ADCH_VREFINT	17u

#define	ADC_SMPT_2_5	0u
#define	ADC_SMPT_6_5	1u
#define	ADC_SMPT_12_5	2u
#define	ADC_SMPT_24_5	3u
#define	ADC_SMPT_47_5	4u
#define	ADC_SMPT_92_5	5u
#define	ADC_SMPT_247_5	6u
#define	ADC_SMPT_640_5	7u

#define ADC_CCR_PRESC_DIV2	1u
#define ADC_CCR_PRESC_DIV4	2u
#define ADC_CCR_PRESC_DIV6	3u
#define ADC_CCR_PRESC_DIV8	4u
#define ADC_CCR_PRESC_DIV10	5u
#define ADC_CCR_PRESC_DIV12	6u
#define ADC_CCR_PRESC_DIV16	7u
#define ADC_CCR_PRESC_DIV32	8u
#define ADC_CCR_PRESC_DIV64	9u

enum gpdma_rq_ {DMARQ_ADC1, DMARQ_R1,
	DMARQ_DAC1CH1, DMARQ_DAC1CH2, DMARQ_TIM6_UPD, DMARQ_TIM7_UPD,
	DMARQ_SPI1_RX = 6, DMARQ_SPI1_TX, DMARQ_SPI2_RX, DMARQ_SPI2_TX, DMARQ_SPI3_RX, DMARQ_SPI3_TX,
	DMARQ_I2C1_RX, DMARQ_I2C1_TX, DMARQ_R14, DMARQ_I2C2_RX, DMARQ_I2C2_TX,
	DMARQ_USART1_RX = 21, DMARQ_USART1_TX, DMARQ_USART2_RX, DMARQ_USART2_TX, DMARQ_USART3_RX, DMARQ_USART3_TX,
	DMARQ_LPUART1_RX = 45, DMARQ_LPUART1_TX,
	DMARQ_TIM1_CC1 = 58, DMARQ_TIM1_CC2, DMARQ_TIM1_CC3, DMARQ_TIM1_CC4,
	DMARQ_TIM1_UPD, DMARQ_TIM1_TRG, DMARQ_TIM1_COM,
	DMARQ_TIM2_CC1 = 72, DMARQ_TIM2_CC2, DMARQ_TIM2_CC3, DMARQ_TIM2_CC4, DMARQ_TIM2_UPD,
	DMARQ_TIM3_CC1 = 72, DMARQ_TIM3_CC2, DMARQ_TIM3_CC3, DMARQ_TIM3_CC4, DMARQ_TIM3_UPD, DMARQ_TIM3_TRG,
};
enum gpdma_trig_ {GPDMA_TRIG_EXTI0, GPDMA_TRIG_EXTI1, GPDMA_TRIG_EXTI2, GPDMA_TRIG_EXTI3,
	GPDMA_TRIG_EXTI4, GPDMA_TRIG_EXTI5, GPDMA_TRIG_EXTI6, GPDMA_TRIG_EXTI7,
};

#define	DMA_CFCR_ALLF	(DMA_CFCR_TOF | DMA_CFCR_SUSPF | DMA_CFCR_USEF | DMA_CFCR_ULEF | DMA_CFCR_DTEF | DMA_CFCR_HTF | DMA_CFCR_TCF)

#define LPTIM_PRESC_64	6u
#define LPTIM_PRESC_128	7u

#define SPI_CFG1_MBR_DIV2	(0u << SPI_CFG1_MBR_Pos)
#define SPI_CFG1_MBR_DIV4	(1u << SPI_CFG1_MBR_Pos)
#define SPI_CFG1_MBR_DIV8	(2u << SPI_CFG1_MBR_Pos)
#define SPI_CFG1_MBR_DIV16	(3u << SPI_CFG1_MBR_Pos)
#define SPI_CFG1_MBR_DIV32	(4u << SPI_CFG1_MBR_Pos)
#define SPI_CFG1_MBR_DIV64	(5u << SPI_CFG1_MBR_Pos)
#define SPI_CFG1_MBR_DIV128	(6u << SPI_CFG1_MBR_Pos)
#define SPI_CFG1_MBR_DIV256	(7u << SPI_CFG1_MBR_Pos)

#define USART_PRESC_DIV1	0u
#define USART_PRESC_DIV2	1u
#define USART_PRESC_DIV4	2u
#define USART_PRESC_DIV6	3u
#define USART_PRESC_DIV8	4u
#define USART_PRESC_DIV10	5u
#define USART_PRESC_DIV12	6u
#define USART_PRESC_DIV16	7u
#define USART_PRESC_DIV32	8u
#define USART_PRESC_DIV64	9u
#define USART_PRESC_DIV128	10u
#define USART_PRESC_DIV256	11u

#include "stm32yyyy.h"	// add defs common to STM32 family
#include "stm32util.h"

#endif
