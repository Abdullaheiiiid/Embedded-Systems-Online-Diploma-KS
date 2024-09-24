#include "STM32F103C6.h"
#include "GPIO.h"
#include "LCD.h"
#include "EXTI.h"
#include "KEYPAD.h"

vuint8 flag = 0;

void isr_function_ptr(){

	LCD_Send_String("__|--|__");
	_delay_ms(250);
	flag = 1;
}

void GPIO_init() {
	EXTI_INPUT_DATA(GPIOB, &EXTI9PB9, EXTI_ENABLE, EXTI_RISING_EDGE, isr_function_ptr);
}

void CLOCK_init(){
	//	ENABLE GPIOA
	RCC_GPIOA_ENABLE;
	//	ENABLE GPIOB
	RCC_GPIOB_ENABLE;
	//	ENABLE AFIO
	RCC_AFIO_ENABLE;
}


int main(){
	CLOCK_init();
	GPIO_init();
	LCD_Init();

	flag = 1;

	while (1) {

		if(flag){
			LCD_Clear_Screen();
			flag = 0;
		}
	}
	return 0;
}

