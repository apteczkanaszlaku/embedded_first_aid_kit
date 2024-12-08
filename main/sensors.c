#include <stdio.h>
#include <string.h>
#include <cJSON.h> // If you have access to the cJSON library
#include "sensors.h"
#include <bmp280.h>
#include "tasks_settings.h"
#include <string.h>
#include "xbee.h"
#include "sensors.h"

extern char json_buffer[256]; 
static SemaphoreHandle_t json_sensor_mutex;

void sensorsInit(void){
	//mutex
	json_sensor_mutex = xSemaphoreCreateMutex();
    ESP_ERROR_CHECK(i2cdev_init());
}

void Sensors(void *pvParameters) {
    bmp280_params_t params;
    bmp280_init_default_params(&params);
    bmp280_t dev;
    memset(&dev, 0, sizeof(bmp280_t));

    ESP_ERROR_CHECK(bmp280_init_desc(&dev, BMP280_I2C_ADDRESS_0, 0, 2, 5));
    if (bmp280_init(&dev, &params) != ESP_OK) {
        printf("Failed to initialize BMP280\n");
        vTaskDelete(NULL); 
    }

    bool bme280p = dev.id == BME280_CHIP_ID;
    float pressure, temperature, humidity;

    while (1) {
        esp_err_t res = bmp280_read_float(&dev, &temperature, &pressure, &humidity);
        if (res == ESP_OK) {
            printf("Temperature: %.2f, Pressure: %.2f, Humidity: %.2f\n",
                   temperature, pressure, bme280p ? humidity : 0.0);
        } else {
            printf("Temperature/pressure reading failed: %s\n", esp_err_to_name(res));
            
            if (res == ESP_FAIL || res == ESP_ERR_TIMEOUT) {
                printf("Sensor might be disconnected. Retrying...\n");
                vTaskDelay(pdMS_TO_TICKS(5000)); 
                continue;
            }
        }

        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}


void sensorsTaskStart(void) {
    xTaskCreatePinnedToCore(&Sensors, "Sensors", SENSORS_STACK_SIZE, NULL, SENSORS_PRIORITY, NULL, SENSORS_CORE_ID);
}


		/*
        // Construct JSON data
        cJSON *root = cJSON_CreateObject();
        cJSON_AddNumberToObject(root, "pressure", pressure);
        cJSON_AddNumberToObject(root, "temperature", temperature);
        if (bme280p) {
            cJSON_AddNumberToObject(root, "humidity", humidity);
        }

		char *json_string = cJSON_Print(root);
		ESP_LOGI(MESSAGE, "Sensor values %s", json_string);

		xSemaphoreTake(json_sensor_mutex, portMAX_DELAY);
		strncpy(json_buffer, json_string, sizeof(json_buffer));
		xSemaphoreGive(json_sensor_mutex); 

		free(json_string);
		cJSON_Delete(root);

		*/