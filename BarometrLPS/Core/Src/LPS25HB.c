/*
 * LPS25HB.c
 *
 *  Created on: Feb 7, 2022
 *      Author: User
 */
#include "LPS25HB.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"
#include <stdio.h>
#include "stm32l4xx_hal.h"
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "i2c.h"

uint8_t lps_reg(uint8_t reg)
{
	uint8_t value = 0;

	  HAL_I2C_Master_Transmit(&hi2c1, LPS25HB_ADDR, &reg, 1, HAL_MAX_DELAY);
	  HAL_Delay(10);
	  HAL_I2C_Master_Receive(&hi2c1, LPS25HB_ADDR, &value, 1, HAL_MAX_DELAY);

	/*
	reg |= 0x80;
	HAL_GPIO_WritePin(CS2_GPIO_Port, CS2_Pin, GPIO_PIN_RESET);
//	HAL_SPI_TransmitReceive(&hspi2, reg, value, 1, HAL_MAX_DELAY);
	HAL_SPI_Transmit(&hspi2, &reg, 1, 1000);
	HAL_SPI_Receive(&hspi2, &value, 1, 1000);
	HAL_GPIO_WritePin(CS2_GPIO_Port, CS2_Pin, GPIO_PIN_SET);
*/
	return value;
}
