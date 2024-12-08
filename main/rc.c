/*
 * rc.c
 *
 *  Created on: 26 paź 2024
 *      Author: majorbien
 */


#include "rc.h"


rfid_login_t rfid_login;

char rfid_login_buffer[256];
char buffer[40];



uint32_t hex2int(char *hex) {
    uint32_t val = 0;
    while (*hex) {
        // get current character then increment
        char byte = *hex++;
        // transform hex character to the 4bit equivalent number, using the ascii table indexes
        if (byte >= '0' && byte <= '9') byte = byte - '0';
        else if (byte >= 'a' && byte <='f') byte = byte - 'a' + 10;
        else if (byte >= 'A' && byte <='F') byte = byte - 'A' + 10;
        // shift 4 to make space for new digit, and add the 4 bits of the new digit
        val = (val << 4) | (byte & 0xF);
    }
    return val;
}


void parseUserData(rfid_login_t *login, char *buffer) {
    int index = 0;
    for (int i = 0; i < 4; i++) {
        char segment[3] = { buffer[index], buffer[index + 1], '\0' };
        login->code[i] = hex2int(segment);

        index += 3;
    }

    ESP_LOGI(TAG, "Conversion:");
    for (int i = 0; i < 4; i++) {
        ESP_LOGI(TAG, "%02x", login->code[i]);
    }
}

/*# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.5)

set(components/DFRobotDFPlayerMini)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(lora)*/


