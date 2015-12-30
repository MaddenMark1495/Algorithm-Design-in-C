#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


BST* build_balanced_tree(int a[],int low,int high){

	int middle;
	//check what if low> high
	if(low>high){
		return NULL;
	}
	//calculate the middle index
	middle=(high+low)/2;
	//create a bst root node and allocate space 
	BST* temp=malloc(sizeof(BST));
	temp->data=a[middle];
	// set up data left and right field of this root node 
	temp->left=build_balanced_tree(a,low,middle-1);
	temp->right=build_balanced_tree(a,middle+1,high);		
	// return root node 
	return temp;
}

BST* delete_node(BST* tree,int data){

if(tree==NULL){
	return NULL;
}

else if(data<tree->data)
{
	delete_node(tree->right,data);
	

}
else if(data>tree->data){
	delete_node(tree->left,data);
	}
	else{
	
	if(tree->left==NULL)
		{
			tree=tree->right;
			return tree;
		}
	if(tree->right==NULL)
		{
			tree=tree->left;
			return tree;
		}
	else{	
			
			BST* treemin=min(tree->right);
			treemin->data=data;
			treemin->right=tree->right;
			return treemin;
			}
		}
	}
BST* min(BST* tree){
	int data;
	data=tree->data;
	// check if root is null
	//hint smallest value of bst should be located 
	if(tree==NULL){
		return NULL;
	}
	else{
		while(tree!=NULL){
		
		tree=tree->left;
		}
	}
	return tree;
}
	
	

void padding(char ch, int n){
	int i;
	
	for(i=0;i<n;i++){
		putchar(ch);
	}
}
void structure(BST* root,int level){
	int i;
	if(root==NULL){
		padding('\t',level);
		puts("~");
	}
	else{
		structure(root->right,level+1);
		padding('\t',level);
		printf("%d\n",root->data);
		structure(root->left,level+1);
		}
	}
	

void print(BST* root){
	structure(root,0);
}


