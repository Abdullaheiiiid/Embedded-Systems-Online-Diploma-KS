#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define  Dprintf(...)      fflush(stdin);\
						   fflush(stdout);\
						   printf(__VA_ARGS__);\
						   fflush(stdin);\
						   fflush(stdout);\

#define buffer_length        5

void array_stack(datatype* array_buffer,Stack_Buffer * stack1);

void linked_list_stack(Stack_Buffer * stack2);

int main(){

	Stack_Buffer *stack1, *stack2;
	datatype array_buffer[buffer_length];
	linked_list_stack(stack2);
	//array_stack(array_buffer,&stack2);

	return 0;
}

void array_stack(datatype* array_buffer,Stack_Buffer * stack1){
	Stack_Init(array_buffer,&stack1,buffer_length);
	datatype data =0;
	Stack_Pop(&data,stack1);
	Stack_Push(10, stack1);
	Stack_Push(11,stack1);
	Stack_Push(12, stack1);
	Stack_Push(13, stack1);
	Stack_Push(13, stack1);
	Stack_Push(13, stack1);
	Stack_Push(13, stack1);
	for(int i = 0; i<buffer_length ; i++){
		Dprintf("element %d: %d \n",i+1,array_buffer[i]);
	}
	Stack_Pop(&data,stack1);
	Dprintf("\npop element 1 : %d\n",data);
	Dprintf("stack size : %d\n",Stack_Size(stack1));
	Stack_Clear(stack1);
	Dprintf("stack size : %d\n",Stack_Size(stack1));
	Stack_Pop(&data,stack1);
	Stack_Push(0, stack1);
	Stack_Pop(&data,stack1);
	Dprintf("\npop element 2 : %d\n",data);
	Stack_Pop(&data,stack1);
}

void linked_list_stack(Stack_Buffer * stack2){
	datatype *ptr;
	Stack_Init(ptr,stack2,buffer_length);
	datatype data =0 ;

	Stack_Pop(&data,stack2);
		Stack_Push(10, stack2);
		Stack_Push(11, stack2);
		Stack_Push(12, stack2);
		Stack_Push(13, stack2);
		Stack_Peek(&data,stack2);
		Dprintf("\npeek element 1 : %d\n",data);
		Stack_Push(13, stack2);
		Stack_Push(13, stack2);
		Stack_Push(13, stack2);
		Stack_Pop(&data,stack2);
		Dprintf("\npop element 1 : %d\n",data);
		Dprintf("stack size : %d\n",Stack_Size(stack2));
		Stack_Clear(stack2);
		Dprintf("stack size : %d\n",Stack_Size(stack2));
		Stack_Pop(&data,stack2);
		Stack_Push(60, stack2);
		Stack_Pop(&data,stack2);
		Dprintf("\n\n\npop element 2 : %d\n",data);
		Stack_Pop(&data,stack2);
}
