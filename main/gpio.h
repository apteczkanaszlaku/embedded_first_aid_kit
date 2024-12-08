/*
 * gpio.h
 *
 *  Created on: 14 wrz 2024
 *      Author: majorbien
 */

#ifndef MAIN_GPIO_H_
#define MAIN_GPIO_H_

#define LOCK       13
#define LED        4
#define SLEEP      15
#define MODULES    19

#include "driver/gpio.h"
#include <stdint.h>
#include <stdio.h>

void gpioConfig(void);

void gpioControl(void);

void gpioTaskStart(void);

#endif /* MAIN_GPIO_H_ */
