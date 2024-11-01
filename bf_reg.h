/*
 * gal_reg.h
 *  bit field definitions and utility functions for peripheral config register access
 *
 *  Created on: 9.11.2022
 *      Author: gbm
 */

#ifndef INC_BF_REG_H_
#define INC_BF_REG_H_

#include <stdint.h>

union bf2_ {
	struct {
		uint32_t p0:2, p1:2, p2:2, p3:2, p4:2, p5:2, p6:2, p7:2,
			p8:2, p9:2, p10:2, p11:2, p12:2, p13:2, p14:2, p15:2;
	};
	uint32_t w;
};

union bf4_ {
	struct {
		uint32_t p0:4, p1:4, p2:4, p3:4, p4:4, p5:4, p6:4, p7:4;
	};
	struct {
		uint32_t p8:4, p9:4, p10:4, p11:4, p12:4, p13:4, p14:4, p15:4;
	};
	uint32_t w;
};

union bf4u_ {
	struct {
		uint32_t p8:4, p9:4, p10:4, p11:4, p12:4, p13:4, p14:4, p15:4;
	};
	uint32_t w;
};

union bf4d_ {
	struct {
		uint32_t p0:4, p1:4, p2:4, p3:4, p4:4, p5:4, p6:4, p7:4;
		uint32_t p8:4, p9:4, p10:4, p11:4, p12:4, p13:4, p14:4, p15:4;
	};
	uint64_t d;
};

#define PIN(b)	p##b

#define BF2_(a)	(*(volatile union bf2_ *)&(a))
#define BF2F(a,b) (*(volatile union bf2_ *)&(a)).PIN(b)
#define BF4_(a)	(*(volatile union bf4_ *)&(a))
#define BF4F(a,b) (*(volatile union bf4_ *)&(a)).PIN(b)

// AFR register access
#define AFRF(p,b) (((volatile union bf4_ *)(p->AFR))[(b) / 8]).PIN(b)
// CRL/CRH register access for STM32F1
#define CRF(p,b) (((volatile union bf4_ *)&(p->CRL))[(b) / 8]).PIN(b)


union dma_cselr_ {
	struct {
		uint32_t c1s:4, c2s:4, c3s:4, c4s:4, c5s:4, c6s:4, c7s:4;
	};
	uint32_t w;
};

union adc_smpr_ {
	struct {
		uint32_t smp0:3, smp1:3, smp2:3, smp3:3, smp4:3,
			smp5:3, smp6:3, smp7:3, smp8:3, smp9:3, rsvd:1, smpplus:1;
	};
	struct {
		uint32_t smp10:3, smp11:3, smp12:3, smp13:3, smp14:3,
			smp15:3, smp16:3, smp17:3, smp18:3, smp19:3;
	};
	uint32_t w;
};

static inline void gREG_Modify(volatile uint32_t *reg, uint32_t mask, uint32_t val)
{
	*reg = (*reg & mask) | val;
}

static inline void gREG_Modify64(volatile uint64_t *reg, uint64_t mask, uint64_t val)
{
	*reg = (*reg & mask) | val;
}

#define MOD2	3u
#define MOD4	0xfu

#define gREGMOD(reg, mask, val)	( *(reg) = (*(reg) & (mask)) | (val) )
#define REG64(rp)	(*(volatile uint64_t *)(rp))

#endif /* INC_BF_REG_H_ */
