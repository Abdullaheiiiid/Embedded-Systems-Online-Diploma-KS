#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define  Dprintf(...)      fflush(stdin);\
						   fflush(stdout);\
						   printf(__VA_ARGS__);\
						   fflush(stdin);\
						   fflush(stdout);\

ptrdatatype * LL_Head = NULL;

Stack_Error Stack_Init(datatype* array_buffer, Stack_Buffer* stack_buffer, uint32 array_length){
	#if (stack_imp_mode)
			stack_buffer->base = LL_Head;
			stack_buffer->top = stack_buffer->base;
			stack_buffer->length = array_length;
			stack_buffer->counter = 0;
			return No_Error;
	#else
		stack_buffer->base = (datatype *) array_buffer;
		stack_buffer->top = stack_buffer->base;
		stack_buffer->length = array_length;
		stack_buffer->counter = 0;
		return No_Error;
	#endif
}

Stack_Error Stack_IsNull(Stack_Buffer* buffer){

	return No_Error;
}

Stack_Error Stack_Push(datatype data, Stack_Buffer* buffer){
	#if (stack_imp_mode)
		if(Stack_IsNull(buffer) == Null_Error){
			Dprintf("======================\n");
			Dprintf("    Stack is Null!\n");
			Dprintf("======================\n");
			return Null_Error;
		}
		else if(Stack_IsFull(buffer) == Full_Error){
			Dprintf("======================\n");
			Dprintf("    Stack is Full!\n");
			Dprintf("======================\n");
			return Full_Error;
		}
		else
		{
			if(!buffer->counter){
				struct Linked_List * temp = (struct Linked_List *) malloc (sizeof(struct Linked_List));
				buffer->top = temp;
				LL_Head = temp;
				buffer->base = temp;
			}
			else{
				struct Linked_List * temp = (struct Linked_List *) malloc (sizeof(struct Linked_List));
				buffer->top->next = temp;
				buffer->top = temp;

			}
			buffer->top->next = NULL;
			buffer->top->data = data;
			buffer->counter++;
			return No_Error;
		}
	#else
		if(Stack_IsFull(buffer) == Full_Error){
			Dprintf("======================\n");
			Dprintf("    Stack is Full!\n");
			Dprintf("======================\n");
			return Full_Error;
		}
		else
		{
			buffer->counter++;
			*(buffer->top) = data;
			buffer->top = buffer->top + 1;
			return No_Error;
		}

	#endif
}

Stack_Error Stack_IsFull(Stack_Buffer* buffer)
{
	if(buffer->counter < buffer->length)
		return No_Error;
	return Full_Error;
}

Stack_Error Stack_Pop(datatype* data, Stack_Buffer* buffer){
	#if (stack_imp_mode)
		if(Stack_IsNull(buffer) == Null_Error){
			Dprintf("======================\n");
			Dprintf("    Stack is Null!\n");
			Dprintf("======================\n");
			return Null_Error;
		}
		else if(Stack_IsEmpty(buffer) == Empty_Error){
			Dprintf("======================\n");
			Dprintf("    Stack is Empty!\n");
			Dprintf("======================\n");
			return Empty_Error;
		}
		else
		{
			struct Linked_List * temp = LL_Head;
			if(temp == buffer->top){
				*data = buffer->top->data;
				free(temp);
				//datatype* array_buffer;
				//uint32 array_length = 5;
				//return Stack_Init(array_buffer, buffer,array_length);
				buffer->counter = 0;
				return No_Error;
			}else{
				while(temp->next != buffer->top)
					temp = temp->next;
				*data = buffer->top->data;
				buffer->top = temp;
				temp = temp->next;
				free(temp);
				buffer->top->next = NULL;
				buffer->counter--;
				return No_Error;
			}
		}
	#else
		if(Stack_IsEmpty(buffer) == Empty_Error){
			Dprintf("======================\n");
			Dprintf("   Stack is Empty!\n");
			Dprintf("======================\n");
			return Empty_Error;
		}
		else
		{
			buffer->counter--;
			*data = *(--buffer->top);
			return No_Error;
		}

	#endif
}

Stack_Error Stack_Peek(datatype* data, Stack_Buffer* buffer){
	#if (stack_imp_mode)
		if(Stack_IsNull(buffer) == Null_Error){
			Dprintf("======================\n");
			Dprintf("    Stack is Null!\n");
			Dprintf("======================\n");
			return Null_Error;
		}
		else if(Stack_IsEmpty(buffer) == Empty_Error){
			Dprintf("======================\n");
			Dprintf("    Stack is Empty!\n");
			Dprintf("======================\n");
			return Empty_Error;
		}
		else
		{
			*data = buffer->top->data;
			return No_Error;
		}
	#else
		if(Stack_IsEmpty(buffer) == Empty_Error){
			Dprintf("======================\n");
			Dprintf("   Stack is Empty!\n");
			Dprintf("======================\n");
			return Empty_Error;
		}
		else
		{
			buffer->counter--;
			*data = *(--buffer->top);
			return No_Error;
		}

	#endif
}

Stack_Error Stack_IsEmpty(Stack_Buffer* buffer)
{
	if(buffer->counter)
		return No_Error;
	return Empty_Error;
}

int Stack_Size(Stack_Buffer* buffer){
	return buffer->counter;
}
Stack_Error Stack_Clear(Stack_Buffer* buffer){
	if(Stack_IsEmpty(buffer) == Empty_Error){
		Dprintf("======================\n");
		Dprintf("   Stack is Empty!\n");
		Dprintf("======================\n");
		return Empty_Error;
	}
	else{
		#if (stack_imp_mode)
			datatype data;
			while(Stack_Pop(&data, buffer) != Empty_Error);
		#else
			while(Stack_IsEmpty(buffer) != Empty_Error){
				buffer->counter--;
				buffer->top = buffer->top - 1;
			}

		#endif
		return No_Error;
	}

}
