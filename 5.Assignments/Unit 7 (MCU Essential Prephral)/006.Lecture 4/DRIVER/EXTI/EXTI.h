#ifndef EXT_INT
#define EXT_INT

//********************************  LIBRARIES  *******************************//

#include "STM32F103C6.h"
#include "GPIO.h"


//********************  User type definitions (structures)  ******************//

typedef struct{

	uint8        EXTI_LINE;       		// SPECIFY THE PIN OF GPIO THAT BE CONFIGURED            @REF GPIO_PINS_define
	GPIO_typedef* EXTI_GPIO;       		// SPECIFY THE MODE OF GPIO PINS THAT BE SELECTED        @REF GPIO_MODES_define
	uint16        EXTI_PIN_NUMBER;      // SPECIFY THE SPEED OF GPIO PINS THAT BE SELECTED       @REF GPIO_SPEED_define
	uint8         EXTI_IVT_IRQ_NUMBER;      // SPECIFY THE SPEED OF GPIO PINS THAT BE SELECTED       @REF GPIO_SPEED_define

}EXT_GPIO_MAP;


typedef struct{

	EXT_GPIO_MAP EXTI_PIN;          	 // SPECIFY THE EXTI GPIO MAPPING       		@REF EXTI_MAPPING_define
	uint8		 EXTI_TRIGGER;      	 // SPECIFY THE EXTI TRIGGER CASE       		@REF EXTI_TRIGGER_define
	uint8		 EXTI_IRQ_ENABLE;    	 // SPECIFY THE EXTI IRQ ENABLE OR DISABLE      @REF EXTI_ENABLE_define
	void 		 (* EXTI_PTF)(void);	 // SET THE C FUNCTION THAT WILL BE EXCUTE ONCE WHEN INTERRUPT HAPPEND
}EXT_Config_Pin;

//*********************  Macros Configuration References  ********************//


//@ref EXTI_LINE_define

#define EXTI0							0
#define EXTI1							1
#define EXTI2							2
#define EXTI3							3
#define EXTI4							4
#define EXTI5							5
#define EXTI6							6
#define EXTI7							7
#define EXTI8							8
#define EXTI9							9
#define EXTI10							10
#define EXTI11							11
#define EXTI12							12
#define EXTI13							13
#define EXTI14							14
#define EXTI15							15

//@ref EXTI_MAPPING_define

#define EXTI0PA0						(EXT_GPIO_MAP){EXTI0,GPIOA,GPIO_PIN0,EXTI0_IRQ}
#define EXTI0PB0						(EXT_GPIO_MAP){EXTI0,GPIOB,GPIO_PIN0,EXTI0_IRQ}
#define EXTI0PC0						(EXT_GPIO_MAP){EXTI0,GPIOC,GPIO_PIN0,EXTI0_IRQ}
#define EXTI0PD0						(EXT_GPIO_MAP){EXTI0,GPIOD,GPIO_PIN0,EXTI0_IRQ}

#define EXTI1PA1						(EXT_GPIO_MAP){EXTI1,GPIOA,GPIO_PIN1,EXTI1_IRQ}
#define EXTI1PB1						(EXT_GPIO_MAP){EXTI1,GPIOB,GPIO_PIN1,EXTI1_IRQ}
#define EXTI1PC1						(EXT_GPIO_MAP){EXTI1,GPIOC,GPIO_PIN1,EXTI1_IRQ}
#define EXTI1PD1						(EXT_GPIO_MAP){EXTI1,GPIOD,GPIO_PIN1,EXTI1_IRQ}

#define EXTI2PA2						(EXT_GPIO_MAP){EXTI2,GPIOA,GPIO_PIN2,EXTI2_IRQ}
#define EXTI2PB2						(EXT_GPIO_MAP){EXTI2,GPIOB,GPIO_PIN2,EXTI2_IRQ}
#define EXTI2PC2						(EXT_GPIO_MAP){EXTI2,GPIOC,GPIO_PIN2,EXTI2_IRQ}
#define EXTI2PD2						(EXT_GPIO_MAP){EXTI2,GPIOD,GPIO_PIN2,EXTI2_IRQ}

#define EXTI3PA3						(EXT_GPIO_MAP){EXTI3,GPIOA,GPIO_PIN3,EXTI3_IRQ}
#define EXTI3PB3						(EXT_GPIO_MAP){EXTI3,GPIOB,GPIO_PIN3,EXTI3_IRQ}
#define EXTI3PC3						(EXT_GPIO_MAP){EXTI3,GPIOC,GPIO_PIN3,EXTI3_IRQ}
#define EXTI3PD3						(EXT_GPIO_MAP){EXTI3,GPIOD,GPIO_PIN3,EXTI3_IRQ}

#define EXTI4PA4						(EXT_GPIO_MAP){EXTI4,GPIOA,GPIO_PIN4,EXTI4_IRQ}
#define EXTI4PB4						(EXT_GPIO_MAP){EXTI4,GPIOB,GPIO_PIN4,EXTI4_IRQ}
#define EXTI4PC4						(EXT_GPIO_MAP){EXTI4,GPIOC,GPIO_PIN4,EXTI4_IRQ}
#define EXTI4PD4						(EXT_GPIO_MAP){EXTI4,GPIOD,GPIO_PIN4,EXTI4_IRQ}

#define EXTI5PA5						(EXT_GPIO_MAP){EXTI5,GPIOA,GPIO_PIN5,EXTI5_IRQ}
#define EXTI5PB5						(EXT_GPIO_MAP){EXTI5,GPIOB,GPIO_PIN5,EXTI5_IRQ}
#define EXTI5PC5						(EXT_GPIO_MAP){EXTI5,GPIOC,GPIO_PIN5,EXTI5_IRQ}
#define EXTI5PD5						(EXT_GPIO_MAP){EXTI5,GPIOD,GPIO_PIN5,EXTI5_IRQ}

#define EXTI6PA6						(EXT_GPIO_MAP){EXTI6,GPIOA,GPIO_PIN6,EXTI6_IRQ}
#define EXTI6PB6						(EXT_GPIO_MAP){EXTI6,GPIOB,GPIO_PIN6,EXTI6_IRQ}
#define EXTI6PC6						(EXT_GPIO_MAP){EXTI6,GPIOC,GPIO_PIN6,EXTI6_IRQ}
#define EXTI6PD6						(EXT_GPIO_MAP){EXTI6,GPIOD,GPIO_PIN6,EXTI6_IRQ}

#define EXTI7PA7						(EXT_GPIO_MAP){EXTI7,GPIOA,GPIO_PIN7,EXTI7_IRQ}
#define EXTI7PB7						(EXT_GPIO_MAP){EXTI7,GPIOB,GPIO_PIN7,EXTI7_IRQ}
#define EXTI7PC7						(EXT_GPIO_MAP){EXTI7,GPIOC,GPIO_PIN7,EXTI7_IRQ}
#define EXTI7PD7						(EXT_GPIO_MAP){EXTI7,GPIOD,GPIO_PIN7,EXTI7_IRQ}

#define EXTI8PA8						(EXT_GPIO_MAP){EXTI8,GPIOA,GPIO_PIN8,EXTI8_IRQ}
#define EXTI8PB8						(EXT_GPIO_MAP){EXTI8,GPIOB,GPIO_PIN8,EXTI8_IRQ}
#define EXTI8PC8						(EXT_GPIO_MAP){EXTI8,GPIOC,GPIO_PIN8,EXTI8_IRQ}
#define EXTI8PD8						(EXT_GPIO_MAP){EXTI8,GPIOD,GPIO_PIN8,EXTI8_IRQ}

#define EXTI9PA9						(EXT_GPIO_MAP){EXTI9,GPIOA,GPIO_PIN9,EXTI9_IRQ}
#define EXTI9PB9						(EXT_GPIO_MAP){EXTI9,GPIOB,GPIO_PIN9,EXTI9_IRQ}
#define EXTI9PC9						(EXT_GPIO_MAP){EXTI9,GPIOC,GPIO_PIN9,EXTI9_IRQ}
#define EXTI9PD9						(EXT_GPIO_MAP){EXTI9,GPIOD,GPIO_PIN9,EXTI9_IRQ}

#define EXTI10PA10						(EXT_GPIO_MAP){EXTI10,GPIOA,GPIO_PIN10,EXTI10_IRQ}
#define EXTI10PB10						(EXT_GPIO_MAP){EXTI10,GPIOB,GPIO_PIN10,EXTI10_IRQ}
#define EXTI10PC10						(EXT_GPIO_MAP){EXTI10,GPIOC,GPIO_PIN10,EXTI10_IRQ}
#define EXTI10PD10						(EXT_GPIO_MAP){EXTI10,GPIOD,GPIO_PIN10,EXTI10_IRQ}

#define EXTI11PA11						(EXT_GPIO_MAP){EXTI11,GPIOA,GPIO_PIN11,EXTI11_IRQ}
#define EXTI11PB11						(EXT_GPIO_MAP){EXTI11,GPIOB,GPIO_PIN11,EXTI11_IRQ}
#define EXTI11PC11						(EXT_GPIO_MAP){EXTI11,GPIOC,GPIO_PIN11,EXTI11_IRQ}
#define EXTI11PD11						(EXT_GPIO_MAP){EXTI11,GPIOD,GPIO_PIN11,EXTI11_IRQ}

#define EXTI12PA12						(EXT_GPIO_MAP){EXTI12,GPIOA,GPIO_PIN12,EXTI12_IRQ}
#define EXTI12PB12						(EXT_GPIO_MAP){EXTI12,GPIOB,GPIO_PIN12,EXTI12_IRQ}
#define EXTI12PC12						(EXT_GPIO_MAP){EXTI12,GPIOC,GPIO_PIN12,EXTI12_IRQ}
#define EXTI12PD12						(EXT_GPIO_MAP){EXTI12,GPIOD,GPIO_PIN12,EXTI12_IRQ}

#define EXTI13PA13						(EXT_GPIO_MAP){EXTI13,GPIOA,GPIO_PIN13,EXTI13_IRQ}
#define EXTI13PB13						(EXT_GPIO_MAP){EXTI13,GPIOB,GPIO_PIN13,EXTI13_IRQ}
#define EXTI13PC13						(EXT_GPIO_MAP){EXTI13,GPIOC,GPIO_PIN13,EXTI13_IRQ}
#define EXTI13PD13						(EXT_GPIO_MAP){EXTI13,GPIOD,GPIO_PIN13,EXTI13_IRQ}

#define EXTI14PA14						(EXT_GPIO_MAP){EXTI14,GPIOA,GPIO_PIN14,EXTI14_IRQ}
#define EXTI14PB14						(EXT_GPIO_MAP){EXTI14,GPIOB,GPIO_PIN14,EXTI14_IRQ}
#define EXTI14PC14						(EXT_GPIO_MAP){EXTI14,GPIOC,GPIO_PIN14,EXTI14_IRQ}
#define EXTI14PD14						(EXT_GPIO_MAP){EXTI14,GPIOD,GPIO_PIN14,EXTI14_IRQ}

#define EXTI15PA15						(EXT_GPIO_MAP){EXTI15,GPIOA,GPIO_PIN15,EXTI15_IRQ}
#define EXTI15PB15						(EXT_GPIO_MAP){EXTI15,GPIOB,GPIO_PIN15,EXTI15_IRQ}
#define EXTI15PC15						(EXT_GPIO_MAP){EXTI15,GPIOC,GPIO_PIN15,EXTI15_IRQ}
#define EXTI15PD15						(EXT_GPIO_MAP){EXTI15,GPIOD,GPIO_PIN15,EXTI15_IRQ}


//@REF EXTI_TRIGGER_define

#define EXTI_RISING_EDGE				0
#define EXTI_FALLING_EDGE				1
#define EXTI_RISING_FALLING				2

//@REF EXTI_ENABLE_define

#define EXTI_ENABLE						1
#define EXTI_DISABLE					0

//******************  APIs Supported by "MCAL EXTI DRIVER"  ******************//

void EXTI_INIT(EXT_Config_Pin* EXI_PIN_Config);
void EXTI_DEINIT();
void EXTI_UPDATE(EXT_Config_Pin* EXI_PIN_Config);
void EXTI_INPUT_DATA(GPIO_typedef* GPIOx, EXT_GPIO_MAP* EXTIxPyx, uint8 enable_disable, uint8 trigger, void (* isr_function_ptr)(void));
#endif