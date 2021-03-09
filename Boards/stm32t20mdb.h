/*
	STM32x0 TSSOP20 mini dev board by gbm
	gbm 07'2016
*/
//========================================================================
#define LED_PORT		GPIOB
#define LED_BIT	1
#define LED_MSK	(1u << LED_BIT)

#define LED_DUTY	TIM14->CCR1
//========================================================================
