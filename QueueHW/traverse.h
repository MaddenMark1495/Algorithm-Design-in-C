/*Mark Madden
Homework 4
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_LEN 100

typedef struct node_{
	int data;
	struct node_* left;
	struct node_* right;
}BST;

typedef struct stack_{
	BST* tNode;
	struct stack_* next;
}Stack;

typedef struct queue_{
	BST* data;
	struct queue_* previous;
	struct queue_* next;
}Queue;

BST* build(int a[], int low, int high);
void preorder(BST* tree);
void inorder(BST* tree);
void breadth(BST* tree);
void destroy(BST* tree);
Stack* push(Stack* s, BST* node);
Stack* pop(Stack* s);
void padding(char ch, int n);
void structure(BST* root, int level);
void print(BST* root);
