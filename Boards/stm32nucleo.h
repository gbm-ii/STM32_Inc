/*
	STM32 Nucleo board auto selection based on MPU type
	gbm 11'2026
*/
#ifndef STM32NUCLEO_H_
#define STM32NUCLEO_H_
//========================================================================
#if defined(STM32F042xx) || defined(STM32F042x6)
#include "stm32f0yy.h"
#include "boards/stm32nucleo32.h"

#elif defined(STM32F072xB) || defined(STM32F091xx)
#include "stm32f0yy.h"
#include "boards/stm32nucleo64.h"

#elif defined(STM32L073xx)
#include "stm32l0yy.h"
#include "boards/stm32nucleo64.h"

#elif defined(STM32L432xx)
#include "stm32l4yy.h"
#include "boards/stm32nucleo32.h"

#elif defined(STM32L452xx)
#include "stm32l4yy.h"
#include "boards/stm32nucleo64.h"

#elif defined(STM32L552xx)
#include "stm32l5yy.h"
#error Nucleo version not defined for this MCU

#elif defined(STM32G0B1xx) || defined(STM32G0C1xx)
#include "stm32g0yy.h"
#include "boards/stm32nucleo64.h"

#elif defined(STM32G474xx)
#include "stm32g4yy.h"
#include "boards/stm32nucleo64.h"

#elif defined(STM32G564xx)
#include "stm32g5yy.h"
#include "boards/stm32nucleo64.h"

#elif defined(STM32C031xx) || defined(STM32C071xx)
#include "stm32c0yy.h"
#include "boards/stm32nucleo64.h"

#elif defined(STM32H503xx) || defined(STM32H533xx)
#include "stm32h5yy.h"
#include "boards/stm32nucleo64.h"

#elif defined(STM32H563xx) || defined(STM32H5E5xx)
#include "stm32h5yy.h"
#include "boards/stm32nucleo144-h5.h"

#elif defined(STM32U535xx) || defined(STM32U545xx) 
#include "stm32u5yy.h"
#include "boards/stm32nucleo64.h"

#elif defined(STM32C542xx) || defined(STM32C562xx)
#include "stm32c5yy.h"
#include "boards/stm32nucleo64.h"

#elif defined(STM32U375xx) || defined(STM32U385xx)
#include "stm32u3yy.h"
#include "boards/stm32nucleo64.h"

#elif defined(STM32U3B5xx) || defined(STM32U3C5xx)
#include "stm32u3yy.h"
#include "boards/stm32nucleo144-u3.h"

#elif defined(STM32F401xC) || defined(STM32F411xC)
#include "stm32f4yy.h"
#include "boards/stm32nucleo64.h"

#elif defined(STM32L476xx) || defined(STM32L496xx) || defined(STM32L4A6xx)
#include "stm32l4yy.h"
#include "boards/stm32nucleo64.h"

#elif defined(STM32L496xx) || defined(STM32L4A6xx) || defined(STM32L4P5xx) || defined(STM32L4R5xx) || defined(STM32L4S5xx)
#include "stm32l4yy.h"
#include "boards/stm32nucleo144-l4.h"

#elif defined(STM32U575xx) || defined(STM32U585xx) || defined(STM32U5A5xx)
#include "stm32u5yy.h"
#include "boards/stm32nucleo144-u5.h"

#else
#error Nucleo version not defined for this MCU
#endif

//========================================================================
#endif
