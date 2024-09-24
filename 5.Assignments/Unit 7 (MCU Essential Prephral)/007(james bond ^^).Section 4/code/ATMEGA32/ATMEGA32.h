#ifndef  ATMEGA32
#define  ATMEGA32

#include"../Standard Library/Common Marcos.h"
#include"../Standard Library/Type_Definitions.h"
#include <util/delay.h>

// GPIO 
typedef struct{
		uint8 pin0:1;
		uint8 pin1:1;
		uint8 pin2:1;
		uint8 pin3:1;
		uint8 pin4:1;
		uint8 pin5:1;
		uint8 pin6:1;
		uint8 pin7:1;
	}GPIO_Pin_Define;

typedef union{
	uint8 PORT;
	GPIO_Pin_Define PIN;
}GPIO_Port_Define;


//DDRx
#define DDRA    ((volatile GPIO_Port_Define*)0x3A)
#define DDRB  	((volatile GPIO_Port_Define*)0x37)
#define DDRC  	((volatile GPIO_Port_Define*)0x34)
#define DDRD  	((volatile GPIO_Port_Define*)0x31)

//PORTx
#define PORTA 	((volatile GPIO_Port_Define*)0x3B)
#define PORTB 	((volatile GPIO_Port_Define*)0x38)
#define PORTC 	((volatile GPIO_Port_Define*)0x35)
#define PORTD 	((volatile GPIO_Port_Define*)0x32)


//PINx
#define PINA  	((volatile GPIO_Port_Define*)0x39)
#define PINB  	((volatile GPIO_Port_Define*)0x36)
#define PINC  	((volatile GPIO_Port_Define*)0x33)
#define PIND  	((volatile GPIO_Port_Define*)0x30)

//EXTI

#define SREG	((volatile GPIO_Port_Define*)0x5F)
#define GICR	((volatile GPIO_Port_Define*)0x5B)
#define GIFR	((volatile GPIO_Port_Define*)0x5A)
#define MCUCR	((volatile GPIO_Port_Define*)0x55)
#define MCUCSR	((volatile GPIO_Port_Define*)0x54)

#define EXTI0_PIN							  PIN2
#define EXTI1_PIN							  PIN3
#define EXTI2_PIN							  PIN2

#define EXTI0_PORT							 PORTD
#define EXTI1_PORT							 PORTD
#define EXTI2_PORT							 PORTB

#endif
