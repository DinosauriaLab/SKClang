/**
 * @file sk_arm.h
 * @author leoli (leo.li@viewsec.com)
 * @brief
 * @version 0.1
 * @date 2023-11-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __SK_ARM_H
#define __SK_ARM_H

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

extern uint32_t SystemCoreClock;
#define delay_ns(x)                                                \
    {                                                              \
        uint32_t ticks = (SystemCoreClock / 1000000) * (x / 1000); \
        while (ticks--) {                                          \
            __NOP();                                               \
        }                                                          \
    }
#define delay_us(x)  delay_ns(x * 1000)
#define delay_ms(x)  delay_us(x * 1000)
#define delay_sec(x) delay_ms(x * 1000)

#ifndef UART_SEND_CHAR
#define UART_SEND_CHAR(x)
#endif

#ifdef DEBUG
static inline int _write(int fd, char *ptr, int len) {
    (void)fd;
    for (int i = 0; i < len; i++) {
        UART_SEND_CHAR(ptr[i]);
    }
    return len;
}
#else
static inline int _write(int fd, char *ptr, int len) {
    (void)fd;
    (void)ptr;
    return len;  // 或者返回未使用参数len以避免警告
}
#endif  // DEBUG

#endif  // __ARM_ARCH_6M__ || __ARM_ARCH_7M__ || __ARM_ARCH_7EM__ || __ARM_ARCH_8M_BASE__ || __ARM_ARCH_8M_MAIN__

/* Exported functions prototypes ---------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif  // __SK_ARM_H
