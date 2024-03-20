/**
 * @file sk_lib.h
 * @author leoli (jafee201153@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-09-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __SK_COMMON_H
#define __SK_COMMON_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "progressbar.h"
#include "sk_arm.h"
#include "sk_debug.h"
#include "sk_math.h"

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

#define STRINGIFY(x)       #x
#define TOSTRING(x)        STRINGIFY(x)

/* Exported functions prototypes ---------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif  // __SK_COMMON_H
