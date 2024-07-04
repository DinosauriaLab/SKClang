/**
 * @file c_lib.h
 * @author leoli (jafee201153@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-07-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __C_LIB_H
#define __C_LIB_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "c_arm.h"
#include "c_math.h"
#include "c_progressbar.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

#ifndef UNUSED
#define UNUSED(x) (void)(x)
#endif

/*  */

#define STRINGBOOL(x)   ((x) ? "TRUE" : "FALSE")

/*  */

#define BUILD_DATE_TIME (__DATE__ " @ " __TIME__)  // "Sep 21 2018 @ 11:00:00"
#define HEX2ASCII(x)    ((x) < 10 ? (x) + '0' : (x) - 10 + 'A')

// #define VALUE 123
// STRINGIFY(VALUE) // "VALUE"
// TOSTRING(VALUE)  // "123"
#define STRINGIFY(x)    #x
#define TOSTRING(x)     STRINGIFY(x)

/*  */

#define TO_LOWERCASE(str)                    \
    do {                                     \
        char *s = (str);                     \
        while (*s) {                         \
            *s = tolower((unsigned char)*s); \
            s++;                             \
        }                                    \
    } while (0)

#define TO_UPPERCASE(str)                    \
    do {                                     \
        char *s = (str);                     \
        while (*s) {                         \
            *s = toupper((unsigned char)*s); \
            s++;                             \
        }                                    \
    } while (0)

/* Exported functions prototypes ---------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif  // __C_LIB_H
