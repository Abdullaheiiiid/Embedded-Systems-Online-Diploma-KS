#include"ATMEGA32/ATMEGA32.h"
#include"LCD/LCD.h"
#include"KEYPAD/KEYPAD.h"
#include"GPIO/GPIO.h"
#include"EXTI/EXTI.h"

int main (){

	LCD_Init();

	while (1) {
		for(int i = 0 ; i <= 9 ; i++){
			LCD_Send_Number(i);
			_delay_ms(250);
		}
		LCD_Clear_Screen();
		LCD_Send_String("HELLO WORLD!");
		_delay_ms(1000);
		LCD_Clear_Screen();
	}
	return 0;
}
