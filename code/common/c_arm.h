/**
 * @file c_arm.h
 * @author leoli (jafee201153@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __C_ARM_H
#define __C_ARM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cmodule_config.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/**
 * __ARM_ARCH_6M__     : Cortex-M0, Cortex-M0+, Cortex-M1
 * __ARM_ARCH_7M__     : Cortex-M3
 * __ARM_ARCH_7EM__    : Cortex-M4, Cortex-M7
 * __ARM_ARCH_8M_BASE__: Cortex-M23
 * __ARM_ARCH_8M_MAIN__: Cortex-M33
 */
#if defined(__ARM_ARCH_6M__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__) || \
    defined(__ARM_ARCH_8M_BASE__) || defined(__ARM_ARCH_8M_MAIN__)

#define SYS_TICK_START()      \
    SysTick->LOAD = 0xFFFFFF; \
    SysTick->VAL  = 0;        \
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;
#define SYS_TICK_STOP()  (SysTick->CTRL = 0)
#define SYS_TICK_COUNT() (SysTick->VAL)

#ifndef delay_us
#error "delay_us() is not defined"
#else
#define delay_ms(ms)    \
    while (ms--) {      \
        delay_us(1000); \
    }
#endif

#endif  // __ARM_ARCH_6M__ || __ARM_ARCH_7M__ || __ARM_ARCH_7EM__ || __ARM_ARCH_8M_BASE__ || __ARM_ARCH_8M_MAIN__

/* Exported functions prototypes ---------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif  // __C_ARM_H
