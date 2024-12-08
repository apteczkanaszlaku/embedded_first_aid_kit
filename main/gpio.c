/*
 * gpio.c
 *
 *  Created on: 14 wrz 2024
 *      Author: majorbien
 */
 #include "gpio.h"
 #include "driver/gpio.h"
 #include "tasks_settings.h"
 #include "freertos/FreeRTOS.h"
 
bool openFirstAidKit;

void gpioTask(void *pvParameters)
{
	while(1)
	{
		gpioControl();
		vTaskDelay(pdMS_TO_TICKS(1000));
	}

}

void gpioConfig(void)
{
    esp_rom_gpio_pad_select_gpio(LOCK);
    esp_rom_gpio_pad_select_gpio(LED);
	esp_rom_gpio_pad_select_gpio(SLEEP);
	esp_rom_gpio_pad_select_gpio(MODULES);
	
    gpio_set_direction(LOCK, GPIO_MODE_OUTPUT);
	gpio_set_direction(LED, GPIO_MODE_OUTPUT);
    gpio_set_direction(SLEEP, GPIO_MODE_OUTPUT);
    gpio_set_direction(MODULES, GPIO_MODE_OUTPUT);
}


void gpioControl(void)
{
	if(openFirstAidKit==0)
	{
		gpio_set_level(LED, 0);	
		gpio_set_level(LOCK, 1);	
	}
	else
	{
		gpio_set_level(LOCK, 0);	
		gpio_set_level(LED, 1);

	}
	gpio_set_level(SLEEP, 0);
	gpio_set_level(MODULES, 0);
}

void gpioTaskStart(void)
{
	xTaskCreatePinnedToCore(&gpioTask,"gpio", GPIO_STACK_SIZE, NULL, GPIO_PRIORITY, NULL, GPIO_CORE_ID);
}


	
