/*
 * Nucleo64 Arduino port mapping
 * gbm 12'16
 */

// Arduino connectors pin mapping
#define AR_D0_PORT	GPIOA
#define	AR_D0_BIT	3
#define AR_D1_PORT	GPIOA
#define	AR_D1_BIT	2
#define AR_D2_PORT	GPIOA
#define	AR_D2_BIT	10
#define AR_D3_PORT	GPIOB
#define	AR_D3_BIT	3
#define AR_D4_PORT	GPIOB
#define	AR_D4_BIT	5
#define AR_D5_PORT	GPIOB
#define	AR_D5_BIT	4
#define AR_D6_PORT	GPIOB
#define	AR_D6_BIT	10
#define AR_D7_PORT	GPIOA
#define	AR_D7_BIT	8

#define AR_D8_PORT	GPIOA
#define	AR_D8_BIT	9
#define AR_D9_PORT	GPIOC
#define	AR_D9_BIT	7
#define AR_D10_PORT	GPIOB
#define	AR_D10_BIT	6
#define AR_D11_PORT	GPIOA
#define	AR_D11_BIT	7
#define AR_D12_PORT	GPIOA
#define	AR_D12_BIT	6
#define AR_D13_PORT	GPIOA
#define	AR_D13_BIT	5
#define AR_D14_PORT	GPIOB
#define	AR_D14_BIT	9
#define AR_D15_PORT	GPIOB
#define	AR_D15_BIT	8

#define AR_D10_DUTY	TIM4->CCR1
#define AR_D11_DUTY	TIM3->CCR2
#define AR_D12_DUTY	TIM3->CCR1
#define AR_D13_DUTY	TIM2->CCR1

#define AR_A0_PORT	GPIOA
#define	AR_A0_BIT	0
#define AR_A1_PORT	GPIOA
#define	AR_A1_BIT	1
#define AR_A2_PORT	GPIOA
#define	AR_A2_BIT	4
#define AR_A3_PORT	GPIOB
#define	AR_A3_BIT	0
#define AR_A4_PORT	GPIOC
#define	AR_A4_BIT	1
#define AR_A5_PORT	GPIOC
#define	AR_A5_BIT	0

#define AR_D0_MASK	(1 << AR_D0_BIT)
#define AR_D1_MASK	(1 << AR_D1_BIT)
#define AR_D2_MASK	(1 << AR_D2_BIT)
#define AR_D3_MASK	(1 << AR_D3_BIT)
#define AR_D4_MASK	(1 << AR_D4_BIT)
#define AR_D5_MASK	(1 << AR_D5_BIT)
#define AR_D6_MASK	(1 << AR_D6_BIT)
#define AR_D7_MASK	(1 << AR_D7_BIT)
#define AR_D8_MASK	(1 << AR_D8_BIT)
#define AR_D9_MASK	(1 << AR_D9_BIT)
#define AR_D10_MASK	(1 << AR_D10_BIT)
#define AR_D11_MASK	(1 << AR_D11_BIT)
#define AR_D12_MASK	(1 << AR_D12_BIT)
#define AR_D13_MASK	(1 << AR_D13_BIT)
#define AR_D14_MASK	(1 << AR_D14_BIT)
#define AR_D15_MASK	(1 << AR_D15_BIT)

#define AR_A0_MASK	(1 << AR_A0_BIT)
#define AR_A1_MASK	(1 << AR_A1_BIT)
#define AR_A2_MASK	(1 << AR_A2_BIT)
#define AR_A3_MASK	(1 << AR_A3_BIT)
#define AR_A4_MASK	(1 << AR_A4_BIT)
#define AR_A5_MASK	(1 << AR_A5_BIT)

#define AR_D_GPIOA_MASK (1u << AR_D2_BIT | 1u << AR_D7_BIT | 1u << AR_D8_BIT | 1u << AR_D11_BIT | 1u << AR_D12_BIT | 1u << AR_D13_BIT)
#define AR_D_GPIOB_MASK (1u << AR_D3_BIT | 1u << AR_D4_BIT | 1u << AR_D5_BIT | 1u << AR_D6_BIT | 1u << AR_D10_BIT)
#define AR_D_GPIOC_MASK (1u << AR_D9_BIT)

#define GPIOA_MODER_USART
#define GPIOB_MODER_AR_I2C
#define GPIOB_AFR1_AR_I2C

// AVT1615
// LCD R/-W short to GND
#define LCD_D4_PORT	AR_D4_PORT
#define LCD_D4_BIT	AR_D4_BIT
#define LCD_D5_PORT	AR_D5_PORT
#define LCD_D5_BIT	AR_D5_BIT
#define LCD_D6_PORT	AR_D6_PORT
#define LCD_D6_BIT	AR_D6_BIT
#define LCD_D7_PORT	AR_D7_PORT
#define LCD_D7_BIT	AR_D7_BIT

#define LCD_RS_PORT	AR_D8_PORT
#define LCD_RS_BIT	AR_D8_BIT
#define LCD_E_PORT	AR_D9_PORT
#define LCD_E_BIT	AR_D9_BIT

#define LCD_E_MSK	(1u << LCD_E_BIT)
#define LCD_RS_MSK	(1u << LCD_RS_BIT)

#define LCD_E_SET	LCD_E_PORT->BSRR = LCD_E_MSK
#define LCD_E_CLR	LCD_E_PORT->BSRR = (LCD_E_MSK << 16)
#define LCD_RS_SET	LCD_RS_PORT->BSRR = LCD_RS_MSK
#define LCD_RS_CLR	LCD_RS_PORT->BSRR = (LCD_RS_MSK << 16)

#define LCD_DATA_OUT(v)	(LCD_D4_PORT->BSRR = (1u << 16 | (v & 1u)) << LCD_D4_BIT);\
			(LCD_D5_PORT->BSRR = (1u << 16 | (v >> 1 & 1u)) << LCD_D5_BIT);\
			(LCD_D6_PORT->BSRR = (1u << 16 | (v >> 2 & 1u)) << LCD_D6_BIT);\
			(LCD_D7_PORT->BSRR = (1u << 16 | (v >> 3 & 1u)) << LCD_D7_BIT);

#define DLY_5MS		5

#define LCD_DLY_tAS	// from RS to E rising - 40 ns, 250 ns from E falling
#define LCD_DLY_tAH	// from E falling to RS change - 10 ns
#define LCD_DLY_tDSW	// from data to E falling - 80 ns, 250 ns from E rising
#define LCD_DLY_tH	// from E falling to data change - 10ns
#define LCD_DLY_tEL	__NOP(); __NOP(); __NOP(); __NOP(); __NOP(); \
	__NOP(); __NOP(); __NOP(); __NOP(); __NOP(); \
	__NOP(); __NOP(); __NOP(); __NOP(); __NOP(); \
	__NOP(); __NOP(); __NOP(); __NOP(); __NOP(); \
	__NOP(); __NOP(); __NOP(); __NOP(); __NOP();
// from E falling to E rising - 250ns

#define E_L_DELAY	LCD_DLY_tEL
#define E_H_DELAY	LCD_DLY_tEL

// LEDs on D10..13
// Buttons on D0..3

// AVT1616
// Segments A..G, DP on D0..7, colon on D12
#define GPIOA_SEGMENTS	(AR_D0_MASK | AR_D1_MASK | AR_D2_MASK | AR_D7_MASK)
#define GPIOB_SEGMENTS	(AR_D3_MASK | AR_D4_MASK | AR_D5_MASK | AR_D6_MASK)

#define DISP_COLON_MASK	AR_D12_MASK
// Digits on D8..11
#define GPIOA_DIGITS	(AR_D11_MASK | AR_D8_MASK)
#define GPIOB_DIGITS	(AR_D10_MASK | AR_D9_MASK)
// Buzzer on D13, active low
#define BEEP_PORT	AR_D13_PORT
#define BEEP_BIT	AR_D13_BIT
// Buttons on A0, 1
// DS18B20 on A3
#define GPIOA_ODR_AVT1616	(1 << BEEP_BIT | 1 << AR_D0_BIT | 1 << AR_D1_BIT | 1 << AR_D2_BIT | 1 << AR_D7_BIT \
	| 1 << AR_D8_BIT | 1 << AR_D11_BIT | 1 << AR_D12_BIT)
#define GPIOA_MODER_AVT1616	(GPIOA_MODER_SWD | BF2(BEEP_BIT, GPIO_MODER_OUT)\
	| BF2(AR_D0_BIT, GPIO_MODER_OUT) | BF2(AR_D1_BIT, GPIO_MODER_OUT) | BF2(AR_D2_BIT, GPIO_MODER_OUT)\
	| BF2(AR_D7_BIT, GPIO_MODER_OUT) \
	| BF2(AR_D8_BIT, GPIO_MODER_OUT) | BF2(AR_D11_BIT, GPIO_MODER_OUT)| BF2(AR_D12_BIT, GPIO_MODER_OUT))
#define GPIOB_ODR_AVT1616	(1 << BEEP_BIT | 1 << AR_D3_BIT | 1 << AR_D4_BIT | 1 << AR_D5_BIT | 1 << AR_D6_BIT \
	| 1 << AR_D9_BIT | 1 << AR_D10_BIT)
#define GPIOB_MODER_AVT1616	(BF2(BEEP_BIT, GPIO_MODER_OUT)\
	| BF2(AR_D3_BIT, GPIO_MODER_OUT) | BF2(AR_D4_BIT, GPIO_MODER_OUT) | BF2(AR_D5_BIT, GPIO_MODER_OUT)\
	| BF2(AR_D6_BIT, GPIO_MODER_OUT) | BF2(AR_D9_BIT, GPIO_MODER_OUT) | BF2(AR_D10_BIT, GPIO_MODER_OUT))
