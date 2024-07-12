#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define  Dprintf(...)      fflush(stdin);\
						   fflush(stdout);\
						   printf(__VA_ARGS__);\
						   fflush(stdin);\
						   fflush(stdout);\

#define buffer_length        5

void array_Queue(datatype* array_buffer,Queue_Buffer * Queue1);

//void linked_list_Queue(Queue_Buffer * Queue2);

int main(){

	Queue_Buffer * Queue1,* Queue2;
	datatype array_buffer[buffer_length];
	linked_list_Queue(Queue2);
	//array_Queue(array_buffer,Queue2);

	return 0;
}

void array_Queue(datatype* array_buffer,Queue_Buffer * Queue1){
	Queue_Init(array_buffer,Queue1,buffer_length);
	datatype data =0;
	Queue_Dequeue(&data,Queue1);
	Queue_Enqueue(100, Queue1);
	Queue_Enqueue(11, Queue1);
	Queue_Enqueue(12, Queue1);
	Queue_Enqueue(13, Queue1);
	Queue_Enqueue(13, Queue1);
	Queue_Enqueue(13, Queue1);
	Queue_Enqueue(13, Queue1);
	for(int i = 0; i<buffer_length ; i++){
		Dprintf("element %d: %d \n",i+1,array_buffer[i]);
	}
	Queue_Dequeue(&data,Queue1);
	Dprintf("\nDequeue element 1 : %d\n",data);
	Dprintf("Queue size : %d\n",Queue_Size(Queue1));
	Queue_Clear(Queue1);
	Dprintf("Queue size : %d\n",Queue_Size(Queue1));
	Queue_Dequeue(&data,Queue1);
	Queue_Enqueue(0, Queue1);
	Queue_Dequeue(&data,Queue1);
	Dprintf("\nDequeue element 2 : %d\n",data);
	Queue_Dequeue(&data,Queue1);
}

void linked_list_Queue(Queue_Buffer * Queue2){
	datatype *ptr;
	Queue_Init(ptr,Queue2,buffer_length);
	datatype data =0 ;

	Queue_Dequeue(&data,Queue2);
		Queue_Enqueue(10, Queue2);
		Queue_Enqueue(11, Queue2);
		Queue_Enqueue(12, Queue2);
		Queue_Enqueue(13, Queue2);
		Queue_Front(&data,Queue2);
		Dprintf("\nFront element 1 : %d\n",data);
		Queue_Back(&data,Queue2);
		Dprintf("\nBack element 1 : %d\n",data);
		Queue_Enqueue(13, Queue2);
		Queue_Enqueue(13, Queue2);
		Queue_Enqueue(13, Queue2);
		Queue_Dequeue(&data,Queue2);
		Dprintf("\nDequeue element 1 : %d\n",data);
		Dprintf("Queue size : %d\n",Queue_Size(Queue2));
		Queue_Clear(Queue2);
		Dprintf("Queue size : %d\n",Queue_Size(Queue2));
		Queue_Dequeue(&data,Queue2);
		Queue_Enqueue(60, Queue2);
		Queue_Dequeue(&data,Queue2);
		Dprintf("\n\n\nDequeue element 2 : %d\n",data);
		Queue_Dequeue(&data,Queue2);
}

