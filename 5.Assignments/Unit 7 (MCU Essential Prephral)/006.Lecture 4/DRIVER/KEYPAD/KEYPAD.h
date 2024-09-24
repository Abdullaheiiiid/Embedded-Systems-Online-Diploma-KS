#ifndef KEYPAD
#define KEYPAD

//*********************************  LIBRARIES  ******************************//

#include "STM32F103C6.h"
#include "Common Marcos.h"
#include "Type_Definitions.h"
#include "GPIO.h"


//*****************************  KPD REGISTERS MAP  **************************//

#define KPD_GPIO                              GPIOB
#define ROW0                                  GPIO_PIN3
#define ROW1                                  GPIO_PIN4
#define ROW2                                  GPIO_PIN5
#define ROW3                                  GPIO_PIN6
#define COL0                                  GPIO_PIN7
#define COL1                                  GPIO_PIN8
#define COL2                                  GPIO_PIN9
#define COL3                                  GPIO_PIN10

//*********************************  KPD APIs  *******************************//

void KPD_Init();
uint8 KPD_Get_Key();

#endif


