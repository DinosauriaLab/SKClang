/**
 * @file math_c.h
 * @author leoli (leo.li@viewsec.com)
 * @brief
 * @version 0.1
 * @date 2023-11-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __MATH_C_H
#define __MATH_C_H

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

#ifndef ARRAY_INVERT
#define ARRAY_INVERT(array, length)                \
    do {                                           \
        for (int i = 0; i < length / 2; i++) {     \
            SWAP(array[i], array[length - i - 1]); \
        }                                          \
    } while (0)
#endif

#ifndef ARRAY_IS_ALL_ZERO
#define ARRAY_IS_ALL_ZERO(array, length, type)    \
    ({                                            \
        bool is_all_zero = true;                  \
        for (size_t i = 0; i < (length); ++i) {   \
            if (((type*)(array))[i] != (type)0) { \
                is_all_zero = false;              \
                break;                            \
            }                                     \
        }                                         \
        is_all_zero;                              \
    })
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

#ifndef CHECKSUM_ADD
#define CHECKSUM_ADD(array, length)        \
    ({                                     \
        uint64_t sum = 0;                  \
        for (int i = 0; i < length; i++) { \
            sum += array[i];               \
        }                                  \
        sum;                               \
    })
#endif

/* Exported functions prototypes ---------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif  // __MATH_C_H
