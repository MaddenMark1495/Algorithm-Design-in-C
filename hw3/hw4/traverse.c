/*David Casper
Section C
Homework 4
*/
#include"traverse.h"

BST* build(int a[], int low, int high){
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
	Stack* temp = (Stack*)malloc(sizeof(Stack));
	if(temp == NULL){
		printf("\nMemory allocation error\n");
		return NULL;
	}
	BST* test = NULL;
	temp->tNode = node;
	temp->next = s;
	s = temp;
	test = s->tNode;
	//printf("node test %d\n", test->data);
	printf("\npush test\n");
	return s;
	
}

Stack* pop(Stack* s){
	Stack* temp = NULL;
	//printf("pop test ");
	printf("%d ", s->tNode->data);
	temp = s;
	s = s->next;
	free(temp);
	return s;
}

Queue* enqueue(Queue* q, BST* tree){
	Queue* new = NULL;
	Queue* current = q;
	if(q == NULL){
		new = malloc(sizeof(Queue));
		new->data = tree;
		new->next = NULL;
		new->previous = NULL;
	}else{
		while(q->next != NULL){
			q = q->next;
			if(q->next == NULL){
				q->next->data = tree;
				q->next->next = NULL;
				q->next->previous = q;
				return current;
				break;
			}
		}
	}
}

int dequeue(Queue* q){
	Queue temp;
	BST* fst;
	}
	

void inorder(BST* tree){
	Stack* s = NULL;
	BST* current = tree;
	int fin = 0;
	while(fin != 1){
		while(current != NULL){
			//printf("push initial ");
			s = push(s, current);
			current = current->left;
		}
		if(s != NULL && current == NULL){
				current = s->tNode->right;
				s = pop(s);
				//printf("pop initial ");
			}else if(current == NULL && s == NULL){ 
				fin = 1;
			}
	}
}

void preorder(BST* tree){
	Stack* s = push(s, tree);
	Stack* temp;
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

void breadth(BST* tree){
	BST* temp = NULL;
	Queue* q = 
void padding(char ch, int n)
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