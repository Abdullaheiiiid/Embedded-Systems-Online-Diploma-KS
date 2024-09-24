#ifndef STM32F103C6
#define STM32F103C6

//********************************  LIBRARIES  *******************************//

#include "Common Marcos.h"
#include "Type_Definitions.h"

//***********************  Base addresses for Memories  **********************//

#define FLASH_MEMORY_BASE                                       0x08000000UL
#define SYSTEM_MEMORY_BASE                                      0x1FFFF000UL
#define SRAM_MEMORY_BASE                                        0x20000000UL


#define PERIPHERALS_BASE                                        0x40000000UL

#define CORTEX_M3_INTERNAL_PERIPHERALS_BASE                     0xE0000000UL

#define NVIC_BASE                    							0xE000E100UL

#define NVIC_ISER0                    							*(vuint32 *)(NVIC_BASE + 0x00)
#define NVIC_ISER1                    							*(vuint32 *)(NVIC_BASE + 0x04)
#define NVIC_ISER2                    							*(vuint32 *)(NVIC_BASE + 0x08)
#define NVIC_ICER0                    							*(vuint32 *)(NVIC_BASE + 0x80)
#define NVIC_ICER1                    							*(vuint32 *)(NVIC_BASE + 0x84)
#define NVIC_ICER2                    							*(vuint32 *)(NVIC_BASE + 0x88)

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
	volatile uint32 EXTICR[4];
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

//*********************************  Macros  *********************************//

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


//@ref EXTI_IRQ_define

#define EXTI0_IRQ						6
#define EXTI1_IRQ						7
#define EXTI2_IRQ						8
#define EXTI3_IRQ						9
#define EXTI4_IRQ						10
#define EXTI5_IRQ						23
#define EXTI6_IRQ						23
#define EXTI7_IRQ						23
#define EXTI8_IRQ						23
#define EXTI9_IRQ						23
#define EXTI10_IRQ						40
#define EXTI11_IRQ						40
#define EXTI12_IRQ						40
#define EXTI13_IRQ						40
#define EXTI14_IRQ						40
#define EXTI15_IRQ						40


#define NVIC_IRQ6_EXTI0_ENABLE									 NVIC_ISER0 |= (1<<EXTI0_IRQ)
#define NVIC_IRQ7_EXTI1_ENABLE									 NVIC_ISER0 |= (1<<EXTI1_IRQ)
#define NVIC_IRQ8_EXTI2_ENABLE									 NVIC_ISER0 |= (1<<EXTI2_IRQ)
#define NVIC_IRQ9_EXTI3_ENABLE									 NVIC_ISER0 |= (1<<EXTI3_IRQ)
#define NVIC_IRQ10_EXTI4_ENABLE									 NVIC_ISER0 |= (1<<EXTI4_IRQ)
#define NVIC_IRQ23_EXTI5_ENABLE									 NVIC_ISER0 |= (1<<EXTI5_IRQ)
#define NVIC_IRQ23_EXTI6_ENABLE									 NVIC_ISER0 |= (1<<EXTI6_IRQ)
#define NVIC_IRQ23_EXTI7_ENABLE									 NVIC_ISER0 |= (1<<EXTI7_IRQ)
#define NVIC_IRQ23_EXTI8_ENABLE									 NVIC_ISER0 |= (1<<EXTI8_IRQ)
#define NVIC_IRQ23_EXTI9_ENABLE									 NVIC_ISER0 |= (1<<EXTI9_IRQ)
#define NVIC_IRQ40_EXTI10_ENABLE								 NVIC_ISER1 |= (1<<(EXTI10_IRQ - 32)) //NEW REGESTER
#define NVIC_IRQ40_EXTI11_ENABLE								 NVIC_ISER1 |= (1<<(EXTI11_IRQ - 32))
#define NVIC_IRQ40_EXTI12_ENABLE								 NVIC_ISER1 |= (1<<(EXTI12_IRQ - 32))
#define NVIC_IRQ40_EXTI13_ENABLE								 NVIC_ISER1 |= (1<<(EXTI13_IRQ - 32))
#define NVIC_IRQ40_EXTI14_ENABLE								 NVIC_ISER1 |= (1<<(EXTI14_IRQ - 32))
#define NVIC_IRQ40_EXTI15_ENABLE								 NVIC_ISER1 |= (1<<(EXTI15_IRQ - 32))


#define NVIC_IRQ6_EXTI0_DISABLE									 NVIC_ICER0 |= (1<<EXTI0_IRQ)
#define NVIC_IRQ7_EXTI1_DISABLE									 NVIC_ICER0 |= (1<<EXTI1_IRQ)
#define NVIC_IRQ8_EXTI2_DISABLE									 NVIC_ICER0 |= (1<<EXTI2_IRQ)
#define NVIC_IRQ9_EXTI3_DISABLE									 NVIC_ICER0 |= (1<<EXTI3_IRQ)
#define NVIC_IRQ10_EXTI4_DISABLE								 NVIC_ICER0 |= (1<<EXTI4_IRQ)
#define NVIC_IRQ23_EXTI5_DISABLE								 NVIC_ICER0 |= (1<<EXTI5_IRQ)
#define NVIC_IRQ23_EXTI6_DISABLE								 NVIC_ICER0 |= (1<<EXTI6_IRQ)
#define NVIC_IRQ23_EXTI7_DISABLE								 NVIC_ICER0 |= (1<<EXTI7_IRQ)
#define NVIC_IRQ23_EXTI8_DISABLE								 NVIC_ICER0 |= (1<<EXTI8_IRQ)
#define NVIC_IRQ23_EXTI9_DISABLE								 NVIC_ICER0 |= (1<<EXTI9_IRQ)
#define NVIC_IRQ40_EXTI10_DISABLE								 NVIC_ICER1 |= (1<<(EXTI10_IRQ - 32)) //NEW REGESTER
#define NVIC_IRQ40_EXTI11_DISABLE								 NVIC_ICER1 |= (1<<(EXTI11_IRQ - 32))
#define NVIC_IRQ40_EXTI12_DISABLE								 NVIC_ICER1 |= (1<<(EXTI12_IRQ - 32))
#define NVIC_IRQ40_EXTI13_DISABLE								 NVIC_ICER1 |= (1<<(EXTI13_IRQ - 32))
#define NVIC_IRQ40_EXTI14_DISABLE								 NVIC_ICER1 |= (1<<(EXTI14_IRQ - 32))
#define NVIC_IRQ40_EXTI15_DISABLE								 NVIC_ICER1 |= (1<<(EXTI15_IRQ - 32))


#endif


