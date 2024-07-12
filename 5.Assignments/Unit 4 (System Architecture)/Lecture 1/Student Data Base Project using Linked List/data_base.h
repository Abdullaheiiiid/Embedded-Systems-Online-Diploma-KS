#include <stdio.h>
#include <stdlib.h>
#include "Type_Definitions.h"

#define  DPRINTF(...)      fflush(stdin);\
						   fflush(stdout);\
						   printf(__VA_ARGS__);\
						   fflush(stdin);\
						   fflush(stdout);\

#ifndef DATA_BASE_H
#define DATA_BASE_H

#define   Student    struct student

typedef struct{
	uint32 id;
	uint8 name [100];
	float height;
}SStudent;

Student{
	SStudent student_data;
	Student * next;
};



void DB_Main_Menu();
void DB_Add_Student();
void DB_Fill_Data(Student * New_Student);
void DB_Remove_Student();
void DB_View_Students();
void DB_Remove_All();
void DB_Students_Number();
void DB_View_Nth_Student();
void DB_Reverse_View_Nth_Student();

#endif
