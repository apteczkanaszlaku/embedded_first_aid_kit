/*
 * analog.h
 *
 *  Created on: 5 paź 2024
 *      Author: majorbien
 */

#ifndef MAIN_ANALOG_H_
#define MAIN_ANALOG_H_

#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"
#include "driver/gpio.h"
#include "tasks_settings.h"
static const char *MESSAGE = "SENSORS";

extern char json_sensor_buffer[];

void sensorsInit(void);

double scaleXnormX(uint32_t x, uint32_t in_min, uint32_t in_max, double out_min, double out_max);

void sensorsTaskStart(void);



#endif /* MAIN_ANALOG_H_ */
