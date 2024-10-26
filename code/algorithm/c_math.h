/**
 * @file c_math.h
 * @author leoli (jafee201153@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __C_MATH_H
#define __C_MATH_H

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

#define TO_DEG(x) (x * 57.2957795131f)  // 1do/rad
#define RAD_2_DEG 57.29578              // [deg/rad]

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
#define SWAP(a, b)                 \
    do {                           \
        __typeof__(a) temp = (a);  \
        (a)                = (b);  \
        (b)                = temp; \
    } while (0)
#endif

#define IS_ODD(x)  ((x) & 1)
#define IS_EVEN(x) (!IS_ODD(x))

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#endif

#ifndef ARRAY_INVERT
#define ARRAY_INVERT(array, length)                      \
    do {                                                 \
        for (int i = 0; i < (length) / 2; ++i) {         \
            SWAP((array)[i], (array)[(length) - i - 1]); \
        }                                                \
    } while (0)
#endif

#ifndef ARRAY_IS_EMPTY
#define ARRAY_IS_EMPTY(array, length)           \
    ({                                          \
        bool is_empty = true;                   \
        for (size_t i = 0; i < (length); ++i) { \
            if ((array)[i] != 0) {              \
                is_empty = false;               \
                break;                          \
            }                                   \
        }                                       \
        is_empty;                               \
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

#endif  // __C_MATH_H
