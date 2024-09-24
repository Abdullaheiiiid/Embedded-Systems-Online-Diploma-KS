/*
 * assignment.c
 *
 *  Created on: ٢٠‏/٠٩‏/٢٠٢٤
 *      Author: abdul
 */

#include<util/delay.h>
#define DDRA    *((volatile unsigned char*)0x3A)
#define PORTA 	*((volatile unsigned char*)0x3B)
#define PINA  	*((volatile unsigned char*)0x39)
#define DDRB  	*((volatile unsigned char*)0x37)
#define PORTB 	*((volatile unsigned char*)0x38)
#define PINB  	*((volatile unsigned char*)0x36)
#define DDRC  	*((volatile unsigned char*)0x34)
#define PORTC 	*((volatile unsigned char*)0x35)
#define PINC  	*((volatile unsigned char*)0x33)
#define DDRD  	*((volatile unsigned char*)0x31)
#define PORTD 	*((volatile unsigned char*)0x32)
#define PIND  	*((volatile unsigned char*)0x30)


void blink(volatile  unsigned int* x){
	*x &= ~(1<<0);
	_delay_ms(100);
	*x |= (1<<0);
	_delay_ms(100);
}
int main(){

	DDRA |=(1<<0);
	DDRB |=(1<<0);
	DDRC |=(1<<0);
	DDRD |=(1<<0);
	PORTA |=(1<<0);
	PORTB |=(1<<0);
	PORTC |=(1<<0);
	PORTD &=~(1<<0);

	while(1){
		PORTA &= ~(1<<0);
		_delay_ms(250);
		PORTA |= (1<<0);
		_delay_ms(250);

		PORTB &= ~(1<<0);
		_delay_ms(250);
		PORTB |= (1<<0);
		_delay_ms(250);

		PORTC &= ~(1<<0);
		_delay_ms(250);
		PORTC |= (1<<0);
		_delay_ms(250);

		PORTD |= (1<<0);
		_delay_ms(500);
		PORTD &= ~(1<<0);
		_delay_ms(500);



	}
	return 0;
}
