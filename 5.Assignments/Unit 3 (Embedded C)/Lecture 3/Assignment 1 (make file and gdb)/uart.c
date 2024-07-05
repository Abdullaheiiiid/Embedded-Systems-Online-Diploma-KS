#include "uart.h"
#include "Type_Definitions.h"

void uart_send_string(String data){

    while(*data != '\0'){
        uartdr = (unsigned int volatile)(*data);
        data++;
    }
}