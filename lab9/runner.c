//Mark Madden
//14182986
//mcmpw6
//11/4/14
//BST

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "bst.h"

int main(int argc, char* argv[])
{
	if(argc<2){ // error check
		printf("Not enough inputs");
		return 0;
		}
		
	BST* tree=NULL;
	int data;
	int number;
	FILE* file = fopen(argv[1],"r");  //open file

	while(fscanf(file,"%d",&data)!=EOF){ // scan file into data
		tree=insert(tree,data);
	}
	inorder(tree); //call inorder
	number=atoi(argv[2]); // converts string into int
	BST* result;
	result=find(tree,number);
	if(result!=NULL){ // call find function in if statement
		printf("\n %d was found\n",number); 
		
	}
	else{
		printf("\n%d was not found\n",number);
	}
		
	fclose(file); // close file
	destroy_tree(tree); // calls destroy tree function
	return 0;
	// end of program
}
