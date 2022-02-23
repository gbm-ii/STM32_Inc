/*
 * Nucleo-144 H7xx board defs
 * gbm 02'18..05'21
 */
 
// all LEDs active HIGH
// LD1
#define LEDG_PORT    GPIOB
#define LEDG_BIT    0
// LD2 - yellow
#define LEDY_PORT    GPIOE
#define LEDY_BIT    1
// LD3
#define LEDR_PORT    GPIOB
#define LEDR_BIT    14
// USB OTG power switch with status LED
#define LEDU_PORT	GPIOD
#define LEDU_BIT	10

#define LEDG_DUTY    TIM3->CCR2    // or TIM8->CCR2
#define LEDB_DUTY    TIM17->CCR1    // CH1N
#define LEDR_DUTY    TIM15->CCR1    // CH1

#define LEDG_MSK    (1u << LEDG_BIT)
#define LEDY_MSK    (1u << LEDY_BIT)
#define LEDR_MSK    (1u << LEDR_BIT)
#define LEDU_MSK    (1u << LEDU_BIT)

#define BTN_PORT    GPIOC
#define BTN_BIT    13

#define BTN_DOWN    (BTN_PORT->IDR >> BTN_BIT & 1)

// GPIOD LPUART1 pins
#define TX_BIT	9
#define RX_BIT	8
