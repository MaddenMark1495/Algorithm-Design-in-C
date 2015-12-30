#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"
#include <string.h>
Queue* enqueue(Queue* queue,char* data)
{
	

	if (queue == NULL){
		Queue* head =malloc(sizeof(Queue)); //malloc memory
		head->data=malloc(sizeof(data)*(strlen(data)+1));
		strcpy(head->data,data); //put data into head-data
		head->next=NULL;
		return head;
	}
	else{
		
		queue->next = enqueue(queue->next,data);
		return queue;
	}
}

char* dequeue(Queue** queue)
{
	if(*queue==NULL) //base case
	{
		return NULL;
	}
	else{ //recursive case
	Queue* prev=*queue; 
	*queue=(*queue)->next;
	char* data = prev->data;
	free(prev);
	return data;
	}
	
	
}
int size(Queue* queue)
{
	int num;
	if(queue==NULL){ //base case
		return 0;
		}
		else{ //recursive case
		num=size(queue->next)+1;
		return num;
		}

}
