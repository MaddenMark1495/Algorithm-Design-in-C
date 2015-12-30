#include <stdlib.h>
#include "stack.h"

/**
 * Return: A pointer to an empty stack
 */
stack* create_stack() {

	stack* temp=malloc(sizeof(stack));
	temp->size=0;
	temp->stack=NULL;
	return temp;

}


/**
 * Param: s   - A pointer to a stack
 * Param: val - A value to be pushed onto the stack
 *
 * Return: None
 */
void push(stack *s, int val) {

	node* temp=malloc(sizeof(node));
	temp->data = val;
	temp->next=s->stack;
	s->stack=temp;
	s->size++;

}


/**
 * Param: s -  A pointer to a stack
 *
 * Return:  None
 *
 * Deletes removes the top node of the stack. 
 * If the stack is empty, nothing should happen. 
 */
void pop(stack *s) {
	
	if(s->size==0){
		return;
		}
	
	node* temp = s->stack;
	s->stack = s->stack->next;
	free(temp);


}

/**
 * Param: s - A pointer to a stack
 *
 * Return: The value stored at the top of a stack
 * 
 * This function should return the value at the top of
 * a non-empty stack without modifying it
 */
int top(stack *s) {

	node* temp = s->stack;
	int value = temp->data;
	return value;
}

/**
 * Param: s - A pointer to a stack
 *
 * Return: 1 if the stack is empty, 0 otherwise
 */
int isEmpty(stack *s) {
    return s->stack == NULL ? 1 : 0;
}
