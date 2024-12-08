/*
 * lora.h
 *
 *  Created on: 14 wrz 2024
 *      Author: majorbien
 */

#ifndef MAIN_XBEE_H_
#define MAIN_XBEE_H_


#define MODEM_UART_NUM UART_NUM_1
#define MODEM_TX_PIN 23
#define MODEM_RX_PIN 22
#define MODEM_UART_BAUD_RATE 9600
#define BUF_SIZE 256

void xbeeInit(void);

void xbeeTaskStart(void);




#endif /* MAIN_XBEE_H_ */
