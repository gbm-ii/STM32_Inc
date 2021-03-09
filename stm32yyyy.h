/*
	STM32F series common enhanced defs
	gbm 09'2014

	Should be included after stm32fXxx.h.
*/

#ifndef __STM32YYYY_H
#define __STM32YYYY_H

typedef __IO uint32_t * __IO32p;	// short type name
//========================================================================
// STM32Fxxx register/bit defs not present in stm32fxxx.h file
#undef SCB_AIRCR_VECTKEY	// some F10x.h files contain key mask definition instead of key value
#define SCB_AIRCR_VECTKEY	0x05fa0000

#define RCC_CFGR_PLLMULV(a)	(((a - 2) & 0xf) << 18)

#define CRS_CFGR_SYNCSRC_LSE	CRS_CFGR_SYNCSRC_0
#define CRS_CFGR_SYNCSRC_USB	CRS_CFGR_SYNCSRC_1

#define GPIO_MODER_IN	0u
#define GPIO_MODER_OUT	1u
#define GPIO_MODER_AF	2u
#define GPIO_MODER_AN	3u

#define GPIO_MODE_IN(p)	(0u << (p)*2)
#define GPIO_MODE_OUT(p)	(1u << (p)*2)
#define GPIO_MODE_AF(p)	(2u << (p)*2)
#define GPIO_MODE_AN(p)	(3u << (p)*2)

#define GPIO_PUPDR_PU	1u
#define GPIO_PUPDR_PD	2u

#define GPIO_OSPEEDR_LOW	0
#define GPIO_OSPEEDR_MED	1u
#define GPIO_OSPEEDR_FAST	2u
#define GPIO_OSPEEDR_HI	3u

// GPIOA settings for 2-wire SWD
#define SWCLK_BIT	14
#define SWDIO_BIT	13
#define GPIOA_MODER_SWD	(BF2(SWCLK_BIT, GPIO_MODER_AF) | BF2(SWDIO_BIT, GPIO_MODER_AF)) // keep SWD pins only
#define GPIOA_MODER_SWDA	(BF2(SWCLK_BIT, GPIO_MODER_AF) | BF2(SWDIO_BIT, GPIO_MODER_AF) | 0xc3ffffffu) // keep SWD pins only
#define GPIOA_PUPDR_SWD	(BF2(SWCLK_BIT, GPIO_PUPDR_PD) | BF2(SWDIO_BIT, GPIO_PUPDR_PU)) // SWD CLK->PD, DIO->PU
#define GPIOA_OSPEEDR_SWD	(BF2(SWDIO_BIT, GPIO_OSPEEDR_HI))	// SWDIO

#define  PWR_CR_PLSV(a)	(((a) & 7) << 5)

#define DMA_CCR_MSIZE16	DMA_CCR_MSIZE_0
#define DMA_CCR_MSIZE32	DMA_CCR_MSIZE_1
#define DMA_CCR_PSIZE16	DMA_CCR_PSIZE_0
#define DMA_CCR_PSIZE32	DMA_CCR_PSIZE_1
#define DMA_CCR_DIR_P2M	0
#define DMA_CCR_DIR_M2P	DMA_CCR_DIR

#define TIM_CCMR1_OC1M_PWM1	0x0060	// OC1M[2:0] - PWM mode 1
#define TIM_CCMR1_OC2M_PWM1	0x6000	// OC2M[2:0] - PWM mode 1
#define TIM_CCMR2_OC3M_PWM1	0x0060	// OC3M[2:0] - PWM mode 1
#define TIM_CCMR2_OC4M_PWM1	0x6000	// OC4M[2:0] - PWM mode 1

#define SPI_CR1_BRSEL(s) ((s) << 3)
#define SPI_CR1_BRDIV2	SPI_CR1_BRSEL(0)
#define SPI_CR1_BRDIV4	SPI_CR1_BRSEL(1)
#define SPI_CR1_BRDIV8	SPI_CR1_BRSEL(2)
#define SPI_CR1_BRDIV16	SPI_CR1_BRSEL(3)
#define SPI_CR1_BRDIV32	SPI_CR1_BRSEL(4)
#define SPI_CR1_BRDIV64	SPI_CR1_BRSEL(5)
#ifndef	SPI_CR1_DFF
#define SPI_CR2_DSIZE(s) (((s) - 1) << 8)
#endif

// byte access to SPI DR - MUST be __IO (= volatile)!
#define SPI1_DRB	(*(__IO uint8_t *)&SPI1->DR)
#define SPI2_DRB	(*(__IO uint8_t *)&SPI2->DR)
#define QUADSPI_DRB	(*(__IO uint8_t *)&QUADSPI->DR)

#ifndef FLASH_FKEY1
// defs missing from some device-specific files
#define	FLASH_FKEY1	0x45670123
#define	FLASH_FKEY2	0xCDEF89AB
#endif

#define	EXTI_MR_PVD EXTI_RTSR_TR16

#endif
