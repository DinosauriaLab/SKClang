/**
 * @file common.c
 * @author leoli (jafee201153@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-11-10
 *
 * @copyright Copyright (c) 2023
 *
 */

/* Includes ------------------------------------------------------------------*/
#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Private includes ----------------------------------------------------------*/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* External variables --------------------------------------------------------*/

/* External functions --------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

#ifdef __ARM_ARCH
__weak void delay_us(uint16_t us) {
    if (us > 0) {
        uint32_t ticks;
        uint32_t told, tnow, tcnt = 0;
        uint32_t reload = SysTick->LOAD;
        ticks           = us * HAL_RCC_GetSysClockFreq() / 1000000;
        told            = SysTick->VAL;
        while (true) {
            tnow = SysTick->VAL;
            if (tnow != told) {
                if (tnow < told)
                    tcnt += told - tnow;
                else
                    tcnt += reload - tnow + told;
                told = tnow;
                if (tcnt >= ticks) break;
            }
        }
    }
}

__weak int UART_TransmitData(uint8_t data) {
    LL_USART_TransmitData8(NULL, data);
    while (!LL_USART_IsActiveFlag_TXE(NULL))
        ;
}

int _write(int fd, char *ptr, int len) {
    (void)fd;
    (void)ptr;
#ifdef DEBUG
    for (int i = 0; i < len; i++) {
        UART_TransmitData(ptr[i]);
    }
#endif
    return len;
}

#endif

#ifdef __cplusplus
}
#endif
