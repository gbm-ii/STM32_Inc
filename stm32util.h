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
// bit fields to be ANDed (for STM32L/H/G/U series MODER)
#define BF2A(b,v)	((uint32_t)(v) << (((b) & 0xf) * 2) | ~(3u << (((b) & 0xf) * 2)))
#define BF4A(b,v)	((uint32_t)(v) << (((b) & 7) * 4) | ~(0xfu << (((b) & 7) * 4)))

#define BRR(v)	((v) << 16)	// Bit reset mask for BSRR
#define SETLOW(p,b)	((p)->BRR = 1 << (b))
#define SETHIGH(p,b)	((p)->BSRR = 1 << (b))
#define GETPIN(p,b)	((p)->IDR >> (b) & 1)
//========================================================================
#define IRQn(n)	(n##_IRQn)
#define IRQHandler(n)	(n##_IRQHandler)
// UART BRR register value calc ==========================================
static inline uint16_t BRR_value(uint32_t uart_clk, uint32_t baudrate)
{
	uint16_t brr = (uart_clk + baudrate / 2) / baudrate;
	if (brr < 16u)
		brr = 16u;
	else if (brr > 0xfff7)
		brr = 0xfff7;		// undocumented! - the maximum valid BRR value
	return brr;
}
// GPIO utilities ========================================================
#ifdef IOENR
static inline void GPIO_PortEnable(GPIO_TypeDef *port)
{
	RCC->IOENR |= RCC_IOENR_GPIOEN(port);
}
#endif
static inline void GPIO_PinToggle(GPIO_TypeDef *port, uint16_t mask)
{
	port->BSRR = mask << 16 | (~port->ODR & mask);
}
// TIM ===================================================================
static inline void TIM_encoder_init(TIM_TypeDef *tim)
{
	tim->SMCR = 1u << TIM_SMCR_SMS_Pos;
	tim->CCMR1 = 0
		| 15u << TIM_CCMR1_IC1F_Pos | TIM_CCMR1_CC1S_0
		| 15u << TIM_CCMR1_IC2F_Pos | TIM_CCMR1_CC2S_0;
	tim->CCER = TIM_CCER_CC1E | TIM_CCER_CC2E;
	tim->CR1 = 2u << TIM_CR1_CKD_Pos | TIM_CR1_CEN;
}
// deprecated stuff ======================================================
// register init structure and routine
struct init_entry_ {
	volatile uint32_t *loc;
	uint32_t value;
};

static inline void writeregs(const struct init_entry_ *p)
{
	for (; p->loc; p ++)
		*p->loc = p->value;
}
//========================================================================
#endif
