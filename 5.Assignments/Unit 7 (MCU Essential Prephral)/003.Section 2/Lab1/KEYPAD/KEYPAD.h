#ifndef KEYPAD
#define KEYPAD

//*********************************  LIBRARIES  ******************************//

#include <util/delay.h>
#include "../ATMEGA32/ATMEGA32.h"
#include "../Standard Library/Common Marcos.h"
#include "../Standard Library/Type_Definitions.h"

//*****************************  KPD REGISTERS MAP  **************************//

#define KPD_DDR                               DDRC
#define KPD_PORT                              PORTC
#define KPD_PIN                               PINC
#define ROW0                                  PIN0
#define ROW1                                  PIN1
#define ROW2                                  PIN2
#define ROW3                                  PIN3
#define COL0                                  PIN4
#define COL1                                  PIN5
#define COL2                                  PIN6
#define COL3                                  PIN7

//*********************************  KPD APIs  *******************************//

void KPD_Init();
uint8 KPD_Get_Key();

#endif


