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
#include <stdint.h>

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
#define SEC_TO_MSEC(x) ((x) * 1000)
#define SEC_TO_USEC(x) ((x) * 1000000)

// extern int32_t CLK_SysTickDelay(uint32_t us);
#define delay_us(x) CLK_SysTickDelay(x)

/* Exported functions prototypes ---------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif  // __COMMON_H
