/*
	Common basic GPIO port utilities for STM32
	gbm 03'2026
*/
#ifndef STM32GPIOUTIL_H_
#define STM32GPIOUTIL_H_
//========================================================================
#include <stdbool.h>
// GPIO utilities ========================================================
#ifdef IOENR	// IO enable register defined in series-specific header
static inline void GPIO_PortEnable(GPIO_TypeDef *port)
{
	RCC->IOENR |= RCC_IOENR_GPIOEN(port);
}
#if 0	// todo def USB_OTG_FS_PERIPH_BASE	// F4, L4 series
// USB peripheral pin configuration
static inline void USB_OTG_FS_PinSetup(void)
{
	RCC->IOENR |= RCC_IOENR_GPIOEN(GPIOA);
	AFRF(GPIOA, 11) = AFN_USB;
	AFRF(GPIOA, 12) = AFN_USB;
	BF2F(GPIOA->OSPEEDR, 11) = GPIO_OSPEEDR_HI;
	BF2F(GPIOA->OSPEEDR, 12) = GPIO_OSPEEDR_HI;
	BF2F(GPIOA->MODER, 11) = GPIO_MODER_AF;
	BF2F(GPIOA->MODER, 12) = GPIO_MODER_AF;
}
#endif

// board LED/Button setup

static inline void LED_Setup(void)
{
#ifdef LED_PORT
	RCC->IOENR |= RCC_IOENR_GPIOEN(LED_PORT);
#ifdef GPIO_CR_OPP_S	// F1 series
	CRF(LED_PORT, LED_BIT) = GPIO_CR_OPP_S;
#else	// all other series with MODER register
	BF2F(LED_PORT->MODER, LED_BIT) = GPIO_MODER_OUT;
#endif
#endif
}

static inline void Btn_Setup(void)
{
#ifdef BTN_PORT
	RCC->IOENR |= RCC_IOENR_GPIOEN(BTN_PORT);
#ifdef GPIO_CR_INP	// F1 series
	CRF(BTN_PORT, BTN_BIT) = GPIO_CR_INP;
	BTN_PORT->BRR = BTN_MSK;	// pull down for BluePillPlus
#else	// all other series with MODER register
	BF2F(BTN_PORT->PUPDR, BTN_BIT) = BTN_PULL;
	BF2F(BTN_PORT->MODER, BTN_BIT) = GPIO_MODER_IN;
#endif
#endif
}

static inline void LED_Btn_Setup(void)
{
	LED_Setup();
	Btn_Setup();
}

#endif	// IO utilities

static inline void hwLED_Set(bool on)
{
#ifdef LED_PORT
	LED_PORT->BSRR = on ^ !LED_ACTIVE_LEVEL ? LED_MSK : LED_MSK << 16;
#endif
}

// STM32 optimal toggle routine for replacing broken HAL_GPIO_PinToggle()
static inline void GPIO_PinToggle(GPIO_TypeDef *port, uint16_t mask)
{
	port->BSRR = mask << 16 | (~port->ODR & mask);
}

//========================================================================
#endif
