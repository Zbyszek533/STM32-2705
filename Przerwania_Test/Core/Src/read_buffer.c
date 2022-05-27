/*
 * read_buffer.c
 *
 *  Created on: May 24, 2022
 *      Author: User
 */


#include <stdio.h>
#include <read_buffer.h>
#include "usart.h"

static char line_buffer[LINE_MAX_LENGTH + 1];
static uint32_t line_length;


void line_append(uint8_t value)
{

	if(value =='\r' || value == '\n')
	{

		if(line_length > 0)
		{
			line_buffer[line_length] = '\0';

			if(strcmp(line_buffer, "on") == 0)
			{
				HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
				printf("On\n");
			}else if(strcmp(line_buffer, "off") == 0)
			{
				HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
				printf("Off\n");
			}

			line_length = 0;
		}
	}else{
		if(line_length >= LINE_MAX_LENGTH)
		{
			line_length = 0;
		}

		line_buffer[line_length++] = value;
	}
}
