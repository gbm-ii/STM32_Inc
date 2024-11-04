/*
 * STM32F103BluePill.h
 *
 *  Created on: 12 gru 2020
 *      Author: gbm
 */

#ifndef INC_F103BLUEPILL_H_
#define INC_F103BLUEPILL_H_

#ifdef BLUEPILLPLUS

// Button ================================================================
#define BTN_PORT	GPIOA
#define BTN_BIT		0
#define BTN_MSK	(1u << BTN_BIT)
#define BTN_DOWN	(BTN_PORT->IDR >> BTN_BIT & 1)	// active high
// LED ===================================================================
#define LED_PORT	GPIOB
#define LED_BIT	2	// active HIGH
#define LED_ACTIVE_LEVEL	1
#define LED_ON_BSR	BSRR
#define LED_OFF_BSR	BRR

#else	// BluePill Classic

#define BTN_PORT	GPIOB
#define BTN_BIT		2
#define BTN_MSK	(1u << BTN_BIT)
#define BTN_DOWN	(~BTN_PORT->IDR >> BTN_BIT & 1)
// LED ===================================================================
#define LED_PORT	GPIOC
#define LED_BIT	13	// active LOW
#define LED_ACTIVE_LEVEL	0
#define LED_ON_BSR	BRR
#define LED_OFF_BSR	BSRR
#endif

#define LED_MSK	(1u << LED_BIT)
#define LED_ON	(LED_PORT->LED_ON_BSR = LED_MSK)
#define LED_OFF	(LED_PORT->LED_OFF_BSR = LED_MSK)

#define LED_DUTY	TIM2->CCR2
#define LED_TIM	TIM2

#endif /* INC_F103BLUEPILLPLUS_H_ */
