/*
 * lora.c
 *
 *  Created on: 14 wrz 2024
 *      Author: majorbien
 */

#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "xbee.h"
#include "tasks_settings.h"
#include "http_server.h"  
#include "driver/uart.h"

char json_buffer[256]; 
static const char *TAG = "XBEE";
static SemaphoreHandle_t json_mutex; 

void task_tx(void *pvParameters)
{
	ESP_LOGI(pcTaskGetName(NULL), "Start");
	uint8_t buffer[256]; 
	ESP_LOGI(pcTaskGetName(NULL), "Waiting for Json...");
	while(1) {
		xSemaphoreTake(json_mutex, portMAX_DELAY);

		if (strlen(json_buffer) > 0) {
			int txLen = snprintf((char *)buffer, sizeof(buffer), "%s", json_buffer);
			ESP_LOGI(pcTaskGetName(NULL), "%d byte packet sent: %s", txLen, buffer);
   			memset(json_buffer, 0, 256);  
    		ESP_LOGI(pcTaskGetName(NULL), "json_buffer cleared after transmission.");
    		ESP_LOGI(pcTaskGetName(NULL), "Waiting for Json...");

			if (uart_write_bytes(MODEM_UART_NUM, buffer, txLen) == false) {
				ESP_LOGE(pcTaskGetName(NULL), "Uart send fail");
			}
			
		} else {
			
		}

		xSemaphoreGive(json_mutex);

		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}

void xbeeInit(void)
{
	const uart_config_t uart_config = {
    .baud_rate = MODEM_UART_BAUD_RATE,
    .data_bits = UART_DATA_8_BITS,
    .parity = UART_PARITY_DISABLE,
    .stop_bits = UART_STOP_BITS_1,
    .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
    };

    uart_param_config(MODEM_UART_NUM, &uart_config);
    uart_set_pin(MODEM_UART_NUM, MODEM_TX_PIN, MODEM_RX_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    uart_driver_install(MODEM_UART_NUM, BUF_SIZE * 2, 0, 0, NULL, 0);
	json_mutex = xSemaphoreCreateMutex();
}

void xbeeTaskStart(void)
{
	xTaskCreatePinnedToCore(&task_tx, "xbeeSend", XBEE_SEND_STACK_SIZE, NULL, XBEE_SEND_PRIORITY, NULL, XBEE_SEND_CORE_ID);
}
