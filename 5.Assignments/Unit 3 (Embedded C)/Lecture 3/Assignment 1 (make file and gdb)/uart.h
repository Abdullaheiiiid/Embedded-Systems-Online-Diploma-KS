#include "Type_Definitions.h"

#ifndef UART_H
#define UART_H


#define uart0_base        0x101F1000


#define uartdr            *((unsigned int volatile*) ((unsigned int volatile*)uart0_base))

void uart_send_string(String data);
#endif