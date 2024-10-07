/*
	Cortex-M core boot util
	gbm 10'2024
*/

/* The file should be included after MCU-specific header, so that Cortex-M core registers are defined.
 *
 * Check the assembly code (.list file) generated by the compiler for caling app reset handler;
 * it will nor work if SP register is used after __set_MSP.
 * For gcc the correct code is produced with -O1 and above while -O0 and -Os use SP (wrong).
 */

#ifndef CM_BOOT_H_
#define CM_BOOT_H_

#ifdef NVIC

#define NELEMSOF(a)	(sizeof((a)) / sizeof((a)[0]))

static inline void disable_all_ints(void)
{
	SysTick->CTRL = 0;
	for (uint8_t i = 0; i < NELEMSOF(NVIC->ICER); i++)
		NVIC->ICER[i] = 0;
}

static inline void disable_unpend_all_ints(void)
{
	SysTick->CTRL = 0;
	SCB->ICSR = SCB_ICSR_PENDSTCLR_Msk | SCB_ICSR_PENDSVCLR_Msk;

	for (uint8_t i = 0; i < NELEMSOF(NVIC->ICER); i++)
	{
		NVIC->ICER[i] = 0;
		NVIC->ICPR[i] = 0;
	}
}

static inline void app_start(uint32_t addr)
{
	// at this point all interrupts must be disabled (NVIC, SysTick)
	SCB->VTOR = addr;
	struct cm_init_ {
		uint32_t Init_SP;
		void (*Reset_Handler)(void);
	};
	struct cm_init_ *app_init = (struct cm_init_ *) addr;
	__set_MSP(app_init->Init_SP);

	// SP register should not be used in the assembly instructions implementing the statement below
	app_init->Reset_Handler();
}

#else
#error MCU header file must be included before cm_boot.h
#endif

#endif	// CM_BOOT_H_