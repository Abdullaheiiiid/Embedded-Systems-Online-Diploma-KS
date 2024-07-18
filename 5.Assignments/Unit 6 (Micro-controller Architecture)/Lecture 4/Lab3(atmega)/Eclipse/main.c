#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

int main(){
	DDRD |=(1<<PD5)|(1<<PD6)|(1<<PD7);
	DDRD &=~((1<<PD3)|(1<<PD2));
	DDRB &=~(1<<PB2);
	GICR |= (1<<INT2)|(1<<INT1)|(1<<INT0);
	MCUCR |= (1<<ISC10)|(1<<ISC11)|(1<<ISC00);
	MCUCSR &= ~(1<<ISC2);
	sei();
	while(1)
	{
		PORTD &=~((1<<PD7)|(1<<PD6)|(1<<PD5));
	}
	return 0;
}

ISR(INT0_vect){
	PORTD|=(1<<PD5);
	_delay_ms(1000);
}
ISR(INT1_vect){
	PORTD|=(1<<PD6);
	_delay_ms(1000);
}
ISR(INT2_vect){
	PORTD|=(1<<PD7);
	_delay_ms(1000);
}
