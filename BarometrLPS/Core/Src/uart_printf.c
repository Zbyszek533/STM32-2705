/*
 * uart_printf.c
 *
 *  Created on: Jan 6, 2022
 *      Author: User
 */

#include "usart.h"
#include "uart_printf.h"



int __io_putchar(int ch)
{
	if(ch == '\n')
	{
		__io_putchar('\r');
	}

	HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, HAL_MAX_DELAY);

	return 1;
}

