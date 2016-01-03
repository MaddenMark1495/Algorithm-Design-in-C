#ifndef QUEUE_H_
#define QUEUE_H_
//usual .h file
typedef struct node_{
	char* data;
	struct node_ *next;
}Queue;
Queue* enqueue(Queue*,char*);
char* dequeue(Queue**);
int size(Queue*);

#endif
