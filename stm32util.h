/*
	some useful defs for STM32
	gbm 11'2015
*/
#ifndef __STM32UTIL_H
#define __STM32UTIL_H

#define WEAK __attribute__ ((weak))
// bit fields to be ORed
#define BF2(b,v)	((uint32_t)(v) << (((b) & 0xf) * 2))
#define BF3(b,v)	((uint32_t)(v) << (((b) % 10) * 3))
#define BF4(b,v)	((uint32_t)(v) << (((b) & 7) * 4))
#define BF5(b,v)	((uint32_t)(v) << (((b) % 6) * 5))
#define BF6(b,v)	((uint32_t)(v) << (((b) % 5) * 6))
#define BF8(b,v)	((uint32_t)(v) << (((b) & 3) * 8))
// bit fields to be ANDed (for STM32L series MODER)
#define BF2A(b,v)	((uint32_t)(v) << (((b) & 0xf) * 2) | ~(3u << (((b) & 0xf) * 2)))
#define BF4A(b,v)	((uint32_t)(v) << (((b) & 7) * 4) | ~(0xfu << (((b) & 7) * 4)))

#define BRR(v)	((v) << 16)	// Bit reset mask for BSRR
#define SETLOW(p,b)	((p)->BRR = 1 << (b))
#define SETHIGH(p,b)	((p)->BSRR = 1 << (b))
#define GETPIN(p,b)	((p)->IDR >> (b) & 1)
//========================================================================
#define IRQn(n)	(n##_IRQn)
#define IRQHandler(n)	(n##_IRQHandler)
//========================================================================
// register init structure and routine
struct init_entry_ {
	volatile uint32_t *loc;
	uint32_t value;
};

static __INLINE void writeregs(const struct init_entry_ *p)
{
	for (; p->loc; p ++)
		*p->loc = p->value;
}
//========================================================================
#endif
