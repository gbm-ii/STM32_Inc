/*
	STM32F10x series enhanced defs
	gbm 01'2016
*/

#ifndef __STM32F10Y_H
#define __STM32F10Y_H

#include "stm32f10x.h"
#include "stm32yyyy.h"
#include "stm32util.h"

// STM32F10x register/bit defs not present in stm32f1xx.h file

#define RCC_AHBENR_RSTVAL	(RCC_AHBENR_FLITFEN | RCC_AHBENR_SRAMEN)

#define RCC_IOENR_GPIOEN(p) ( (RCC_APB2ENR_IOPAEN) << GPIOIDX(p) )

// copied from F0 header to avoid CCRx
#ifndef DMA_CCR_EN
/*******************  Bit definition for DMA_CCR register  ********************/
#define  DMA_CCR_EN                          ((uint32_t)0x00000001)        /*!< Channel enable                      */
#define  DMA_CCR_TCIE                        ((uint32_t)0x00000002)        /*!< Transfer complete interrupt enable  */
#define  DMA_CCR_HTIE                        ((uint32_t)0x00000004)        /*!< Half Transfer interrupt enable      */
#define  DMA_CCR_TEIE                        ((uint32_t)0x00000008)        /*!< Transfer error interrupt enable     */
#define  DMA_CCR_DIR                         ((uint32_t)0x00000010)        /*!< Data transfer direction             */
#define  DMA_CCR_CIRC                        ((uint32_t)0x00000020)        /*!< Circular mode                       */
#define  DMA_CCR_PINC                        ((uint32_t)0x00000040)        /*!< Peripheral increment mode           */
#define  DMA_CCR_MINC                        ((uint32_t)0x00000080)        /*!< Memory increment mode               */

#define  DMA_CCR_PSIZE                       ((uint32_t)0x00000300)        /*!< PSIZE[1:0] bits (Peripheral size)   */
#define  DMA_CCR_PSIZE_0                     ((uint32_t)0x00000100)        /*!< Bit 0                               */
#define  DMA_CCR_PSIZE_1                     ((uint32_t)0x00000200)        /*!< Bit 1                               */

#define  DMA_CCR_MSIZE                       ((uint32_t)0x00000C00)        /*!< MSIZE[1:0] bits (Memory size)       */
#define  DMA_CCR_MSIZE_0                     ((uint32_t)0x00000400)        /*!< Bit 0                               */
#define  DMA_CCR_MSIZE_1                     ((uint32_t)0x00000800)        /*!< Bit 1                               */

#define  DMA_CCR_PL                          ((uint32_t)0x00003000)        /*!< PL[1:0] bits(Channel Priority level)*/
#define  DMA_CCR_PL_0                        ((uint32_t)0x00001000)        /*!< Bit 0                               */
#define  DMA_CCR_PL_1                        ((uint32_t)0x00002000)        /*!< Bit 1                               */

#define  DMA_CCR_MEM2MEM                     ((uint32_t)0x00004000)        /*!< Memory to memory mode               */
#endif
//========================================================================
//#define GPIO_CR_MODE_IN	0u
//#define GPIO_CR_MODE_OUTS	1u
//#define GPIO_CR_MODE_OUTM	2u
//#define GPIO_CR_MODE_OUTF	3u

//#define GPIO_CR_CNF_AN	0u	// analog
//#define GPIO_CR_CNF_FIN	4u	// floating in
//#define GPIO_CR_CNF_PIN	8u	// push/pull in
//#define GPIO_CR_CNF_OD	4u	// OD output
//#define GPIO_CR_CNF_AFPP	8u	// AF output
//#define GPIO_CR_CNF_AFOD	0xc	// AF OD output

enum gpio_crval_ {
	GPIO_CR_AN,		// analog
	GPIO_CR_OPP_M,	// 0x1	// GPIO push-pull output slow
	GPIO_CR_OPP_S,	// 0x2	// GPIO push-pull output med
	GPIO_CR_OPP_F,	// 0x3	// GPIO push-pull output fast
	GPIO_CR_INF,	//	4	// floating in
	GPIO_CR_OOD_M,	//	0x5	// GPIO OD output slow
	GPIO_CR_OOD_S,	//	0x6	// GPIO OD output med
	GPIO_CR_OOD_F,	//	0x7	// GPIO OD output fast
	GPIO_CR_INP,	//	8	// push/pull in
	GPIO_CR_AFPP_M,	//	0x9	// AF output slow
	GPIO_CR_AFPP_S,	//	0xa	// AF output med
	GPIO_CR_AFPP_F,	//	0xb	// AF output fast
	GPIO_CR_INR,	// input reserved
	GPIO_CR_AFOD_M,	//	0xd	// AF OD output slow
	GPIO_CR_AFOD_S,	//	0xe	// AF OD output med
	GPIO_CR_AFOD_F	//	0xf	// AF OD output fast
};

union gpio_crl_ {
	uint32_t cr;
	struct {
		//enum gpio_crval_
		uint8_t
			p0:4, p1:4, p2:4, p3:4, p4:4, p5:4, p6:4, p7:4;
	};
};

union gpio_crh_ {
	uint32_t cr;
	struct {
		//enum gpio_crval_
		uint8_t
		p8:4, p9:4, p10:4, p11:4, p12:4, p13:4, p14:4, p15:4;
	};
};

union gpio_cr_ {
	uint64_t crd;
	uint32_t cr[2];
	struct {
		//enum gpio_crval_
		uint8_t
			p0:4, p1:4, p2:4, p3:4, p4:4, p5:4, p6:4, p7:4,
			p8:4, p9:4, p10:4, p11:4, p12:4, p13:4, p14:4, p15:4;
	};
};

#define	AFIO_MAPR_SWD	(2u << 24)	// SWD only, no JTAG

#define ADC_SMPT_28_5	3u
#define ADC_SMPT_41_5	4u
#define ADC_SMPT_55_5	5u
#define ADC_SMPT_71_5	6u
#define ADC_SMPT_239_5	7u	// 17 us @ 14 MHz - for TS

// Calibration values stored in ROM
#define VREFINT_CAL	(*(uint16_t *)0x1ffff7ba)
#define TS_CAL1	(*(uint16_t *)0x1ffff7b8)
#define TS_CAL2	(*(uint16_t *)0x1ffff7c2)

#define T_CAL1	30
#define T_CAL2	110

#endif
