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
#include "debug_c.h"
#include "math_c.h"
#include "progressbar.h"

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

/* Exported functions prototypes ---------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif  // __UTILITY_C_H
