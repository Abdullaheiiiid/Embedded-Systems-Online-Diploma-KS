#ifndef LCD
#define LCD

//*********************************  LIBRARIES  ******************************//

#include "../STM32F103C6/STM32F103C6.h"
#include "../Standard Library/Common Marcos.h"
#include "../Standard Library/Type_Definitions.h"
#include "../GPIO/GPIO.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*****************************  LCD REGISTERS MAP  **************************//

#define LCD_DATA_GPIO                         GPIOA
#define LCD_CTRL_GPIO                         GPIOA

#define LCD_DATA0_PIN                         GPIO_PIN0
#define LCD_DATA1_PIN                         GPIO_PIN1
#define LCD_DATA2_PIN                         GPIO_PIN2
#define LCD_DATA3_PIN                         GPIO_PIN3

#define LCD_RS_PIN                            GPIO_PIN4
#define LCD_RW_PIN                            GPIO_PIN5
#define LCD_EN_PIN                            GPIO_PIN6

#define EIGHT_PINS_MODE                       0
#define FOUR_PINS_MODE                        1

//*******************************  LCD COMMANDS  *****************************//

//Send 0x02 command which initializes LCD 16x2 in 4-bit mode.

//activate 4bit mode
#define FOUR_BIT_MODE                    0x02

//Function Set: 8-bit, 1 Line, 5x7 Dots
#define EIGHT_BIT_MODE_ONE_LINE          0x30

//Function Set: 8-bit, 2 Line, 5x7 Dots
#define EIGHT_BIT_MODE_TWO_LINE          0x38

//Function Set: 4-bit, 1 Line, 5x7 Dots
#define FOUR_BIT_MODE_ONE_LINE           0x20

//Function Set: 4-bit, 2 Line, 5x7 Dots
#define FOUR_BIT_MODE_TWO_LINE           0x28

//Entry Mode
#define ENTRY_MODE                       0x06

//Display off Cursor off(clearing display without clearing DDRAM content)
#define CLEAR_DISPLAY_CURSOR             0x08

//Clear Display (also clear DDRAM content)
#define CLEAR_DISPLAY_CURSOR_DDRAM       0x01

//Display on Cursor off
#define CURSOR_OFF                       0x0C

//Display on Cursor on
#define CURSOR_ON                        0x0E

//Display on Cursor blinking
#define CURSOR_BLINKING                  0x0F

//Shift entire display left
#define SHIFT_DISPKAY_LEFT               0x18

//Shift entire display right
#define SHIFT_DISPKAY_RIGHT              0x1C

//Move cursor left by one character
#define MOVE_CURSOR_LEFT                 0x10

//Move cursor right by one character
#define MOVE_CURSOR_RIGHT                0x14

//Force cursor to beginning of the first line
#define RESET_CURSOR_FIRST_LINE          0x80

//Force cursor to beginning of second line
#define RESET_CURSOR_SECOND_LINE         0xC0

//Activate second line
#define ACTIVATE_SECOND_LINE             0x3C


GPIO_PINS_config PinCfg ;

//*********************************  LCD APIs  *******************************//

void LCD_Init();
void LCD_Send_CMD(uint8 CMD);
void LCD_Clear_Screen ();
void LCD_GotoXY(uint8 line, uint8 position );
void LCD_Send_Char(uint8 Data);
void LCD_Send_String(uint8 *Data);
void LCD_Send_Number (sint32 Number );
void LCD_Send_Real_Number (float64 Number );
void LCD_Ready(void);
#endif

