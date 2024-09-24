#ifndef GPIO
#define GPIO

//********************************  LIBRARIES  *******************************//

#include "STM32F103C6.h"


//********************  User type definitions (structures)  ******************//

typedef struct{

	uint16 GPIO_PIN;       // SPECIFY THE PIN OF GPIO THAT BE CONFIGURED            @REF GPIO_PINS_define
	uint8 GPIO_MODE;       // SPECIFY THE MODE OF GPIO PINS THAT BE SELECTED        @REF GPIO_MODES_define
	uint8 GPIO_SPEED;      // SPECIFY THE SPEED OF GPIO PINS THAT BE SELECTED       @REF GPIO_SPEED_define
//	uint8 GPIO_VALUE;      // GET THE VALUE OF GPIO PINS THAT BE SELECTED       	@REF GPIO_PINS_VALUE_define

}GPIO_PINS_config;

//*********************  Macros Configuration References  ********************//

//@ref GPIO_PINS_define

#define GPIO_PIN0                               (1<<0)
#define GPIO_PIN1                               (1<<1)
#define GPIO_PIN2                               (1<<2)
#define GPIO_PIN3                               (1<<3)
#define GPIO_PIN4                               (1<<4)
#define GPIO_PIN5                               (1<<5)
#define GPIO_PIN6                               (1<<6)
#define GPIO_PIN7                               (1<<7)
#define GPIO_PIN8                               (1<<8)
#define GPIO_PIN9                               (1<<9)
#define GPIO_PIN10                              (1<<10)
#define GPIO_PIN11                              (1<<11)
#define GPIO_PIN12                              (1<<12)
#define GPIO_PIN13                              (1<<13)
#define GPIO_PIN14                              (1<<14)
#define GPIO_PIN15                              (1<<15)
#define GPIO_PINS                               0xFF

//@ref GPIO_PINS_define

//0: General purpose output push-pull
//1: General purpose output Open-drain
//2: Alternate function output Push-pull
//3: Alternate function output Open-drain
//4: Analog mode
//5: Floating input (reset state)
//6: Input with pull-up
//7: Input with pull-down

#define GPIO_OUTPUT_PUSH_PULL                   0
#define GPIO_OUTPUT_OPEN_DRAIN                  1
#define GPIO_OUTPUT_ALTERNATIVE_PUSH_PULL       2
#define GPIO_OUTPUT_ALTERNATIVE_OPEN_DRAIN      3
#define GPIO_INPUT_ANALOG                       4
#define GPIO_INPUT_FLOATING                     5
#define GPIO_INPUT_PULLUP                       6
#define GPIO_INPUT_PULLDOWN                     7

//@ref GPIO_PINS_define

//0: Input mode (reset state)
//1: Output mode, max speed 10 MHz.
//2: Output mode, max speed 2 MHz.
//3: Output mode, max speed 50 MHz.

#define GPIO_INPUT_SPEED                        0
#define GPIO_OUTPUT_SPEED_10                   	1
#define GPIO_OUTPUT_SPEED_2        				2
#define GPIO_OUTPUT_SPEED_50      				3

//@ref GPIO_PINS_VALUE_define

//0: LOGIC 0 RESET
//1: LOGIC 1 SET

#define GPIO_PIN_RESET                        		0
#define GPIO_PIN_SET                   	   			1

//@ref GPIO_LOCK_STATE_define

//0: LOGIC 0 ERROR
//1: LOGIC 1 OK

#define GPIO_LOCK_STATE_ERROR                   0
#define GPIO_LOCK_STATE_OK         	   			1
//******************  APIs Supported by "MCAL GPIO DRIVER"  ******************//

void   GPIO_INIT		(GPIO_typedef *GPIOx, GPIO_PINS_config *PIN_config);
void   GPIO_DEINIT		(GPIO_typedef *GPIOx);
uint8  GPIO_GET_PIN	    (GPIO_typedef *GPIOx, uint16 PIN_NUMBER);
uint16 GPIO_GET_PORT	(GPIO_typedef *GPIOx);
void   GPIO_SET_PIN		(GPIO_typedef *GPIOx, uint16 PIN_NUMBER, uint8 PIN_VALUE);
void   GPIO_SET_PORT	(GPIO_typedef *GPIOx, uint16 PORT_VALUE);
void   GPIO_TOGGLE_PIN	(GPIO_typedef *GPIOx, uint16 PIN_NUMBER);
uint8  GPIO_LOCK_PIN	(GPIO_typedef *GPIOx, uint16 PIN_NUMBER);
void GPIO_INPUT_PIN(GPIO_typedef *GPIOx, uint16 pin, uint8 mode);
void GPIO_OUTPUT_PIN(GPIO_typedef *GPIOx, uint16 pin, uint8 mode, uint8 speed);

#endif
