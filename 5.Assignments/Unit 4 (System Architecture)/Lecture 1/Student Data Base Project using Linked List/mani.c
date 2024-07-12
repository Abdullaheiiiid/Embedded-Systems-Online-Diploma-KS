#include <stdio.h>
#include <stdlib.h>
#include "data_base.h"
#include "Type_Definitions.h"

#define  DPRINTF(...)      fflush(stdin);\
						   fflush(stdout);\
						   printf(__VA_ARGS__);\
						   fflush(stdin);\
						   fflush(stdout);\

int main(void){
	DB_Main_Menu();
}
