//Mark Madden
//mcmpw6
//14182986
//hw4
#include"traverse.h"

BST* build(int a[], int low, int high){ //build tree
	if(low > high)
	{
		return NULL;
	}
	int mid = (low + high)/2;
	BST* root = NULL; 
	root = malloc(sizeof(BST));
	root->data = a[mid];
	root->left = build(a, low, (mid-1));
	root->right = build(a, (mid+1), high);
	return root;
	
}

void destroy(BST* tree){
	if(tree->left != NULL){
		destroy(tree->left);
	}else if(tree->right != NULL){
		destroy(tree->right);
	}else if(tree->left && tree->right == NULL){
		free(tree);
	}
}

Stack* push(Stack* s, BST* node){
	Stack* tem = (Stack*)malloc(sizeof(Stack));
	if(tem == NULL){
		printf("\nMemory allocation error\n"); //error check
		return NULL;
	}
	BST* test = NULL;
	tem->tNode = node; 
	tem->next = s;
	s = tem;
	test = s->tNode;
	return s;
	
}

Stack* pop(Stack* s){
	Stack* tem = NULL;
	printf("%d ", s->tNode->data);
	tem = s;
	s = s->next;
	free(tem);
	return s;
}

Queue* enqueue(Queue* q, BST* tree){ //add to queue
	Queue* new = NULL;
	Queue* current = q;
	if(q == NULL){
		new = malloc(sizeof(Queue));
		new->data = tree;
		new->next = NULL;
	}else{
		q->next = enqueue(q->next, tree);
		return q;
	}
}

Queue* dequeue(Queue* q){ //remove for a queue
	Queue* tem;
	tem = q;
	q = q->next;
	free(tem);
	return q;
}

void inorder(BST* tree){ 
	Stack* s = NULL;
	BST* current = tree;
	int fin = 0;
	while(fin != 1){
		while(current != NULL){
			s = push(s, current);
			current = current->left;
		}
		if(s != NULL && current == NULL){
				current = s->tNode->right;
				s = pop(s);
			}else if(current == NULL && s == NULL){ 
				fin = 1;
			}
	}
}

void preorder(BST* tree){ //preorder
	Stack* s = push(NULL, tree);
	BST* hold;
	while(s != NULL){
		hold = s->tNode;
		s = pop(s);
		
		if(hold->right!=NULL){
			s = push(s, hold->right);
		}
		if(hold->left != NULL){
			s = push(s, hold->left);
		}
	}
}

void breadth(BST* tree){ //breadth first function
	BST* temp = NULL;
	Queue* q = NULL;
	q = enqueue(q, tree);
	while(q!=NULL){
		temp = q->data;
		printf("%d ", temp->data);
		if(temp->left!=NULL){
			q = enqueue(q, temp->left);
		}
		if(temp->right!=NULL){
			q = enqueue(q, temp->right);
		}
		q = dequeue(q);
	}
}

void padding(char ch, int n) // helps prints out top tree
{
	int i;
	for(i=0; i < n; ++i){
		putchar(ch);
	}
}

void structure(BST* root, int level)
{
	int i;
	if(root == NULL){
		padding('\t', level);
		puts("~");
	} else {
		structure(root->right, level+1);
		padding('\t', level);
		printf("%d\n", root->data);
		structure(root->left, level+1);
	}
}

void print(BST* root)
{
	structure(root, 0);
}