//Mark Madden
//14192986
//mcmpw6
//lab 10
//lab d
//balancedBST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

int main(int argc, char* argv[]){

	if(argc<2){ // error check
		printf("Not enough inputs");
		return 0;
		}

	int i;
	int low;
	int high;
	int *a=malloc(sizeof(int));
	//int a[100];

	BST* tree=NULL;

	FILE* file=fopen(argv[1],"r");	// open file
	if(file==NULL){
		printf("File could not be open\n");
	}
	
	int size;
	fscanf(file,"%d",&size);
	for(i=0;i<size;i++){
	fscanf(file,"%d",(a+i));
	}
	tree=build_balanced_tree(a,0,size-1);
	print(tree);
	//tree=delete_node(tree,atoi(argv[2]));

	printf("Tree without %d\n",atoi(argv[2]));
	print(tree);

	//fclose(file);
	return 0;

}
