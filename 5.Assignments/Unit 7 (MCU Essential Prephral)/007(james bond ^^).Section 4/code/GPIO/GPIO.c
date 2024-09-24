
#include "GPIO.h"


void GPIO_SET_PIN_DIRECTION(GPIO_Port_Define* DDRx, PINS PIN_NUM, GPIO_Pin_Direction PIN_DIR){
	if(PIN_DIR == PIN_INPUT){
		switch(PIN_NUM){
		case PIN0: DDRx->PIN.pin0 = 0; break;
		case PIN1: DDRx->PIN.pin1 = 0; break;
		case PIN2: DDRx->PIN.pin2 = 0; break;
		case PIN3: DDRx->PIN.pin3 = 0; break;
		case PIN4: DDRx->PIN.pin4 = 0; break;
		case PIN5: DDRx->PIN.pin5 = 0; break;
		case PIN6: DDRx->PIN.pin6 = 0; break;
		case PIN7: DDRx->PIN.pin7 = 0; break;
		}
	}
	else if(PIN_DIR == PIN_OUTPUT){
		switch(PIN_NUM){
		case PIN0: DDRx->PIN.pin0 = 1; break;
		case PIN1: DDRx->PIN.pin1 = 1; break;
		case PIN2: DDRx->PIN.pin2 = 1; break;
		case PIN3: DDRx->PIN.pin3 = 1; break;
		case PIN4: DDRx->PIN.pin4 = 1; break;
		case PIN5: DDRx->PIN.pin5 = 1; break;
		case PIN6: DDRx->PIN.pin6 = 1; break;
		case PIN7: DDRx->PIN.pin7 = 1; break;
		}
	}
}
void GPIO_SET_PORT_DIRECTION(GPIO_Port_Define* DDRx, GPIO_Port_Direction PORT_DIR){
	DDRx->PORT = PORT_DIR;
}
void GPIO_SET_PIN_VALUE(GPIO_Port_Define* PORTx, PINS PIN_NUM, GPIO_Pin_Value PIN_VAL){
	switch(PIN_NUM){
	case PIN0: PORTx->PIN.pin0 = PIN_VAL; break;
	case PIN1: PORTx->PIN.pin1 = PIN_VAL; break;
	case PIN2: PORTx->PIN.pin2 = PIN_VAL; break;
	case PIN3: PORTx->PIN.pin3 = PIN_VAL; break;
	case PIN4: PORTx->PIN.pin4 = PIN_VAL; break;
	case PIN5: PORTx->PIN.pin5 = PIN_VAL; break;
	case PIN6: PORTx->PIN.pin6 = PIN_VAL; break;
	case PIN7: PORTx->PIN.pin7 = PIN_VAL; break;
	}
}
void GPIO_SET_PORT_VALUE(GPIO_Port_Define* PORTx,uint8 PORT_VAL){
	PORTx->PORT = PORT_VAL;
}
void GPIO_TOGGLE_PIN_VALUE(GPIO_Port_Define* PORTx, PINS PIN_NUM){
	switch(PIN_NUM){
	case PIN0: PORTx->PIN.pin0 ^= 1; break;
	case PIN1: PORTx->PIN.pin1 ^= 1; break;
	case PIN2: PORTx->PIN.pin2 ^= 1; break;
	case PIN3: PORTx->PIN.pin3 ^= 1; break;
	case PIN4: PORTx->PIN.pin4 ^= 1; break;
	case PIN5: PORTx->PIN.pin5 ^= 1; break;
	case PIN6: PORTx->PIN.pin6 ^= 1; break;
	case PIN7: PORTx->PIN.pin7 ^= 1; break;
	}
}
uint8 GPIO_GET_PIN_VALUE(GPIO_Port_Define* PINx, PINS PIN_NUM){
	switch(PIN_NUM){
		case PIN0: return PINx->PIN.pin0;
		case PIN1: return PINx->PIN.pin1;
		case PIN2: return PINx->PIN.pin2;
		case PIN3: return PINx->PIN.pin3;
		case PIN4: return PINx->PIN.pin4;
		case PIN5: return PINx->PIN.pin5;
		case PIN6: return PINx->PIN.pin6;
		case PIN7: return PINx->PIN.pin7;
	}
	return -1;
}
uint8 GPIO_GET_PORT_VALUE(GPIO_Port_Define* PINx){
	return PINx->PORT;
}

