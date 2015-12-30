typedef struct node_{
	int data;
	struct node_ *left;
	struct node_ *right;
	}BST;
	
BST* insert(BST*,int);
BST*find(BST*,int);
void inorder(BST*);
void destroy_tree(BST*);

