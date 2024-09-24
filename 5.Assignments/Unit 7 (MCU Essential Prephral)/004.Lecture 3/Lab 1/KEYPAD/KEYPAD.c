//*********************************  LIBRARIES  ******************************//

#include "KEYPAD.h"

//****************************  KPD GLOBAL VARIABLE  *************************//

uint8 ROW[4] = {ROW0,ROW1,ROW2,ROW3};
uint8 COL[4] = {COL0,COL1,COL2,COL3};
uint8 KEYS[4][4] = {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'C','0','=','+'}};


//*********************************  KPD APIs  *******************************//

void KPD_Init(){
	KPD_DDR &= ~((1<<ROW0)|(1<<ROW1)|(1<<ROW2)|(1<<ROW3));
	KPD_DDR |= ((1<<COL0)|(1<<COL1)|(1<<COL2)|(1<<COL3));
	KPD_PORT = 0XFF;
}

uint8 KPD_Get_Key(){

	for(int i = 0 ; i < 4 ; i++){

		KPD_PORT |= ((1<<COL[0])|(1<<COL[1])|(1<<COL[2])|(1<<COL[3]));
		KPD_PORT &= ~(1<<COL[i]);

		for(int j = 0 ; j < 4 ; j++){
			if(!(KPD_PIN & (1<<ROW[j]))){

				while(!(KPD_PIN & (1<<ROW[j])));
				return KEYS[j][i];
			}
		}

	}
	return 'E';
}
