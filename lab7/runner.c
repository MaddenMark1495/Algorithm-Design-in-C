#include<stdio.h>
#include<stdlib.h>
#include "set.h"

Set* create_set(char*);

int main(int argc, char* argv[]){
	
	int i;
	Set* create1=NULL;
	Set* create2=NULL;
	if(argc!=4){
		printf("Not Enough inputs\n");
		return 0;
		}
	create1=create_set(argv[1]);
	printf("First Step\n");
	print_list(create1);
	create2=create_set(argv[2]);
	printf("Second Step\n");
	print_list(create2);
}


Set* create_set(char* filename)
{
	int i=0;
	int  temp;
	Set* set=NULL;
	FILE* file=fopen(filename,"r");
	if (file==NULL){
		return 0;
	}
	while(!feof(file))
	{
		fscanf(file,"%d",&temp);
		set=set_insert(set,temp);
	}
	return set;
}

