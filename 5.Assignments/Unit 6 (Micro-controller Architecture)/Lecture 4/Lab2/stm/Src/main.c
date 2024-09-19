/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif



#define   RCC_BASE            0x40021000
#define   EXTI_BASE           0x40010400
#define   GPIOA_BASE          0x40010800
#define   AFIO_BASE           0x40010000

#define   IOPAEN              2    //clock enable port a
#define   AFIOEN              0    // clock enable alternative function
#define   HSION               0    //HSI ENABLE
#define   PLLON               24   //PLL ENABLE

#define   TR0                 0    //trigger bit for exti0
#define   EXTI0_VECTOR        6    // exti0 vector in nvic

#define   RCC_APB2ENR         *((volatile unsigned int * )(RCC_BASE+0x18))
#define   RCC_CR              *((volatile unsigned int * )(RCC_BASE+0x00))
#define   RCC_CFGR              *((volatile unsigned int * )(RCC_BASE+0x04))

#define   GPIOA_OCH           *((volatile unsigned int* )(GPIOA_BASE+0x04))
#define   GPIOA_CRL           *((volatile unsigned int* )(GPIOA_BASE+0x00))
#define   GPIOA_ODR           *((volatile unsigned int* )(GPIOA_BASE+0x0C))

#define   AFIO_EXTICR1		  *((volatile unsigned int* )(AFIO_BASE+0x08))

#define   EXTI_IMR            *((volatile unsigned int* )(EXTI_BASE+0x00))
#define   EXTI_EMR            *((volatile unsigned int* )(EXTI_BASE+0x04))
#define   EXTI_RTSR           *((volatile unsigned int * )(EXTI_BASE+0x08))
#define   EXTI_FTSR           *((volatile unsigned int* )(EXTI_BASE+0x0C))
#define   EXTI_SWIER          *((volatile unsigned int* )(EXTI_BASE+0x10))
#define   EXTI_PR             *((volatile unsigned int* )(EXTI_BASE+0x14))
#define   NVIC_ISERO          *(volatile unsigned int *)(0xE000E100)
int main(){

	RCC_APB2ENR |= (1<<IOPAEN);
	RCC_APB2ENR |= (1<<AFIOEN);
	GPIOA_CRL |=(1 << 2) ;
	GPIOA_OCH &= 0xFF0FFFFF;
	GPIOA_OCH |= 0x00200000;
	AFIO_EXTICR1 = 0x0;
	EXTI_IMR |= (1<<0);
	EXTI_RTSR |= (1<<TR0);
	NVIC_ISERO |= (1<<EXTI0_VECTOR);

	while(1);

}

void EXTI0_IRQHandler(void){
	GPIOA_ODR ^=(1<<13);
	EXTI_PR |= (1<<0);
}