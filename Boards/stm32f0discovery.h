/*
	STM32F0DISCOVERY, STM32F0308-DISCO & STM32F072B-DISCO board defs
	gbm 05'2014
*/

#include "stm32f0yy.h"
#include "stm32util.h"
//========================================================================

#define BOARDNAME	"Discovery"
// STM32F0DISCOVERY board conections
#define BTN_PORT		GPIOA
#define BTN_BIT		0
#define BTN_DOWN	(BTN_PORT->IDR >> BTN_BIT & 1)
#define BTN_PULL	GPIO_PUPDR_PD

#define LED_PORT		GPIOC
#define LED_ACTIVE_LEVEL	1

#ifdef STM32F072xB
// LEDs - F072B
#define LED_U_BIT	6	// red
#define LED_D_BIT	7	// blue
#define LED_L_BIT	8	// orange
#define LED_R_BIT	9	// green

#define RED_LED_BIT	LED_U_BIT
#define BLUE_LED_BIT	LED_D_BIT
#define ORANGE_LED_BIT	LED_L_BIT
#define GREEN_LED_BIT	LED_R_BIT

#define LED_U_DUTY	TIM3->CCR1
#define LED_D_DUTY	TIM3->CCR2
#define LED_L_DUTY	TIM3->CCR3
#define LED_R_DUTY	TIM3->CCR4

#define RED_LED_DUTY	LED_U_DUTY
#define BLUE_LED_DUTY	LED_D_DUTY
#define ORANGE_LED_DUTY	LED_L_DUTY
#define GREEN_LED_DUTY	LED_R_DUTY

#define RED_LED_MSK	(1 << RED_LED_BIT)
#define ORANGE_LED_MSK	(1 << ORANGE_LED_BIT)

// F072B touch
#define TSC_CAPS	(1 << 10 | 1 << 7 | 1 << 3)
#define TSC_KEYS	(1 << 9 | 1 << 6 | 1 << 2)

#else
// LEDs - F0, F0308
#define BLUE_LED_BIT	8
#define GREEN_LED_BIT	9
#define BLUE_LED_DUTY	TIM3->CCR3
#define GREEN_LED_DUTY	TIM3->CCR4

#endif

#define BLUE_LED_MSK	(1 << BLUE_LED_BIT)
#define GREEN_LED_MSK	(1 << GREEN_LED_BIT)
	
#define LED_BIT	BLUE_LED_BIT
#define LED_MSK		BLUE_LED_MSK
//========================================================================
#ifdef PLLMUL
#define SYSCLK_FREQ	(HSI_VALUE * PLLMUL / 2)
#else
#define SYSCLK_FREQ	(HSI_VALUE)
#endif
