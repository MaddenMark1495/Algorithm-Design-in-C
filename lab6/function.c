//MArk Madden
//14183986
//mcmpw6
//lab d
//lab 6
//10/24/14
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"



node* insert_at_head(node* list, int number)
{
	node* new_node=(node*)malloc(sizeof(node));
	if(new_node==NULL){
		return NULL;
	}
	new_node->data=number;
	new_node->next=list;
	
	return new_node;
}
void print_list(node* head)
{
	while(head!=NULL)
	{
		printf("%d->",head->data);
		head=head->next;
	}
		printf("NULL\n");
}
void free_list(node* list)
{
	while(list!=NULL){
		node* temp = list->next;
		free(list);
		list=temp;
	}
}
