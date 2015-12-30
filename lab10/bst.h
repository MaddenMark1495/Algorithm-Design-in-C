typedef struct node_{
	int data;
	struct node_* left;
	struct node_*right;
}BST;

BST* build_balanced_tree(int[],int,int);
BST* delete_node(BST*,int);
BST* min(BST*);
void padding(char,int);
void structure(BST*,int);
void print(BST*); 

