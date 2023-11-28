/**
 * @file utility_c.h
 * @author leoli (jafee201153@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-09-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __UTILITY_C_H
#define __UTILITY_C_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/*  */
#include "utility_config.h"
/*  */

#include "arm_c.h"
#include "math_c.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

#ifndef UNUSED
#define UNUSED(x) (void)(x)
#endif

/*  */

#define StringTrueFalse(x) ((x) ? "true" : "false")

/*  */

#define BUILD_DATE_TIME    (__DATE__ " @ " __TIME__)  // "Sep 21 2018 @ 11:00:00"
#define HEX2ASCII(x)       ((x) < 10 ? (x) + '0' : (x)-10 + 'A')

/*  */

#if defined(__GNUC__)
#define strlwr(x)                              \
    do {                                       \
        char* p = (x);                         \
        while (*p != '\0') *p++ = tolower(*p); \
    } while (0)

#define strupr(x)                              \
    do {                                       \
        char* p = (x);                         \
        while (*p != '\0') *p++ = toupper(*p); \
    } while (0)
#endif

/* Exported functions prototypes ---------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif  // __UTILITY_C_H
