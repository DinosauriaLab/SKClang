#ifndef COMMON_H
#define COMMON_H

/* Include any necessary libraries here */
#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif

/* Declare any constants or global variables here */

/* Declare any function prototypes here */
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
  do {             \
    a ^= b;        \
    b ^= a;        \
    a ^= b;        \
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

#define HEX2ASCII(x) ((x) < 10 ? (x) + '0' : (x)-10 + 'A')

#endif /* COMMON_H */
