/*
 * task_setting.h
 *
 *  Created on: 14 wrz 2024
 *      Author: majorbien
 */
 
#ifndef MAIN_TASKS_SETTINGS_H_
#define MAIN_TASKS_SETTINGS_H_


// XBEE Send task
#define XBEE_SEND_STACK_SIZE				4096
#define XBEE_SEND_PRIORITY					5
#define XBEE_SEND_CORE_ID					0

//LoraWAN Receive task
#define XBEE_RECEIVE_STACK_SIZE				4086
#define XBEE_RECEIVE_PRIORITY				6
#define XBEE_RECEIVE_CORE_ID				0	

// NFC task
#define NFC_STACK_SIZE						4096
#define NFC_PRIORITY						4
#define NFC_CORE_ID							0

//sensors task
#define SENSORS_STACK_SIZE           		4096
#define SENSORS_PRIORITY					8
#define SENSORS_CORE_ID						0


// WiFi application task
#define WIFI_APP_TASK_STACK_SIZE			4096
#define WIFI_APP_TASK_PRIORITY				4
#define WIFI_APP_TASK_CORE_ID				1

// HTTP Server task
#define HTTP_SERVER_TASK_STACK_SIZE			8192
#define HTTP_SERVER_TASK_PRIORITY			3
#define HTTP_SERVER_TASK_CORE_ID			1

// HTTP Server Monitor task
#define HTTP_SERVER_MONITOR_STACK_SIZE		4096
#define HTTP_SERVER_MONITOR_PRIORITY		2
#define HTTP_SERVER_MONITOR_CORE_ID			1

// GPIO task
#define GPIO_STACK_SIZE						1024
#define GPIO_PRIORITY						7
#define GPIO_CORE_ID						1

// GPIO task
#define DFMP3_STACK_SIZE					2048
#define DFMP3_PRIORITY						8
#define DFMP3_CORE_ID						1

#endif /* MAIN_TASKS_SETTINGS_H_ */
