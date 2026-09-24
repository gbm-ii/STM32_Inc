/*
	cm_mpu.h - Cortex-M MPU util
	gbm 09'2026
*/

/* The file should be included after MCU-specific header, so that Cortex-M core registers are defined.
 *
 */

#ifndef CM_MPU_H_
#define CM_MPU_H_

#if defined (__MPU_PRESENT) && (__MPU_PRESENT == 1U)

static inline void MPU_disable(void)
{
	__DMB();
	SCB->SHCSR &= ~SCB_SHCSR_MEMFAULTENA_Msk;
	MPU->CTRL  &= ~MPU_CTRL_ENABLE_Msk;
	__DSB();
	__ISB();
}

static inline void MPU_enable(void)
{
	__DMB();
	MPU->CTRL  |= MPU_CTRL_ENABLE_Msk;
	SCB->SHCSR |= SCB_SHCSR_MEMFAULTENA_Msk;
	__DSB();
	__ISB();
}

static inline void MPU_set_attrib(uint8_t attridx, uint8_t attrval)
{
	volatile uint32_t *mairptr = &MPU->MAIR[attridx / 4];
	union {
		uint32_t w;
		uint8_t b[4];
	} mair;
	mair.w = *mairptr;
	mair.b[attridx % 4] = attrval;
	*mairptr = mair.w;
}

static inline void MPU_set_region(uint8_t region, uint32_t startaddr, uint32_t endaddr, uint8_t access_rights, uint8_t attridx)
{
	__DMB();
	MPU->RNR = region;
	MPU->RLAR = 0;	// disable
	MPU->RBAR = (startaddr & MPU_RBAR_BASE_Msk) | access_rights;
	MPU->RLAR = (endarddr & MPU_RLAR_LIMIT_Msk) | (attridx << MPU_RLAR_AttrIndx_Pos & MPU_RLAR_AttrIndx_Msk) | MPU_RLAR_EN_Msk;
}

#else	// no MPU
#error MCU header file must be included before cm_boot.h for MPU_PRESENT
#endif

#endif	// CM_BOOT_H_
