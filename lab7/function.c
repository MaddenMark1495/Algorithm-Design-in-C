#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "set.h"

Set* set_insert(Set* set,int number){
	Set* head = set;
	while(set!=NULL){
		if(set->data==number){
			return head;
		}
		else{
		set=set->next;
		}
	}
	Set* new = (Set*)malloc(sizeof(Set));
	
	new->data=number;
	new->next=head;
	return new;
}
/*Set* set_remove(Ser* set,int number)
{
}
*/
/*Set* set_intersection(Set* first, Set* secound)
{
}
*/
void print_list(Set* list)
{
	while(list!=NULL){
		printf("%d -> ",list->data);
		list=list->next;
	}
	printf("NULL\n");
}
void free_list(Set* list)
{
	while(list!=NULL){
		Set* temp = list->next;
		free(list);
		list=temp;
	}
}
