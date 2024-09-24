
#include "STM32F103C6.h"
#include "GPIO.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "stdint.h"
#include "string.h"
#include "stdio.h"

#define ZERO 0x01  //0b00000001
#define ONE 0x79   //0b01111001
#define TWO 0x24   //0b00100100
#define THREE 0x30 //0b00110000
#define FOUR 0x58  //0b01011000
#define FIVE 0x12  //0b00010010
#define SIX 0x02   //0b00000010
#define SEVEN 0x19 //0b00011001
#define EIGHT 0x00 //0b00000000
#define NINE 0x10  //0b00010000

void GPIO_init() {
	GPIO_OUTPUT_PIN(GPIOA, GPIO_PIN7, GPIO_OUTPUT_PUSH_PULL, GPIO_OUTPUT_SPEED_10);
	GPIO_OUTPUT_PIN(GPIOA, GPIO_PIN8, GPIO_OUTPUT_PUSH_PULL, GPIO_OUTPUT_SPEED_10);
	GPIO_OUTPUT_PIN(GPIOA, GPIO_PIN9, GPIO_OUTPUT_PUSH_PULL, GPIO_OUTPUT_SPEED_10);
	GPIO_OUTPUT_PIN(GPIOA, GPIO_PIN10, GPIO_OUTPUT_PUSH_PULL, GPIO_OUTPUT_SPEED_10);
	GPIO_OUTPUT_PIN(GPIOA, GPIO_PIN11, GPIO_OUTPUT_PUSH_PULL, GPIO_OUTPUT_SPEED_10);
	GPIO_OUTPUT_PIN(GPIOA, GPIO_PIN12, GPIO_OUTPUT_PUSH_PULL, GPIO_OUTPUT_SPEED_10);
	GPIO_OUTPUT_PIN(GPIOA, GPIO_PIN13, GPIO_OUTPUT_PUSH_PULL, GPIO_OUTPUT_SPEED_10);
}

void CLOCK_init(){
	//	ENABLE GPIOA
	RCC_GPIOA_ENABLE;
	//	ENABLE GPIOB
	RCC_GPIOB_ENABLE;
}


int main(){
	CLOCK_init();
	KPD_Init();
	LCD_Init();
	uint8 key_pressed;
	LCD_Send_String("HEY");
	_delay_ms(100);
	LCD_Clear_Screen();
	GPIO_init();
	uint8 LCD_DISPLAY [11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
	uint8 DISPLAY [11] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO};
	for (uint8 i = 0; i < 11; i++)
	{
		LCD_Send_Char(LCD_DISPLAY[i]);
		GPIO_SET_PORT(GPIOA, DISPLAY[i] << 7);
		_delay_ms(100);
	}
	LCD_Clear_Screen();
	KPD_Init();
	LCD_Send_String("Keypad is ready");
	_delay_ms(100);
	LCD_Clear_Screen();

	while (1) {

		key_pressed = KPD_Get_Key();
		while(key_pressed == 'E'){
			key_pressed = KPD_Get_Key();
		}
		LCD_Send_Char(key_pressed);
		//		//PA1 >>>Connected external PUR
		//
		//		if ( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0) // press
		//		{
		//			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
		//			while  (MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0)  ; //Single Pressing
		//		}
		//		//PA13 >>>Connected external PDR
		//		if ( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == 1) //Multi Pressing
		//		{
		//			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
		//		}
		//		LCD_WRITE_STRING("HEY");
		//		wait_ms(30);
		//		LCD_clear_screen();
	}
	return 0;
}

