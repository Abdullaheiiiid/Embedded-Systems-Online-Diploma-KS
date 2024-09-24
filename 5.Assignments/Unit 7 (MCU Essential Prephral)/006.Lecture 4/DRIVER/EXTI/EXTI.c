//****************************  LIBRARIES  *******************************//

#include "EXTI.h"

//*************************  Generic Variable  ***************************//

void (* EXTI_GPTF[15])(void);


//***************************  Generic Macro  ***************************//

#define EXTI_AFIO_REGESTERS_MAPPING(port)               port == GPIOA ? 0\
														: port == GPIOB ?1\
														: port == GPIOC ?2\
														: port == GPIOD ?3:0


//******************  APIs Used by "MCAL EXTI DRIVER"  ******************//

void ENABLE_NVIC(uint16 Line){
	switch(Line){
	case EXTI0: NVIC_IRQ6_EXTI0_ENABLE; break;
	case EXTI1: NVIC_IRQ7_EXTI1_ENABLE; break;
	case EXTI2: NVIC_IRQ8_EXTI2_ENABLE; break;
	case EXTI3: NVIC_IRQ9_EXTI3_ENABLE; break;
	case EXTI4: NVIC_IRQ10_EXTI4_ENABLE; break;
	case EXTI5: NVIC_IRQ23_EXTI5_ENABLE; break;
	case EXTI6: NVIC_IRQ23_EXTI6_ENABLE; break;
	case EXTI7: NVIC_IRQ23_EXTI7_ENABLE; break;
	case EXTI8: NVIC_IRQ23_EXTI8_ENABLE; break;
	case EXTI9: NVIC_IRQ23_EXTI9_ENABLE; break;
	case EXTI10: NVIC_IRQ40_EXTI10_ENABLE; break;
	case EXTI11: NVIC_IRQ40_EXTI11_ENABLE; break;
	case EXTI12: NVIC_IRQ40_EXTI12_ENABLE; break;
	case EXTI13: NVIC_IRQ40_EXTI13_ENABLE; break;
	case EXTI14: NVIC_IRQ40_EXTI14_ENABLE; break;
	case EXTI15: NVIC_IRQ40_EXTI15_ENABLE; break;
	}
}


void DISABLE_NVIC(uint16 Line){
	switch(Line){
	case EXTI0: NVIC_IRQ6_EXTI0_DISABLE; break;
	case EXTI1: NVIC_IRQ7_EXTI1_DISABLE; break;
	case EXTI2: NVIC_IRQ8_EXTI2_DISABLE; break;
	case EXTI3: NVIC_IRQ9_EXTI3_DISABLE; break;
	case EXTI4: NVIC_IRQ10_EXTI4_DISABLE; break;
	case EXTI5: NVIC_IRQ23_EXTI5_DISABLE; break;
	case EXTI6: NVIC_IRQ23_EXTI6_DISABLE; break;
	case EXTI7: NVIC_IRQ23_EXTI7_DISABLE; break;
	case EXTI8: NVIC_IRQ23_EXTI8_DISABLE; break;
	case EXTI9: NVIC_IRQ23_EXTI9_DISABLE; break;
	case EXTI10: NVIC_IRQ40_EXTI10_DISABLE; break;
	case EXTI11: NVIC_IRQ40_EXTI11_DISABLE; break;
	case EXTI12: NVIC_IRQ40_EXTI12_DISABLE; break;
	case EXTI13: NVIC_IRQ40_EXTI13_DISABLE; break;
	case EXTI14: NVIC_IRQ40_EXTI14_DISABLE; break;
	case EXTI15: NVIC_IRQ40_EXTI15_DISABLE; break;
	}
}


void EXTI_INST(EXT_Config_Pin* EXI_PIN_Config){

	//	1- gpio input floating alternative
	GPIO_INPUT_PIN(EXI_PIN_Config->EXTI_PIN.EXTI_GPIO, EXI_PIN_Config->EXTI_PIN.EXTI_PIN_NUMBER, GPIO_INPUT_FLOATING);
	//	2- CHOOSE THE MULTIPLEXER VALUES TO ROUTE THE GPIOx PINy TO ITS EXTIy
	uint8 rgstnum = EXI_PIN_Config->EXTI_PIN.EXTI_LINE / 4;
	uint8 nipplenum = (EXI_PIN_Config->EXTI_PIN.EXTI_LINE % 4 ) * 4;

	AFIO->EXTICR[rgstnum] &= ~(0xF << nipplenum);
	AFIO->EXTICR[rgstnum] |= ((EXTI_AFIO_REGESTERS_MAPPING(EXI_PIN_Config->EXTI_PIN.EXTI_GPIO) & 0xF) << nipplenum);

	//	3- UPDATE FALLING AND RISING EDGE
	EXTI->RTSR &= ~(1<<EXI_PIN_Config->EXTI_PIN.EXTI_LINE);
	EXTI->FTSR &= ~(1<<EXI_PIN_Config->EXTI_PIN.EXTI_LINE);

	if(EXI_PIN_Config->EXTI_TRIGGER == EXTI_RISING_EDGE)
		EXTI->RTSR |= (1<<EXI_PIN_Config->EXTI_PIN.EXTI_LINE);

	else if(EXI_PIN_Config->EXTI_TRIGGER == EXTI_FALLING_EDGE)
		EXTI->FTSR |= (1<<EXI_PIN_Config->EXTI_PIN.EXTI_LINE);

	else if(EXI_PIN_Config->EXTI_TRIGGER == EXTI_RISING_FALLING){

		EXTI->RTSR |= (1<<EXI_PIN_Config->EXTI_PIN.EXTI_LINE);
		EXTI->FTSR |= (1<<EXI_PIN_Config->EXTI_PIN.EXTI_LINE);
	}

	//	4- update the callback function of ISR
	EXTI_GPTF[EXI_PIN_Config->EXTI_PIN.EXTI_LINE] = EXI_PIN_Config->EXTI_PTF;


	//	5- enable/disable the irq + nvic
	if(EXI_PIN_Config->EXTI_IRQ_ENABLE == EXTI_ENABLE){
		EXTI->IMR |= (1<<EXI_PIN_Config->EXTI_PIN.EXTI_LINE);
		ENABLE_NVIC(EXI_PIN_Config->EXTI_PIN.EXTI_LINE);
	}
	else if(EXI_PIN_Config->EXTI_IRQ_ENABLE == EXTI_DISABLE){
		EXTI->IMR &= ~(1<<EXI_PIN_Config->EXTI_PIN.EXTI_LINE);
		DISABLE_NVIC(EXI_PIN_Config->EXTI_PIN.EXTI_LINE);
	}
}



//@Fn			- EXTI_INIT
//@brief 		- INITIALIZE THE EXTIz GPIOx PINy ACCORDING TO PARAMETERS
//@param [in] 	- EXTI INFORMATIONS(EXT_Config_Pin* EXI_PIN_Config)
//@retval 		- NOTHING
//Note			-

void EXTI_INIT(EXT_Config_Pin* EXI_PIN_Config){

	EXTI_INST(EXI_PIN_Config);

}

//@Fn			- EXTI_DEINIT
//@brief 		- DEINITIALIZE THE EXTIz AND RESET ITS REGESTERS
//@retval 		- NOTHING
//Note			-

void EXTI_DEINIT(){

	EXTI->IMR	= 0x00000000;
	EXTI->EMR	= 0x00000000;
	EXTI->RTSR 	= 0x00000000;
	EXTI->FTSR 	= 0x00000000;
	EXTI->SWIER = 0x00000000;
	EXTI->PR 	= 0x11111111;

	//DISABLE THE NVIC INTERRAUPT
	NVIC_IRQ6_EXTI0_DISABLE;
	NVIC_IRQ7_EXTI1_DISABLE;
	NVIC_IRQ8_EXTI2_DISABLE;
	NVIC_IRQ9_EXTI3_DISABLE;
	NVIC_IRQ10_EXTI4_DISABLE;
	NVIC_IRQ23_EXTI5_DISABLE;
	NVIC_IRQ23_EXTI6_DISABLE;
	NVIC_IRQ23_EXTI7_DISABLE;
	NVIC_IRQ23_EXTI8_DISABLE;
	NVIC_IRQ23_EXTI9_DISABLE;
	NVIC_IRQ40_EXTI10_DISABLE;
	NVIC_IRQ40_EXTI11_DISABLE;
	NVIC_IRQ40_EXTI12_DISABLE;
	NVIC_IRQ40_EXTI13_DISABLE;
	NVIC_IRQ40_EXTI14_DISABLE;
	NVIC_IRQ40_EXTI15_DISABLE;

}

//@Fn			- EXTI_UPDATE
//@brief 		- UPDATE THE EXTIz GPIOx PINy ACCORDING TO PARAMETERS
//@param [in] 	- EXTI INFORMATIONS(EXT_Config_Pin* EXI_PIN_Config)
//@retval 		- NOTHING
//Note			-

void EXTI_UPDATE(EXT_Config_Pin* EXI_PIN_Config){

	EXTI_INST(EXI_PIN_Config);

}

void EXTI_INPUT_DATA(GPIO_typedef* GPIOx, EXT_GPIO_MAP* EXTIxPyx, uint8 enable_disable, uint8 trigger, void (* isr_function_ptr)(void)){
	EXT_Config_Pin PINx_config;
	PINx_config.EXTI_PIN = *EXTIxPyx;
	PINx_config.EXTI_TRIGGER = trigger;
	PINx_config.EXTI_PTF = isr_function_ptr;
	PINx_config.EXTI_IRQ_ENABLE = enable_disable;
	EXTI_INIT(&PINx_config);
}

//******************  ISR FUNCTIONS  ******************//

void EXTI0_IRQHandler(){

//	clear regester pd to avoid loop
	EXTI->PR |= (1<<EXTI0);
	EXTI_GPTF[EXTI0]();
}
void EXTI1_IRQHandler(){

//	clear regester pd to avoid loop
	EXTI->PR |= (1<<EXTI1);
	EXTI_GPTF[EXTI1]();
}
void EXTI2_IRQHandler(){

//	clear regester pd to avoid loop
	EXTI->PR |= (1<<EXTI2);
	EXTI_GPTF[EXTI2]();
}
void EXTI3_IRQHandler(){

//	clear regester pd to avoid loop
	EXTI->PR |= (1<<EXTI3);
	EXTI_GPTF[EXTI3]();
}
void EXTI4_IRQHandler(){

//	clear regester pd to avoid loop
	EXTI->PR |= (1<<EXTI4);
	EXTI_GPTF[EXTI4]();
}
void EXTI9_5_IRQHandler(){

//	clear regester pd to avoid loop
	if(EXTI->PR & (1<<EXTI5)){ EXTI->PR |= (1<<EXTI5);EXTI_GPTF[EXTI5]();}
	if(EXTI->PR & (1<<EXTI6)){ EXTI->PR |= (1<<EXTI6);EXTI_GPTF[EXTI6]();}
	if(EXTI->PR & (1<<EXTI7)){ EXTI->PR |= (1<<EXTI7);EXTI_GPTF[EXTI7]();}
	if(EXTI->PR & (1<<EXTI8)){ EXTI->PR |= (1<<EXTI8);EXTI_GPTF[EXTI8]();}
	if(EXTI->PR & (1<<EXTI9)){ EXTI->PR |= (1<<EXTI9);EXTI_GPTF[EXTI9]();}
}
void EXTI15_10_IRQHandler(){

//	clear regester pd to avoid loop
	if(EXTI->PR & (1<<EXTI10)){ EXTI->PR |= (1<<EXTI10);EXTI_GPTF[EXTI10]();}
	if(EXTI->PR & (1<<EXTI11)){ EXTI->PR |= (1<<EXTI11);EXTI_GPTF[EXTI11]();}
	if(EXTI->PR & (1<<EXTI12)){ EXTI->PR |= (1<<EXTI12);EXTI_GPTF[EXTI12]();}
	if(EXTI->PR & (1<<EXTI13)){ EXTI->PR |= (1<<EXTI13);EXTI_GPTF[EXTI13]();}
	if(EXTI->PR & (1<<EXTI14)){ EXTI->PR |= (1<<EXTI14);EXTI_GPTF[EXTI14]();}
	if(EXTI->PR & (1<<EXTI15)){ EXTI->PR |= (1<<EXTI15);EXTI_GPTF[EXTI15]();}
}



