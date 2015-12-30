#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "bst.h"

BST* insert(BST* tree,int data){
	
	if(tree==NULL) // base case
	{	BST* temp=malloc(sizeof(BST)); //malloc memory
		temp->data=data; // finds data
		temp->left=NULL; 
		temp->right=NULL;
		return temp; 
	}

	else if( data<tree->data){
		tree->left = insert(tree->left,data); // call on left szie
		return tree;  
	}
	else {
		tree->right = insert(tree->right,data);	// call on right
		return tree;
	}
	
}

BST* find(BST* tree,int data){
	if(tree== NULL || tree->data==data){ // base case
		return tree;
	}
	else if(tree->data>data)
	{
		
		return find(tree->right,data); // recall function to right 
	}
		
	else{
		
		return find(tree->left,data); // recusrive call on left
	
	}	
}

void inorder(BST* tree){
	if(tree!=NULL)
	{
		inorder(tree->left); //call on left of tree
		printf("%d ",tree->data); // print
		inorder(tree->right); // call on right of tree
		
		
	}
	
}

void destroy_tree(BST* tree){
	if (tree!=NULL){
		destroy_tree(tree->right); // call on right
		destroy_tree(tree->left); // call on left
		free(tree); // free memory
	}
}
