/**
 * @file common.h
 * @author leoli (jafee201153@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-09-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __COMMON_H
#define __COMMON_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Utils */
#define BUILD_DATE_TIME (__DATE__ " @ " __TIME__)  // "Sep 21 2018 @ 11:00:00"
#define HEX2ASCII(x)    ((x) < 10 ? (x) + '0' : (x)-10 + 'A')

/* Math */
#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif

#ifndef SQUARE
#define SQUARE(a) ((a) * (a))
#endif

#ifndef ABS
#define ABS(a) ((a) < 0 ? -(a) : (a))
#endif

#ifndef CLAMP
#define CLAMP(a, min, max) (MAX(MIN(a, max), min))
#endif

#ifndef SWAP
#define SWAP(a, b) \
    do {           \
        a ^= b;    \
        b ^= a;    \
        a ^= b;    \
    } while (0)
#endif

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#endif

#ifndef BIT
#define BIT(x) (1 << (x))
#endif

#ifndef BIT_SET
#define BIT_SET(x, y) ((x) |= BIT(y))
#endif

#ifndef BIT_CLEAR
#define BIT_CLEAR(x, y) ((x) &= ~BIT(y))
#endif

/* Clock */
#define MSEC_TO_USEC(x) ((x) * 1000)     // millisecond to microsecond
#define SEC_TO_MSEC(x)  ((x) * 1000)     // second to millisecond
#define SEC_TO_USEC(x)  ((x) * 1000000)  // second to microsecond

#ifndef MAX_DELAY_US
#define MAX_DELAY_US (349525)
#endif
#define DELAY_US(x)                 \
    do {                            \
        uint32_t _x = (x);          \
        while (_x > MAX_DELAY_US) { \
            delay_us(MAX_DELAY_US); \
            _x -= MAX_DELAY_US;     \
        }                           \
        delay_us(_x);               \
    } while (0)
#define DELAY_MS(x)  DELAY_US(MSEC_TO_USEC(x))
#define DELAY_SEC(x) DELAY_MS(SEC_TO_MSEC(x))

/* Exported functions prototypes ---------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif  // __COMMON_H
