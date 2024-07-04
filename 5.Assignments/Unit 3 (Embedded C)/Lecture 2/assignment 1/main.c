#include <stdio.h>
#include "uart.h"
#include "Type_Definitions.h"
String data = "learn in depth : abdullah eid";
int main(){

    uart_send_string(data);
    return 0;
}