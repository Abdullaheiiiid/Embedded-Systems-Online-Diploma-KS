#ifndef GPIO
#define GPIO

#include"../ATMEGA32/ATMEGA32.h"

//PINs
typedef enum{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}PINS;

typedef enum
{
	PIN_INPUT,PIN_OUTPUT
}GPIO_Pin_Direction;

typedef enum
{
	LOGIC_LOW,LOGIC_HIGH
}GPIO_Pin_Value;

typedef enum
{
	PORT_INPUT,PORT_OUTPUT=0xFF
}GPIO_Port_Direction;



void GPIO_SET_PIN_DIRECTION(GPIO_Port_Define* DDRx, PINS PIN_NUM, GPIO_Pin_Direction PIN_DIR);
void GPIO_SET_PORT_DIRECTION(GPIO_Port_Define* DDRx, GPIO_Port_Direction PORT_DIR);
void GPIO_SET_PIN_VALUE(GPIO_Port_Define* PORTx, PINS PIN_NUM, GPIO_Pin_Value PIN_VAL);
void GPIO_SET_PORT_VALUE(GPIO_Port_Define* PORTx,uint8 PORT_VAL);
void GPIO_TOGGLE_PIN_VALUE(GPIO_Port_Define* PORTx, PINS PIN_NUM);
uint8 GPIO_GET_PIN_VALUE(GPIO_Port_Define* PINx, PINS PIN_NUM);
uint8 GPIO_GET_PORT_VALUE(GPIO_Port_Define* PINx);


#endif
