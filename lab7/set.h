typedef struct node_{
	int data;
	struct node_* next;
	} Set;


Set* set_insert(Set*,int);
Set* set_remove(Set*,int);
Set* set_intersection(Set*,Set*);
void print_List(Set* list);
void free_list(Set* list);


