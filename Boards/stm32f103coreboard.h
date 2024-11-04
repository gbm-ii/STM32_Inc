/*
	STM32F103 Core Board defs
	(Chinese black board with nRF24L01, ESP8266 connectors and some other stuff
	gbm 06'2019
*/
#ifndef STM32CORE_H_
#define STM32CORE_H_
// Button ================================================================
#define BTN_PORT	GPIOA
#define BTN_BIT		8
#define BTN_MSK	(1u << BTN_BIT)
#define BTN_DOWN	(~BTN_PORT->IDR >> BTN_BIT & 1)
// LED ===================================================================
#define LED_PORT	GPIOA
#define LED_BIT	1	// active LOW
#define LED_MSK	(1u << LED_BIT)
#define LED_TIM	TIM2
#define LED_TIM_IRQn	TIM2_IRQn
#define LED_DUTY	TIM2->CCR2
#define LED_ON	(LED_PORT->BRR = LED_MSK)
#define LED_OFF	(LED_PORT->BSRR = LED_MSK)
// nRF24L01 ==============================================================
// PA5, 6, 7 - SCK, MISO, MOSI
#define NRF24_NSS_PORT	GPIOB
#define NRF24_NSS_BIT	2
#define NRF24_CE_PORT	GPIOB
#define NRF24_CE_BIT	0
#define NRF24_NIRQ_PORT	GPIOA
#define NRF24_NIRQ_BIT	15
#define NRF24_SPI	SPI1
#define	NRF_SPI_RX_DMACH DMA1_Channel2
#define	NRF_SPI_TX_DMACH DMA1_Channel3

#define NRF24_NSS_MSK	(1u << NRF24_NSS_BIT)
#define NRF24_CE_MSK	(1u << NRF24_CE_BIT)
#define NRF24_NIRQ_MSK	(1u << NRF24_NIRQ_BIT)
// I2C EEPROM ============================================================
// PB4 - SCL, PB6 - SDA bit banged
// SPI Flash =============================================================
// PA5, 6, 7 - SCK, MISO, MOSI - same as nRF24L01
#define SF_NSS_PORT	GPIOC
#define SF_NSS_BIT	13
#define SF_NSS_MSK	(1u << SF_NSS_BIT)
// UARTS: 1 - PA9/PA10 or PB6/PB7, 2 - PA2/PA3 - ESP8266, 3 - PB10/PB11
//========================================================================
#endif
