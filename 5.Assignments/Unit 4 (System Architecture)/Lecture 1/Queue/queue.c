#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define  Dprintf(...)      fflush(stdin);\
						   fflush(stdout);\
						   printf(__VA_ARGS__);\
						   fflush(stdin);\
						   fflush(stdout);\

ptrdatatype * LL_Head = NULL;

Queue_Error Queue_Init(datatype* array_buffer, Queue_Buffer* Queue_buffer, uint32 array_length){
	#if (Queue_imp_mode)
			Queue_buffer->base = Queue_buffer->head = Queue_buffer->tail = LL_Head;
			Queue_buffer->length = array_length;
			Queue_buffer->counter = 0;
			return No_Error;
	#else
		Queue_buffer->base = Queue_buffer->head = Queue_buffer->tail = (datatype *) array_buffer;
		Queue_buffer->length = array_length;
		Queue_buffer->counter = 0;
		return No_Error;
	#endif
}

Queue_Error Queue_IsNull(Queue_Buffer* buffer){

	return No_Error;
}

Queue_Error Queue_Enqueue(datatype data, Queue_Buffer* buffer){
	#if (Queue_imp_mode)
		if(Queue_IsNull(buffer) == Null_Error){
			Dprintf("======================\n");
			Dprintf("    Queue is Null!\n");
			Dprintf("======================\n");
			return Null_Error;
		}
		else if(Queue_IsFull(buffer) == Full_Error){
			Dprintf("======================\n");
			Dprintf("    Queue is Full!\n");
			Dprintf("======================\n");
			return Full_Error;
		}
		else
		{
			if(!buffer->counter){
				struct Linked_List * temp = (struct Linked_List *) malloc (sizeof(struct Linked_List));
				buffer->head = temp;
				LL_Head = temp;
				buffer->base = temp;
				buffer->tail = temp;
			}
			else{
				struct Linked_List * temp = (struct Linked_List *) malloc (sizeof(struct Linked_List));
				buffer->head->next = temp;
				buffer->head = temp;

			}
			buffer->head->next = NULL;
			buffer->head->data = data;
			buffer->counter++;
			return No_Error;
		}
	#else
		if(Queue_IsFull(buffer) == Full_Error){
			Dprintf("======================\n");
			Dprintf("    Queue is Full!\n");
			Dprintf("======================\n");
			return Full_Error;
		}
		else
		{
			buffer->counter++;
			*buffer->head = data;
			buffer->head = buffer->base +((++buffer->head - buffer->base) % buffer->length);
			return No_Error;
		}

	#endif
}

Queue_Error Queue_IsFull(Queue_Buffer* buffer)
{
	if(buffer->counter == buffer->length)
		return Full_Error;
	return No_Error;
}

Queue_Error Queue_Dequeue(datatype * data, Queue_Buffer* buffer){
	#if (Queue_imp_mode)
		if(Queue_IsNull(buffer) == Null_Error){
			Dprintf("======================\n");
			Dprintf("    Queue is Null!\n");
			Dprintf("======================\n");
			return Null_Error;
		}
		else if(Queue_IsEmpty(buffer) == Empty_Error){
			Dprintf("======================\n");
			Dprintf("    Queue is Empty!\n");
			Dprintf("======================\n");
			return Empty_Error;
		}
		else
		{
			struct Linked_List * temp = LL_Head;
			if(buffer->head == buffer->tail){
				*data = buffer->tail->data;
				free(temp);

				//datatype* array_buffer;
				//uint32 array_length = 5;
				//return Queue_Init(array_buffer, buffer,array_length);
				buffer->counter = 0;
				return No_Error;
			}else{
				*data = buffer->tail->data;
				buffer->tail = buffer->tail->next;
				LL_Head = buffer->base = buffer->tail;
				free(temp);

				buffer->counter--;
				return No_Error;
			}
		}
	#else
		if(Queue_IsEmpty(buffer) == Empty_Error){
			Dprintf("======================\n");
			Dprintf("   Queue is Empty!\n");
			Dprintf("======================\n");
			return Empty_Error;
		}
		else
		{
			buffer->counter--;
			*data = *(buffer->tail);
			buffer->tail = buffer->base +((++buffer->tail - buffer->base) % buffer->length);
			return No_Error;
		}

	#endif
}

Queue_Error Queue_Front(datatype* data, Queue_Buffer* buffer){
	#if (Queue_imp_mode)
		if(Queue_IsNull(buffer) == Null_Error){
			Dprintf("======================\n");
			Dprintf("    Queue is Null!\n");
			Dprintf("======================\n");
			return Null_Error;
		}
		else if(Queue_IsEmpty(buffer) == Empty_Error){
			Dprintf("======================\n");
			Dprintf("    Queue is Empty!\n");
			Dprintf("======================\n");
			return Empty_Error;
		}
		else
		{
			*data = buffer->tail->data;
			return No_Error;
		}
	#else
		if(Queue_IsEmpty(buffer) == Empty_Error){
			Dprintf("======================\n");
			Dprintf("   Queue is Empty!\n");
			Dprintf("======================\n");
			return Empty_Error;
		}
		else
		{
			*data = *(buffer->tail);
			return No_Error;
		}

	#endif
}

Queue_Error Queue_Back(datatype* data, Queue_Buffer* buffer){
	#if (Queue_imp_mode)
		if(Queue_IsNull(buffer) == Null_Error){
			Dprintf("======================\n");
			Dprintf("    Queue is Null!\n");
			Dprintf("======================\n");
			return Null_Error;
		}
		else if(Queue_IsEmpty(buffer) == Empty_Error){
			Dprintf("======================\n");
			Dprintf("    Queue is Empty!\n");
			Dprintf("======================\n");
			return Empty_Error;
		}
		else
		{
			*data = buffer->head->data;
			return No_Error;
		}
	#else
		if(Queue_IsEmpty(buffer) == Empty_Error){
			Dprintf("======================\n");
			Dprintf("   Queue is Empty!\n");
			Dprintf("======================\n");
			return Empty_Error;
		}
		else
		{
			*data = *(buffer->head);
			return No_Error;
		}

	#endif
}

Queue_Error Queue_IsEmpty(Queue_Buffer* buffer)
{
	if(!buffer->counter)
		return Empty_Error;
	return No_Error;

}

int Queue_Size(Queue_Buffer* buffer){
	return buffer->counter;
}
Queue_Error Queue_Clear(Queue_Buffer* buffer){
	if(Queue_IsEmpty(buffer) == Empty_Error){
		Dprintf("======================\n");
		Dprintf("   Queue is Empty!\n");
		Dprintf("======================\n");
		return Empty_Error;
	}
	else{
		#if (Queue_imp_mode)
			datatype data;
			while(Queue_Dequeue(&data, buffer) != Empty_Error);
		#else
			buffer->counter = 0;
			buffer->tail = buffer->head = buffer->base;
		#endif
		return No_Error;
	}

}
