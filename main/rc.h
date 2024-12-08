/*
 * rc.h
 *
 *  Created on: 26 paź 2024
 *      Author: majorbien
 */

#ifndef MAIN_RC_H_
#define MAIN_RC_H_
#include <esp_log.h>

static const char *TAG = "rc522";


typedef struct rfid_login{
	char buffer[40];
	uint8_t code[8];
	char name[15];
	char surname[15];
}rfid_login_t;


extern char rfid_login_buffer[];

uint32_t hex2int(char *hex); 
void parseUserData(rfid_login_t *login, char *buffer);

#endif /* MAIN_RC_H_ */