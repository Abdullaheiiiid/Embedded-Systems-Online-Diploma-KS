/*
 * main.c
 *
 *  Created on: ٢٠‏/٠٩‏/٢٠٢٤
 *      Author: abdul
 */
#include "ATMEGA32/ATMEGA32.h"
#include "Standard Library/Common Marcos.h"
#include "Standard Library/Type_Definitions.h"
#include "LCD/LCD.h"
#include "KEYPAD/KEYPAD.h"
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	LCD_Init();
	KPD_Init();
	uint32 value;
	uint8 valprev[20];
	uint8 op;
	uint32 result;
	while (1){
		value = KPD_Get_Key();
		while (value == 'E'){
			value = KPD_Get_Key();
		}
		if(value == 'C'){
			LCD_Clear_Screen();
		}
		else if(value == '+' || value == '-' || value == '*' || value == '/' || value == '%'){
			result = atoi(valprev);
			strcpy(valprev,"");
			LCD_Send_Char(' ');
			LCD_Send_Char(value);
			LCD_Send_Char(' ');
			op = value;
		}else{
			if(value == '='){
				int var = atoi(valprev);
				if(op == '+'){
					LCD_Send_Char(' ');
					LCD_Send_Char('=');
					LCD_Send_Char(' ');
					uint32 x = result + var;
					LCD_Send_Number(x);
				}
				if(op == '-'){
					LCD_Send_Char(' ');
					LCD_Send_Char('=');
					LCD_Send_Char(' ');
					uint32 x = result - var;
					LCD_Send_Number(x);
				}
				if(op == '*'){
					LCD_Send_Char(' ');
					LCD_Send_Char('=');
					LCD_Send_Char(' ');
					uint32 x = result * var;
					LCD_Send_Number(x);
				}
				if(op == '/'){
					LCD_Send_Char(' ');
					LCD_Send_Char('=');
					LCD_Send_Char(' ');
					float32 x = (float32)result / (float32)var;
					LCD_Send_Real_Number(x);
				}
				if(op == '%'){
					LCD_Send_Char(' ');
					LCD_Send_Char('=');
					LCD_Send_Char(' ');
					uint32 x = result % var;
					LCD_Send_Number(x);
				}
				result = 0;
				var = 0;
				strcpy(valprev,"");
			}
			else{
				strncat(valprev, &value, 1);
				LCD_Send_Char(value);
			}
		}
	}
	return 0;
}
