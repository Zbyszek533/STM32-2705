/*
 * LPS25HB.h
 *
 *  Created on: Feb 7, 2022
 *      Author: User
 */
#include "spi.h"
#include "usart.h"
#include "gpio.h"
#include <stdio.h>
#include "stm32l4xx_hal.h"
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef INC_LPS25HB_H_
#define INC_LPS25HB_H_

#define LPS25HB_ADDR			0xBA

#define LPS25HB_WHO_AM_I  		0x0F
#define LPS25HB_CTRL_REG1  		0x20
#define LPS25HB_CTRL_REG2  		0x21
#define LPS25HB_CTRL_REG3  		0x22
#define LPS25HB_CTRL_REG4  		0x23
#define LPS25HB_PRESS_OUT_XL  	0x28
#define LPS25HB_PRESS_OUT_L  	0x29
#define LPS25HB_PRESS_OUT_H  	0x2A
#define LPS25HB_TEMO_OUT_L  	0x2B
#define LPS25HB_TEMO_OUT_H  	0x2C

uint8_t lps_reg(uint8_t reg);

#endif /* INC_LPS25HB_H_ */
