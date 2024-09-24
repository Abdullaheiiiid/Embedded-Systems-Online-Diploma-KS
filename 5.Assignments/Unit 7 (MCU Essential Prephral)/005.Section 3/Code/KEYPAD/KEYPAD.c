//*********************************  LIBRARIES  ******************************//

#include "KEYPAD.h"

//****************************  KPD GLOBAL VARIABLE  *************************//

static uint16 ROW[4] = {ROW0,ROW1,ROW2,ROW3};
static uint16 COL[4] = {COL0,COL1,COL2,COL3};
static uint8 KEYS[4][4] = {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'C','0','=','+'}};


//*********************************  KPD APIs  *******************************//

void KPD_Init(){
	for(int i = 0 ; i < 4 ; i++){
		GPIO_OUTPUT_PIN(KPD_GPIO, ROW[i], GPIO_OUTPUT_PUSH_PULL, GPIO_OUTPUT_SPEED_10);
		GPIO_OUTPUT_PIN(KPD_GPIO, COL[i], GPIO_OUTPUT_PUSH_PULL, GPIO_OUTPUT_SPEED_10);
	}

	GPIO_SET_PORT(KPD_GPIO, 0XFF);
}

uint8 KPD_Get_Key(){

	for(int i = 0 ; i < 4 ; i++){
		for(int k = 0 ; k < 4 ; k++){
			GPIO_SET_PIN(KPD_GPIO, COL[k], GPIO_PIN_SET);
		}
		GPIO_SET_PIN(KPD_GPIO, COL[i], GPIO_PIN_RESET);
		for(int j = 0 ; j < 4 ; j++){
			if(GPIO_GET_PIN(KPD_GPIO, ROW[j]) == GPIO_PIN_RESET){
				while(GPIO_GET_PIN(KPD_GPIO, ROW[j]) == GPIO_PIN_RESET);
				return KEYS[j][i];
			}
		}

	}
	return 'E';
}
