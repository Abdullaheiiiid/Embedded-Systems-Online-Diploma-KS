//********************************  LIBRARIES  *******************************//

#include "GPIO.h"


//******************  APIs Used by "MCAL GPIO DRIVER"  ******************//

//@Fn			- GPIO_CRL_PIN
//@brief 		- GET FIRST BIT NUMBER OF PINy THAT WILL BE CONFIGURED USING MODE[0:1],CNF[0:1]
//@param [in] 	- PIN NUMBER (uint16 PIN_NUMBER)											            @ref GPIO_PINS_define(uint16 PIN_NUMBER)
//@param [out] 	- NUMBER OF FIRST BIT OF PINy
//Note			-

uint8 GPIO_CRLH_PIN(uint16 PIN_NUMBER){

	switch(PIN_NUMBER){
	case GPIO_PIN0:
		return 0;
	case GPIO_PIN1:
		return 4;
	case GPIO_PIN2:
		return 8;
	case GPIO_PIN3:
		return 12;
	case GPIO_PIN4:
		return 16;
	case GPIO_PIN5:
		return 20;
	case GPIO_PIN6:
		return 24;
	case GPIO_PIN7:
		return 28;


	case GPIO_PIN8:
		return 0;
	case GPIO_PIN9:
		return 4;
	case GPIO_PIN10:
		return 8;
	case GPIO_PIN11:
		return 12;
	case GPIO_PIN12:
		return 16;
	case GPIO_PIN13:
		return 20;
	case GPIO_PIN14:
		return 24;
	case GPIO_PIN15:
		return 28;
	}
	return 0;

}

//******************  APIs Supported by "MCAL GPIO DRIVER"  ******************//

//@Fn			- GPIO_INIT
//@brief 		- INITIALIZE THE GPIOx PINy ACCORDING TO PARAMETERS
//@param [in] 	- GPIO PORT(GPIO_typedef *GPIOx), GPIO PIN(GPIO_PINS_config PIN_config)
//@retval 		- NOTHING
//Note			-

void GPIO_INIT(GPIO_typedef *GPIOx, GPIO_PINS_config *PIN_config){

	//	PORT CONFIGURATION REGISTER LOW (GPIOx->CRL) CONFIGURE PINS 0 >>> 7
	//	PORT CONFIGURATION REGISTER HIGH (GPIOx->CRH) CONFIGURE PINS 8 >>> 15

	volatile uint32* ConfigRegister = (PIN_config->GPIO_PIN <= GPIO_PIN7) ? &GPIOx->CRL : &GPIOx->CRH ;
	GPIOx->ODR ;

	//	CLEAR CNFx[1:0] MODEx[1:0]
	*ConfigRegister &= ~(0XF << GPIO_CRLH_PIN(PIN_config->GPIO_PIN));
	uint8 mode = 0;
	switch(PIN_config->GPIO_MODE){
	case GPIO_OUTPUT_PUSH_PULL:
	case GPIO_OUTPUT_OPEN_DRAIN:
	case GPIO_OUTPUT_ALTERNATIVE_PUSH_PULL:
	case GPIO_OUTPUT_ALTERNATIVE_OPEN_DRAIN:
		mode = (PIN_config->GPIO_MODE << 2) | (PIN_config->GPIO_SPEED);
		*ConfigRegister |= (mode << GPIO_CRLH_PIN(PIN_config->GPIO_PIN));
		break;

	case GPIO_INPUT_ANALOG:
	case GPIO_INPUT_FLOATING:
		mode = ((PIN_config->GPIO_MODE - 4 ) << 2) | (PIN_config->GPIO_SPEED) ;
		*ConfigRegister |= (mode << GPIO_CRLH_PIN(PIN_config->GPIO_PIN));
		break;

	case GPIO_INPUT_PULLUP:
		mode = ((PIN_config->GPIO_MODE - 4 ) << 2) | (PIN_config->GPIO_SPEED);
		*ConfigRegister |= (mode << GPIO_CRLH_PIN(PIN_config->GPIO_PIN));
		GPIOx->ODR |= PIN_config->GPIO_PIN;
		break;

	case GPIO_INPUT_PULLDOWN:
		mode = ((PIN_config->GPIO_MODE - 5 ) << 2) | (PIN_config->GPIO_SPEED);
		*ConfigRegister |= (mode << GPIO_CRLH_PIN(PIN_config->GPIO_PIN));
		GPIOx->ODR &= ~PIN_config->GPIO_PIN;
		break;
	}

}

//@Fn			- GPIO_DEINIT
//@brief 		- DEINITIALIZE THE GPIOx AND RESET ITS REGESTERS
//@param [in] 	- GPIO PORT(GPIO_typedef *GPIOx)
//@retval 		- NOTHING
//Note			-

void GPIO_DEINIT(GPIO_typedef *GPIOx){

	//	IF MICROCONTROLLER DOES NOT HAS RESET CONTROLLER
	//	GPIOx->CRL  =  0x44444444;
	//	GPIOx->CHL  =  0x44444444;
	//	GPIOx->ID      IS READ ONLY
	//	GPIOx->ODR  =  0x00000000;
	//	GPIOx->BSRR =  0x00000000;
	//	GPIOx->BRR  =  0x00000000;
	//	GPIOx->LCKR =  0x00000000;

	//	IF MICROCONTROLLER HAS RESET CONTROLLER
	//	USING APB2RSTR REGESTER BY SET OR RESET THE PERIPHERALS
	if(GPIOx == GPIOA){
		RCC_GPIOA_RESET;
	}
	else if(GPIOx == GPIOB){
		RCC_GPIOB_RESET;
	}
	else if(GPIOx == GPIOC){
		RCC_GPIOC_RESET;
	}
	else if(GPIOx == GPIOD){
		RCC_GPIOD_RESET;
	}


}

//@Fn			- GPIO_GET_PIN
//@brief 		- READ THE PINy VALUE OF GPIOx
//@param [in] 	- GPIO PORT(GPIO_typedef *GPIOx), PIN NUMBER THAT WILL BE READ ACCORDING TO @ref GPIO_PINS_define(uint16 PIN_NUMBER)
//@param [out] 	- PINy VALUE ACCORDING TO //@ref GPIO_PINS_VALUE_define
//@retval 		- NOTHING
//Note			-

uint8 GPIO_GET_PIN(GPIO_typedef *GPIOx,uint16 PIN_NUMBER){

	if(GPIOx->IDR & PIN_NUMBER)
		return GPIO_PIN_SET;
	else
		return GPIO_PIN_RESET;

}

//@Fn			- GPIO_GET_PORT
//@brief 		- READ THE GPIOx PORT
//@param [in] 	- GPIO PORT(GPIO_typedef *GPIOx)
//@param [out] 	- GPIOx PORT VALUE
//@retval 		- NOTHING
//Note			-

uint16 GPIO_GET_PORT(GPIO_typedef *GPIOx){

	return (uint16)GPIOx->IDR;

}

//@Fn			- GPIO_SET_PIN
//@brief 		- WRITE ON THE PINy OF GPIOx
//@param [in] 	- GPIO PORT(GPIO_typedef *GPIOx), PIN NUMBER THAT WILL BE READ ACCORDING TO @ref GPIO_PINS_define(uint16 PIN_NUMBER), THE VALUE THAT WILL BE WRITTEN (uint8 PIN_VALUE)
//@retval 		- NOTHING
//Note			-

void GPIO_SET_PIN(GPIO_typedef *GPIOx, uint16 PIN_NUMBER, uint8 PIN_VALUE){

	if(PIN_VALUE){
		GPIOx->ODR |= (uint32)PIN_NUMBER;
		//or
		//GPIOx->BSRR |= PIN_NUMBER;
	}
	else{
		GPIOx->ODR &= ~(uint32)PIN_NUMBER;
		//or
		//GPIOx->BRR |= (uint32)PIN_NUMBER;
		//or
		//GPIOx->BSRR |= ((uint32)PIN_NUMBER << 16);
	}

}

//@Fn			- GPIO_SET_PORT
//@brief 		- WRITE ON THE GPIOx PORT
//@param [in] 	- GPIO PORT(GPIO_typedef *GPIOx), THE VALUE THAT WILL BE WRITTEN (uint16 PORT_VALUE)
//@retval 		- NOTHING
//Note			-

void GPIO_SET_PORT(GPIO_typedef *GPIOx, uint16 PORT_VALUE){

	GPIOx->ODR = (uint32)PORT_VALUE;

}

//@Fn			- GPIO_TOGGLE_PIN
//@brief 		- TOGGLE THE PINy OF GPIOx
//@param [in] 	- GPIO PORT(GPIO_typedef *GPIOx), PIN NUMBER THAT WILL BE READ ACCORDING TO @ref GPIO_PINS_define(uint16 PIN_NUMBER)
//@retval 		- NOTHING
//Note			-

void GPIO_TOGGLE_PIN(GPIO_typedef *GPIOx, uint16 PIN_NUMBER){

	GPIOx->ODR ^= PIN_NUMBER;
}

//@Fn			- GPIO_LOCK_PIN
//@brief 		- LOCK THE PINy OF GPIOx
//@param [in] 	- GPIO PORT(GPIO_typedef *GPIOx), PIN NUMBER THAT WILL BE READ ACCORDING TO             @ref GPIO_PINS_define(uint16 PIN_NUMBER)
//@param [out] 	- LOCKING STATE ACCORDING TO   															@ref GPIO_LOCK_STATE_define
//@retval 		- OK IF THE PIN IS LOCKED SUCCESSFULLY OR ERROR IF THE PIN IS NOT LOCKED ACCORDING TO   @ref GPIO_LOCK_STATE_define
//Note			-

uint8 GPIO_LOCK_PIN(GPIO_typedef *GPIOx, uint16 PIN_NUMBER){

//	Bit 16 LCKK[16]: Lock key
//	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
//	0: Port configuration lock key not active
//	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	vuint32 temp;
	temp |= (1<<16);
	temp |= PIN_NUMBER;


//	LOCK key writing sequence:
//	Write 1
	GPIOx->LCKR = temp;
//	Write 0
	GPIOx->LCKR = PIN_NUMBER;
//	Write 1
	GPIOx->LCKR = temp;
//	Read 0
	temp = GPIOx->LCKR;
//	Read 1 (this read is optional but confirms that the lock is active)
	if((uint32)(GPIOx->LCKR & (1<<16))){
		return GPIO_LOCK_STATE_OK;
	}
	else{
		return GPIO_LOCK_STATE_ERROR;
	}
//	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
//	Any error in the lock sequence will abort the lock.



}

void GPIO_INPUT_PIN(GPIO_typedef *GPIOx, uint16 pin, uint8 mode){
	GPIO_PINS_config PIN;
	PIN.GPIO_PIN = pin ;
	PIN.GPIO_MODE = mode ;
	PIN.GPIO_SPEED = GPIO_INPUT_SPEED ;
	GPIO_INIT(GPIOx, &PIN);
}

void GPIO_OUTPUT_PIN(GPIO_typedef *GPIOx, uint16 pin, uint8 mode, uint8 speed){
	GPIO_PINS_config PIN;
	PIN.GPIO_PIN = pin ;
	PIN.GPIO_MODE = mode ;
	PIN.GPIO_SPEED = speed ;
	GPIO_INIT(GPIOx, &PIN);
}
