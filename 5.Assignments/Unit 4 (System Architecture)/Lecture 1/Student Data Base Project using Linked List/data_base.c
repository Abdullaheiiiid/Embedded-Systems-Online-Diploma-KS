#include "data_base.h"

#define  DPRINTF(...)      fflush(stdin);\
		fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdin);\
		fflush(stdout);\

Student * Head = NULL;
uint32 Students_counter = 0;

void DB_Main_Menu(){
	DPRINTF("\n==================================================");
	DPRINTF("\n\t Choose on of the following Options ");
	DPRINTF("\n 1: Add Student ");
	DPRINTF("\n 2: Delete Student ");
	DPRINTF("\n 3: View students ");
	DPRINTF("\n 4: Delete All students");
	DPRINTF("\n 5: Data Base Size ");
	DPRINTF("\n 6: View Nth student ");
	DPRINTF("\n 7: Reverse View Nth student");
	label:
	DPRINTF("\n==================================================");
	DPRINTF("\n Enter Option Number: ");
	sint32 C;
	scanf("%d",&C);
	switch (C){
	case 1:
		DB_Add_Student();
		break;
	case 2:
		DB_Remove_Student();
		break;
	case 3:
		DB_View_Students();
		break;
	case 4:
		DB_Remove_All();
		break;
	case 5:
		DB_Students_Number();
		break;
	case 6:
		DB_View_Nth_Student();
		break;
	case 7:
		DB_Reverse_View_Nth_Students();
		break;
	default:
		printf(" Invalid Number!");
		goto label;
	}
}
void DB_Add_Student(){

	Student * New_Student = (Student * ) malloc(sizeof(Student)), * Last_Student;
	if (!Head){
		Head = New_Student;
	}
	else
	{
		Last_Student = Head;
		while(Last_Student->next)
			Last_Student = Last_Student->next;
		Last_Student->next = New_Student;
	}
	DB_Fill_Data(New_Student);
	New_Student->next = NULL;
	Students_counter++;
	DB_Main_Menu();
}

void DB_Fill_Data(Student * New_Student){

	DPRINTF("\n Enter the ID : ");
	scanf("%u",&(New_Student->student_data.id));

	DPRINTF("\n Enter Student Full Name : ");
	scanf("%s",New_Student->student_data.name);

	DPRINTF("\n Enter height: ");
	scanf("%f",&(New_Student->student_data.height));
}

void DB_Remove_Student(){

	if (!Students_counter){
		DPRINTF("\n There is no Students in Data Base");
	}
	else{
		Student * Prev_Student = NULL, *Current_Student = Head;
		DPRINTF("\n Enter the ID : ");
		uint32 id,flag = 0;
		scanf("%u",&id);

		while(Current_Student){
			if(Current_Student->student_data.id == id){
				if(!Prev_Student){
					Head = Current_Student->next;
				}
				else{
					Prev_Student->next = Current_Student->next;
				}
				free(Current_Student);
				Students_counter--;
				flag = 1;
				break;
			}
			Prev_Student = Current_Student;
			Current_Student = Current_Student->next;
		}
		if(!flag){
			DPRINTF("\n There is no student with id %d",id);
		}
		else{
			DPRINTF("\n Student with id %d is removed successfully",id);
		}
	}
	DB_Main_Menu();
}
void DB_View_Students(){

	Student * Current_Student = Head;
	if (!Students_counter){
		DPRINTF("\n There is no Students in Data Base");
	}
	else
	{
		uint32 i = 0;
		while(Current_Student != NULL){
			DPRINTF("\n Student Number %d", ++i);
			DPRINTF("\n ID: %d", Current_Student->student_data.id);
			DPRINTF("\n Name: %s", Current_Student->student_data.name);
			DPRINTF("\n Height: %f\n", Current_Student->student_data.height);
			Current_Student = Current_Student->next ;

		}
	}
	DB_Main_Menu();
}
void DB_Remove_All(){

	if (!Students_counter){
		DPRINTF("\n There is no Students in Data Base");
	}
	else{
		Student * Prev_Student, *Current_Student = Head;
		while(Current_Student){
			Prev_Student= Current_Student;
			Current_Student= Current_Student->next;
			free(Prev_Student);
		}
		Students_counter = 0;
		Head = NULL;
		DPRINTF("\n All students are removed successfully");
	}
	DB_Main_Menu();
}
void DB_Students_Number(){
	DPRINTF("\n There is %d Students in Data Base", Students_counter);
	DB_Main_Menu();
}
void DB_View_Nth_Student(){

	DPRINTF("\n Enter the ID : ");
	uint32 i;
	scanf("%u",&i);
	// i = 1 <----> Students_counter
	if(Students_counter < i--){
		DPRINTF("\n There is no Student with this index in Data Base");
	}
	else{
		Student *Current_Student = Head;
		while(i){
			Current_Student = Current_Student->next;
			i--;
		}
		DPRINTF("\n Student Found");
		DPRINTF("\n ID: %d", Current_Student->student_data.id);
		DPRINTF("\n Name: %s", Current_Student->student_data.name);
		DPRINTF("\n Height: %f\n", Current_Student->student_data.height);
	}
	DB_Main_Menu();
}

void DB_Reverse_View_Nth_Student(){

	DPRINTF("\n Enter the ID : ");
	uint32 i;
	scanf("%u",&i);
	// i = 1 <----> Students_counter
	if(Students_counter < i--){
		DPRINTF("\n There is no Student with this index in Data Base");
	}
	else{
		i = Students_counter - i - 1;
		Student *Current_Student = Head;
		while(i){
			Current_Student = Current_Student->next;
			i--;
		}
		DPRINTF("\n Student Found");
		DPRINTF("\n ID: %d", Current_Student->student_data.id);
		DPRINTF("\n Name: %s", Current_Student->student_data.name);
		DPRINTF("\n Height: %f\n", Current_Student->student_data.height);
	}
	DB_Main_Menu();
}
