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
PUTCHAR_PROTOTYPE {
    /* Place your implementation of fputc here */
    /* e.g. write a character to the USART and Loop until the end of transmission */
    #ifdef DEBUG
    LL_USART_TransmitData8(__UART_DEBUG_PORT__, ch);
    while (!LL_USART_IsActiveFlag_TXE(__UART_DEBUG_PORT__))
        ;
    #endif
    return ch;
}
int _write(int fd, char *ch, int len) {
    #ifdef DEBUG
    while (len--) {
        LL_USART_TransmitData8(__UART_DEBUG_PORT__, *ch);
        while (!LL_USART_IsActiveFlag_TXE(__UART_DEBUG_PORT__))
            ;
        ch++;
    }
    #endif
    return len;
}
int fputc(int ch, FILE *f) {
    #ifdef DEBUG
    LL_USART_TransmitData8(__UART_DEBUG_PORT__, (uint8_t *)&ch);
    while (!LL_USART_IsActiveFlag_TXE(__UART_DEBUG_PORT__))
        ;
    #endif
    return ch;
}

/* The minimum delay is 5us */
void DelayUs(uint16_t us) {
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
#endif

#ifdef __cplusplus
}
#endif
