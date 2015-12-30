typedef struct node_{
	int data;
	struct node_* next;
}node;

node* insert_at_head(node*,int);
void print_list(node*);
void free_list(node*);
node* create_list(char*);
