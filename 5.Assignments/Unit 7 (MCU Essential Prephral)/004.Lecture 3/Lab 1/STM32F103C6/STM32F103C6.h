#ifndef STM32F103C6
#define STM32F103C6

//********************************  LIBRARIES  *******************************//

#include "Common Marcos.h"
#include "Type_Definitions.h"
#include "stdlib.h"
#include "stdint.h"

//***********************  Base addresses for Memories  **********************//

#define FLASH_MEMORY_BASE                                       0x08000000UL
#define SYSTEM_MEMORY_BASE                                      0x1FFFF000UL
#define SRAM_MEMORY_BASE                                        0x20000000UL


#define PERIPHERALS_BASE                                        0x40000000UL

#define CORTEX_M3_INTERNAL_PERIPHERALS_BASE                     0xE0000000UL

//*******************  Base addresses for AHB Peripherals  ********************//

#define RCC_BASE												0x40021000UL

//******************  Base addresses for APB2 Peripherals  ********************//

//GPIO

//A,B PORTS ARE FULLY ADDED

#define GPIOA_BASE                                              0x40010800UL
#define GPIOB_BASE                                              0x40010C00UL

//C,D PORTS ALL PARTIALLY ADDED

#define GPIOC_BASE                                              0x40011000UL
#define GPIOD_BASE                                              0x40011400UL

//E IS NOT INCLUDED

//EXTI

#define EXTI_BASE                                              0x40010400UL

//AFIO

#define AFIO_BASE                                              0x40010000UL

//******************  Base addresses for APB1 Peripherals  ********************//


//**************************  Peripheral register  ***************************//

//PPERIPHERAL REGISTER : RCC

typedef struct{
	volatile uint32 CR;
	volatile uint32 CFGR;
	volatile uint32 CIR;
	volatile uint32 APB2RSTR;
	volatile uint32 APB1RSTR;
	volatile uint32 AHBENR;
	volatile uint32 APB2ENR;
	volatile uint32 APB1ENR;
	volatile uint32 BDCR;
	volatile uint32 CSR;
	volatile uint32 AHBSTR;
	volatile uint32 CFGR2;
}RCC_typedef;

//PPERIPHERAL REGISTER : GPIO

typedef struct{
	volatile uint32 CRL;
	volatile uint32 CRH;
	volatile uint32 IDR;
	volatile uint32 ODR;
	volatile uint32 BSRR;
	volatile uint32 BRR;
	volatile uint32 LCKR;
}GPIO_typedef;

//PPERIPHERAL REGISTER : EXTI

typedef struct{
	volatile uint32 IMR;
	volatile uint32 EMR;
	volatile uint32 RTSR;
	volatile uint32 FTSR;
	volatile uint32 SWIER;
	volatile uint32 PR;
}EXTI_typedef;

//PPERIPHERAL REGISTER : AFIO

typedef struct{
	volatile uint32 EVCR;
	volatile uint32 MAPR;
	volatile uint32 EXTICR1;
	volatile uint32 EXTICR2;
	volatile uint32 EXTICR3;
	volatile uint32 EXTICR4;
	uint32          RESERVED0;  //0x18
	volatile uint32 MAPR2;      //0x1C
}AFIO_typedef;

//**************************  Peripheral Instants  ***************************//

#define GPIOA													((GPIO_typedef*)GPIOA_BASE)
#define GPIOB													((GPIO_typedef*)GPIOB_BASE)
#define GPIOC													((GPIO_typedef*)GPIOC_BASE)
#define GPIOD													((GPIO_typedef*)GPIOD_BASE)

#define RCC														((RCC_typedef*)RCC_BASE)

#define EXTI													((EXTI_typedef*)EXTI_BASE)

#define AFIO													((AFIO_typedef*)AFIO_BASE)

//******************************  clock Macros  ******************************//

#define RCC_AFIO_ENABLE                                          RCC->APB2ENR |= (1<<0)
#define RCC_GPIOA_ENABLE                                         RCC->APB2ENR |= (1<<2)
#define RCC_GPIOB_ENABLE                                         RCC->APB2ENR |= (1<<3)
#define RCC_GPIOC_ENABLE                                         RCC->APB2ENR |= (1<<4)
#define RCC_GPIOD_ENABLE                                         RCC->APB2ENR |= (1<<5)

#define RCC_AFIO_RESET                                           RCC->APB2RSTR |=  (1<<0);\
																 RCC->APB2RSTR &= ~(1<<0)
#define RCC_GPIOA_RESET                	                         RCC->APB2RSTR |=  (1<<2);\
		 	 	 	 	 	 	 	 	 	 	 	 	 	 	 RCC->APB2RSTR &= ~(1<<2)
#define RCC_GPIOB_RESET                  	                     RCC->APB2RSTR |=  (1<<3);\
		 	 	 	 	 	 	 	 	 	 	 	 	 	 	 RCC->APB2RSTR &= ~(1<<3)
#define RCC_GPIOC_RESET            	                             RCC->APB2RSTR |=  (1<<4);\
		 	 	 	 	 	 	 	 	 	 	 	 	 	 	 RCC->APB2RSTR &= ~(1<<4)
#define RCC_GPIOD_RESET	                                         RCC->APB2RSTR |=  (1<<5);\
		 	 	 	 	 	 	 	 	 	 	 	 	 	 	 RCC->APB2RSTR &= ~(1<<5)

//*****************************  Generic Macros  *****************************//

void _delay_ms(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++);
}


#endif


