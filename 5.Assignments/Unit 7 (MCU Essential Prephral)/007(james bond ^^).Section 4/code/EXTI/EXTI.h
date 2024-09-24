#ifndef EXTI
#define EXTI

#include"../ATMEGA32/ATMEGA32.h"
#include"../GPIO/GPIO.h"


void __vector_1(void) __attribute__((signal)); // ISR for INT0
void __vector_2(void) __attribute__((signal)); // ISR for INT1
void __vector_3(void) __attribute__((signal)); // ISR for INT2
/*Address Labels Code Comments
$000 jmp RESET ; Reset Handler
$002 jmp EXT_INT0 ; IRQ0 Handler
$004 jmp EXT_INT1 ; IRQ1 Handler
$006 jmp EXT_INT2 ; IRQ2 Handler
$008 jmp TIM2_COMP ; Timer2 Compare Handler
$00A jmp TIM2_OVF ; Timer2 Overflow Handler
$00C jmp TIM1_CAPT ; Timer1 Capture Handler
$00E jmp TIM1_COMPA ; Timer1 CompareA Handler
$010 jmp TIM1_COMPB ; Timer1 CompareB Handler
$012 jmp TIM1_OVF ; Timer1 Overflow Handler
$014 jmp TIM0_COMP ; Timer0 Compare Handler
$016 jmp TIM0_OVF ; Timer0 Overflow Handler
$018 jmp SPI_STC ; SPI Transfer Complete Handler
$01A jmp USART_RXC ; USART RX Complete Handler
$01C jmp USART_UDRE ; UDR Empty Handler
$01E jmp USART_TXC ; USART TX Complete Handler
$020 jmp ADC ; ADC Conversion Complete Handler
$022 jmp EE_RDY ; EEPROM Ready Handler
$024 jmp ANA_COMP ; Analog Comparator Handler
$026 jmp TWI ; Two-wire Serial Interface Handler
$028 jmp SPM_RDY ; Store Program Memory Ready Handler*/

//SREG PINS
#define GLOBAL_INTE								PIN7

//MCUCR PINS
#define ISC00									PIN0
#define ISC01									PIN1
#define ISC10									PIN2
#define ISC11									PIN3

//MCUCSR PINS
#define ISC2									PIN6

//GICR PINS
#define INTE0									PIN6
#define INTE1									PIN7
#define INTE2									PIN5

//GIFR PINS
#define INTF0									PIN6
#define INTF1									PIN7
#define INTF2									PIN5

typedef enum{
	INT0, INT1, INT2
}EXTI_NUMBER_config;

typedef enum{
	LOW_LEVEL, ANY_CHANGE, FALLING_EDGE01, RISING_EDGE01, NOT_EXTI01
}EXTI01_TRIGGER_MODE_config;

typedef enum{
	FALLING_EDGE2, RISING_EDGE2, NOT_EXTI2
}EXTI2_TRIGGER_MODE_config;

typedef struct{
	EXTI_NUMBER_config INT_NUMBER;
	EXTI01_TRIGGER_MODE_config INT_MODE01;
	EXTI2_TRIGGER_MODE_config INT_MODE2;
	void (*PTF)();
}EXTI_Pin_config;

void EXTI_TNIT(EXTI_Pin_config* EXTI_PIN_config);
void EXTI_GENERAL_ENABLE();
void EXTI_GENERAL_DISABLE();
void EXTI_CHANGE_CONFIGURATION(EXTI_Pin_config* EXTI_PIN_config);
void EXTI_INSTANCE(EXTI_NUMBER_config INT_NUMBER,EXTI01_TRIGGER_MODE_config INT_MODE01,EXTI2_TRIGGER_MODE_config INT_MODE2,void (*PTF)());

#endif
