//*********************************  LIBRARIES  ******************************//

#include "KEYPAD.h"

//****************************  KPD GLOBAL VARIABLE  *************************//

uint8 ROW[4] = {ROW0,ROW1,ROW2,ROW3};
uint8 COL[4] = {COL0,COL1,COL2,COL3};
uint8 KEYS[4][4] = {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'C','0','=','+'}};


//*********************************  KPD APIs  *******************************//

void KPD_Init(){
	for(int i = 0 ; i < 4 ; i++){
		GPIO_SET_PIN_DIRECTION(KPD_DDR, ROW[i], PIN_INPUT);
		GPIO_SET_PIN_DIRECTION(KPD_DDR, COL[i], PIN_OUTPUT);
	}
	GPIO_SET_PORT_VALUE(KPD_PORT, 0xFF);
}

uint8 KPD_Get_Key(){

	for(int i = 0 ; i < 4 ; i++){

		for(int j = 0 ; j < 4 ; j++)
			GPIO_SET_PIN_VALUE(KPD_PORT,COL[j],LOGIC_HIGH);
		GPIO_SET_PIN_VALUE(KPD_PORT,COL[i],LOGIC_LOW);

		for(int j = 0 ; j < 4 ; j++){

			if(GPIO_GET_PIN_VALUE(KPD_PIN, ROW[j]) == LOGIC_LOW){
				while(GPIO_GET_PIN_VALUE(KPD_PIN, ROW[j]) == LOGIC_LOW);
				return KEYS[j][i];
			}
		}

	}
	return 'E';
}
