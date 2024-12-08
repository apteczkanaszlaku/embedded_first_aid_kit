

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdbool.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "xbee.h"
#include "nvs_flash.h"
#include "wifi.h"
#include "gpio.h"
#include "rc.h"

#include "sdkconfig.h"
#include "pn532.h"
#include "DFRobotDFPlayerMini.h"
#include "bmp280.h"
#include "sensors.h"

static const char *TAG_MAIN = "MAIN";


void app_main()
{
	ESP_LOGI(TAG_MAIN, "APP START");
	esp_err_t ret = nvs_flash_init();
	if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
	{
		ESP_ERROR_CHECK(nvs_flash_erase());
		ret = nvs_flash_init();
	}
	ESP_ERROR_CHECK(ret);
	
	xbeeInit();
	gpioConfig();
	sensorsInit();
	
	xbeeTaskStart();	
	gpioTaskStart();
	wifi_app_start();
	pn532TaskStart();
	sensorsTaskStart();
	
	bool debug = false;
	bool err = DF_begin(32, 35, true, true, debug);
	ESP_LOGI(TAG, "DF_begin=%d", err);
	if (!err) {
		ESP_LOGE(TAG, "DFPlayer Mini not online.");
		while(1) {
			vTaskDelay(1);
		}
	}
	ESP_LOGI(TAG, "DFPlayer Mini online.");
	ESP_LOGI(TAG, "Play first track on 01 folder.");
	DF_volume(30); 
	DF_play(1); 

	
}

