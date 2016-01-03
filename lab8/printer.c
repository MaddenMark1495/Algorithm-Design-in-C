//Mark Madden
//lab d
//mcmpw6
//14182986
//Queue

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include "queue.h"

Queue* print(Queue* queue);
int main(int argc, char* argv[]){

	if(argc<2){ // error check
		return 0;
		}

	char a[100];
	Queue* queue=NULL;
	FILE* file=fopen(argv[1],"r"); // open file
	while(fgets(a,100,file)!=NULL) //scan file
	{
		queue=enqueue(queue,a);
		if(size(queue)==3){
			queue=print(queue);
		}
	}
	queue=print(queue);
	fclose(file);
	return 0;
}
Queue* print(Queue* queue)
{
	sleep(1);//delay
	while(queue!=NULL){

	printf("%s",dequeue(&queue)); //opens deque



	}
return queue;
}
