//*********************************  LIBRARIES  ******************************//

#include "LCD.h"

//*********************************  LCD APIs  *******************************//

uint8 locx = 0;
uint8 locy = 0;

void LCD_Init(){

	_delay_ms(20);
	LCD_CTRL_DDR |= (1<<LCD_RW_PIN)|(1<<LCD_RS_PIN)|(1<<LCD_EN_PIN);
	LCD_CTRL_PORT &= ~((1<<LCD_RW_PIN)|(1<<LCD_RS_PIN)|(1<<LCD_EN_PIN));

	_delay_ms(20);
	LCD_Clear_Screen();

#if EIGHT_PINS_MODE
	LCD_DATA_DDR = 0XFF;

	LCD_Send_CMD(EIGHT_BIT_MODE_TWO_LINE);

#elif FOUR_PINS_MODE
	LCD_DATA_DDR |= (1<<PIN0)|(1<<PIN1)|(1<<PIN2)|(1<<PIN3);
	_delay_ms(40);
	LCD_Send_CMD(FOUR_BIT_MODE);
	LCD_Send_CMD(FOUR_BIT_MODE_TWO_LINE);

#endif
	_delay_ms(40);
	LCD_Send_CMD(ENTRY_MODE);
	LCD_Send_CMD(RESET_CURSOR_FIRST_LINE);
	LCD_Send_CMD(CURSOR_BLINKING);
}

void LCD_Send_CMD(uint8 CMD){

#if EIGHT_PINS_MODE

	LCD_DATA_PORT = CMD;
	LCD_CTRL_PORT &= ~((1<<LCD_RS_PIN)|(1<<LCD_RW_PIN));
	LCD_Ready();

#elif FOUR_PINS_MODE

	//	LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0)|(CMD >> 4);
	uint8 x = CMD;
	CMD = x;
	LCD_DATA_PORT = GET_BIT(CMD, PIN4) ? LCD_DATA_PORT | (1<<PIN0): LCD_DATA_PORT & ~(1<<PIN0);
	CMD = x;
	LCD_DATA_PORT = GET_BIT(CMD, PIN5) ? LCD_DATA_PORT | (1<<PIN1): LCD_DATA_PORT & ~(1<<PIN1);
	CMD = x;
	LCD_DATA_PORT = GET_BIT(CMD, PIN6) ? LCD_DATA_PORT | (1<<PIN2): LCD_DATA_PORT & ~(1<<PIN2);
	CMD = x;
	LCD_DATA_PORT = GET_BIT(CMD, PIN7) ? LCD_DATA_PORT | (1<<PIN3): LCD_DATA_PORT & ~(1<<PIN3);

	LCD_CTRL_PORT &= ~((1<<LCD_RS_PIN)|(1<<LCD_RW_PIN));
	LCD_Ready();

	//	LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0)|(CMD & 0x0F);
	CMD = x;
	LCD_DATA_PORT = GET_BIT(CMD, PIN0) ? LCD_DATA_PORT | (1<<PIN0): LCD_DATA_PORT & ~(1<<PIN0);
	CMD = x;
	LCD_DATA_PORT = GET_BIT(CMD, PIN1) ? LCD_DATA_PORT | (1<<PIN1): LCD_DATA_PORT & ~(1<<PIN1);
	CMD = x;
	LCD_DATA_PORT = GET_BIT(CMD, PIN2) ? LCD_DATA_PORT | (1<<PIN2): LCD_DATA_PORT & ~(1<<PIN2);
	CMD = x;
	LCD_DATA_PORT = GET_BIT(CMD, PIN3) ? LCD_DATA_PORT | (1<<PIN3): LCD_DATA_PORT & ~(1<<PIN3);

	LCD_CTRL_PORT &= ~((1<<LCD_RS_PIN)|(1<<LCD_RW_PIN));
	LCD_Ready();

#endif
}
void LCD_Clear_Screen (){
	LCD_GotoXY(0,0);
	LCD_Send_CMD(CLEAR_DISPLAY_CURSOR_DDRAM);
	LCD_Send_CMD(RESET_CURSOR_FIRST_LINE);
}

void LCD_GotoXY(uint8 line, uint8 position ){
	locy = line;
	locx = position;
	if(line == 0){
		if(position <= 15 && position >= 0){
			LCD_Send_CMD(RESET_CURSOR_FIRST_LINE + position);
		}
	}
	else if(line == 1){
		if(position <= 15 && position >= 0){
			LCD_Send_CMD(RESET_CURSOR_SECOND_LINE + position);
		}
	}
}

void LCD_Send_Char(uint8 Data){

	if(locx == 16 && locy == 0){
		locy = 1;
		locx = 0;
	}
	if(locx == 16 && locy == 1){
		locy = 0;
		locx = 0;
	}
	LCD_GotoXY(locy,locx);
	locx++;

#if EIGHT_PINS_MODE

	LCD_DATA_PORT = Data;
	LCD_CTRL_PORT &= ~(1<<LCD_RW_PIN);
	LCD_CTRL_PORT |= (1<<LCD_RS_PIN);
	LCD_Ready();

#elif FOUR_PINS_MODE

	//	LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0)|(Data >> 4);
	uint8 x = Data;
	Data = x;
	LCD_DATA_PORT = GET_BIT(Data, PIN4) ? LCD_DATA_PORT | (1<<PIN0): LCD_DATA_PORT & ~(1<<PIN0);
	Data = x;
	LCD_DATA_PORT = GET_BIT(Data, PIN5) ? LCD_DATA_PORT | (1<<PIN1): LCD_DATA_PORT & ~(1<<PIN1);
	Data = x;
	LCD_DATA_PORT = GET_BIT(Data, PIN6) ? LCD_DATA_PORT | (1<<PIN2): LCD_DATA_PORT & ~(1<<PIN2);
	Data = x;
	LCD_DATA_PORT = GET_BIT(Data, PIN7) ? LCD_DATA_PORT | (1<<PIN3): LCD_DATA_PORT & ~(1<<PIN3);

	LCD_CTRL_PORT &= ~(1<<LCD_RW_PIN);
	LCD_CTRL_PORT |= (1<<LCD_RS_PIN);
	LCD_Ready();

	//	LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0)|(Data & 0x0F);
	Data = x;
	LCD_DATA_PORT = GET_BIT(Data, PIN0) ? LCD_DATA_PORT | (1<<PIN0): LCD_DATA_PORT & ~(1<<PIN0);
	Data = x;
	LCD_DATA_PORT = GET_BIT(Data, PIN1) ? LCD_DATA_PORT | (1<<PIN1): LCD_DATA_PORT & ~(1<<PIN1);
	Data = x;
	LCD_DATA_PORT = GET_BIT(Data, PIN2) ? LCD_DATA_PORT | (1<<PIN2): LCD_DATA_PORT & ~(1<<PIN2);
	Data = x;
	LCD_DATA_PORT = GET_BIT(Data, PIN3) ? LCD_DATA_PORT | (1<<PIN3): LCD_DATA_PORT & ~(1<<PIN3);

	LCD_CTRL_PORT &= ~(1<<LCD_RW_PIN);
	LCD_CTRL_PORT |= (1<<LCD_RS_PIN);
	LCD_Ready();

#endif
}

void LCD_Send_String(uint8 *Data){

	uint8 cnt = 0;
	while(*Data > 0){
		cnt++;
		LCD_Send_Char(*Data++);
		if(cnt == 16)
			LCD_GotoXY(1,0);
		else if (cnt == 32){
			LCD_Clear_Screen();
			LCD_GotoXY(0,0);
			cnt = 0;
		}
	}
}

void LCD_Send_Number (sint32 Number ){

	char str[10];
	sprintf(str,"%d",Number);
	LCD_Send_String(str);
}

void LCD_Send_Real_Number (float64 Number ){

	uint8 str[10];
	uint8* sign = (Number < 0) ? "-": "";
	float32 num = (Number < 0) ? -1* Number : Number;
	sprintf(str,"%s%d.%04d",sign,(uint32)num,(uint32)((num - (uint32)num) * 10000));
	LCD_Send_String(str);
}

void LCD_Ready (void){

	LCD_CTRL_PORT |= (1<<LCD_EN_PIN);
	_delay_ms(2);
	LCD_CTRL_PORT &= ~(1<<LCD_EN_PIN);
	_delay_ms(2);
}


