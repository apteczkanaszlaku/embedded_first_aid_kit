/*
 * http_server.h
 *
 *  Created on: 14 wrz 2024
 *      Author: majorbien
 */

#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"

#ifndef MAIN_HTTP_SERVER_H_
#define MAIN_HTTP_SERVER_H_


extern char json_buffer[];


typedef enum http_server_message
{
	HTTP_MSG_WIFI_CONNECT_INIT = 0,
	HTTP_MSG_WIFI_CONNECT_SUCCESS,
	HTTP_MSG_WIFI_CONNECT_FAIL,
	HTTP_MSG_FIRMWARE_UPDATE_SUCCESSFUL,
	HTTP_MSG_FIRMWARE_UPDATE_FAILED,
	HTTP_MSG_FIRMWARE_UPATE_INITIALIZED,
	HTTP_MSG_USER_LOGIN_DONE,
	HTTP_MGS_USER_LOGIN_FAIL,
	HTTP_MSG_USER_REGISTER_DONE,
	HTTP_MGS_USER_REGISTER_FAIL,
	HTTP_MGS_FIRST_AID_KIT_STATUS,
	HTTP_MSG_OPEN_WEB_PAGE
} http_server_message_e;


typedef struct http_server_queue_message
{
	http_server_message_e msgID;
} http_server_queue_message_t;

BaseType_t http_server_monitor_send_message(http_server_message_e msgID);

void http_server_trigger_open_web_page(void);

void http_server_start(void);

void http_server_stop(void);

#endif /* MAIN_HTTP_SERVER_H_ */
