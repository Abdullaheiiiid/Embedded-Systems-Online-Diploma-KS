
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
	DDRC &= ~(1<<0);
}



int main(){
	GPIOx_INIT();
	signed char cnt = 0;
	char up = 1;
	while(1){
		if(GET_BIT(PINC,0)){
			if(cnt == 8){
				up = 0;
				cnt = 7;
			}
			if(cnt == -1){
				up = 1;
				cnt = 0;
			}

			if(up){
				SET_BIT(PORTA,cnt);
				cnt++;
			}
			else{
				CLEAR_BIT(PORTA,cnt);
				cnt--;
			}
			while(GET_BIT(PINC,0));
		}
	}
}
