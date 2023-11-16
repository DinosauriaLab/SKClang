/**
 * @file arm_c.h
 * @author leoli (leo.li@viewsec.com)
 * @brief
 * @version 0.1
 * @date 2023-11-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __ARM_C_H
#define __ARM_C_H

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

#define MSEC_TO_USEC(x) ((x) * 1000)     // millisecond to microsecond
#define SEC_TO_MSEC(x)  ((x) * 1000)     // second to millisecond
#define SEC_TO_USEC(x)  ((x) * 1000000)  // second to microsecond

#ifdef __ARM_ARCH

#define SYS_TICK_START()      \
    SysTick->LOAD = 0xFFFFFF; \
    SysTick->VAL  = 0;        \
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;
#define SYS_TICK_STOP()  (SysTick->CTRL = 0)
#define SYS_TICK_COUNT() (SysTick->VAL)

#ifndef MAX_DELAY_US
#define MAX_DELAY_US (0xFFFFFFFFU)
#endif

#ifndef TINY_DELAY
#define TINY_DELAY(microseconds)
#endif

#define delay_us(x)                   \
    do {                              \
        uint32_t _x = (x);            \
        while (_x > MAX_DELAY_US) {   \
            TINY_DELAY(MAX_DELAY_US); \
            _x -= MAX_DELAY_US;       \
        }                             \
        TINY_DELAY(_x);               \
    } while (0)
#define delay_ms(x)  delay_us(MSEC_TO_USEC(x))
#define delay_sec(x) delay_ms(SEC_TO_MSEC(x))

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

#endif  // __ARM_ARCH

/* Exported functions prototypes ---------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif  // __ARM_C_H
