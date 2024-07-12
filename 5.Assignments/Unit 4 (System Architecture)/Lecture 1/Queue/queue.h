#include "Type_Definitions.h"
#ifndef QUEUE_H
#define QUEUE_H

#define  Dprintf(...)      fflush(stdin);\
						   fflush(stdout);\
						   printf(__VA_ARGS__);\
						   fflush(stdin);\
						   fflush(stdout);\

#define Queue_imp_mode      1     // 0 for array implementation  ------  1 for linked list implementation
#define datatype            uint32
#define ptrdatatype         struct Linked_List  // if want array implementation replace with (datatype)

#if (Queue_imp_mode)
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
}Queue_Error;

typedef struct{
	uint32 length;
	uint32 counter;
	ptrdatatype * base;
	ptrdatatype * head;
	ptrdatatype * tail;
}Queue_Buffer;

Queue_Error Queue_Init(datatype* array_buffer, Queue_Buffer* Queue_buffer, uint32 array_length);
Queue_Error Queue_IsNull(Queue_Buffer* buffer);
Queue_Error Queue_Enqueue(datatype data, Queue_Buffer* buffer);   //head
Queue_Error Queue_IsFull(Queue_Buffer* buffer);                   //counter == length
Queue_Error Queue_Dequeue(datatype* data, Queue_Buffer* buffer);  //tail
Queue_Error Queue_Front(datatype* data, Queue_Buffer* buffer);    //head
Queue_Error Queue_Back(datatype* data, Queue_Buffer* buffer);     //tail
Queue_Error Queue_IsEmpty(Queue_Buffer* buffer);                  //head == tail
int Queue_Size(Queue_Buffer* buffer);                             //counter
Queue_Error Queue_Clear(Queue_Buffer* buffer);                    //tail & head

#endif
