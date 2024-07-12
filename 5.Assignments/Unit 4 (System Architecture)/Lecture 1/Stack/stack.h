#include "Type_Definitions.h"
#ifndef STACK_H
#define STACK_H

#define  Dprintf(...)      fflush(stdin);\
						   fflush(stdout);\
						   printf(__VA_ARGS__);\
						   fflush(stdin);\
						   fflush(stdout);\

#define stack_imp_mode      1     // 0 for array implementation  ------  1 for linked list implementation
#define datatype            uint32
#define ptrdatatype         struct Linked_List  // if want array implementation replace with (datatype)

#if (stack_imp_mode)
	struct Linked_List{
		datatype data;
		struct Linked_List * next;
	};
#endif

typedef enum{
	No_Error,
	Full_Error,
	Null_Error,
	Empty_Error
}Stack_Error;

typedef struct{
	int length;
	int counter;
	ptrdatatype * base;
	ptrdatatype * top;
}Stack_Buffer;

Stack_Error Stack_Init(datatype* array_buffer, Stack_Buffer* stack_buffer, uint32 array_length);
Stack_Error Stack_IsNull(Stack_Buffer* buffer);
Stack_Error Stack_Push(datatype data, Stack_Buffer* buffer);
Stack_Error Stack_IsFull(Stack_Buffer* buffer);
Stack_Error Stack_Pop(datatype* data, Stack_Buffer* buffer);
Stack_Error Stack_Peek(datatype* data, Stack_Buffer* buffer);
Stack_Error Stack_IsEmpty(Stack_Buffer* buffer);
int Stack_Size(Stack_Buffer* buffer);
Stack_Error Stack_Clear(Stack_Buffer* buffer);

#endif
