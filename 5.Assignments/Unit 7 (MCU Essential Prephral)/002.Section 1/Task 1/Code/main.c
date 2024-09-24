/*
 * main.c
 *
 *  Created on: ٢٠‏/٠٩‏/٢٠٢٤
 *      Author: abdul
 */


#include "GPIO/GPIO_MM.h"
#include "Standard Library/Common Marcos.h"
#include "Standard Library/Type_Definitions.h"
#include <util/delay.h>


void GPIOx_INIT(){
	DDRA = 0xFF;
	PORTA = 0;
}



int main(){
	GPIOx_INIT();
	while(1){
		for(int i = 0 ; i < 8 ; i++){
			SET_BIT(PORTA,i);
			_delay_ms(50);
		}
		for(int i = 0 ; i < 8 ; i++){
			CLEAR_BIT(PORTA,7-i);
			_delay_ms(50);
		}
	}
}
