/**
 * @file utility_config.h
 * @author leoli (jafee201153@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-11-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __UTILITY_CONFIG_H
#define __UTILITY_CONFIG_H

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

// #USER_CODE_BEGIN

// #USER_CODE_END

/* Exported types ------------------------------------------------------------*/

// #USER_CODE_BEGIN

// #USER_CODE_END

/* Exported constants --------------------------------------------------------*/

// #USER_CODE_BEGIN

// #USER_CODE_END

/* Exported macro ------------------------------------------------------------*/

// #USER_CODE_BEGIN

#define MAX_DELAY_US             0xFFFFFFFF /* Please define the max delay time in us */
#define TINY_DELAY(microseconds)            /* Please define the delay function in us */
#define UART_SEND_CHAR(x)                   /* Please define the send char function */

// #USER_CODE_END

/* Exported functions prototypes ---------------------------------------------*/

// #USER_CODE_BEGIN

// #USER_CODE_END

#ifdef __cplusplus
}
#endif

#endif  // __UTILITY_CONFIG_H
