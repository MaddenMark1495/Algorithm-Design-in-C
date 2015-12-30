//Mark Madden
//mcmpw6
//14182986
//hw4
#include"traverse.h"

int main(int argc, char* argv[])
{
	if(argc < 2){
		printf("Invalid command line input\n");
		return 0;
	}
	int a[MAX_LEN] = {0};
	int val, len, i = 0;
	BST* root = NULL;
	FILE* fPtr = fopen(argv[1], "r");
	if(fPtr == NULL){
		printf("\nFile failed to open\n");
		return 0;
	}
	while(!feof(fPtr) && i < MAX_LEN-1){
		fscanf(fPtr, "%d", &a[i++]);
	}
	i--;
	root = build(a, 0, i-1);
		
	print(root);
	printf("\n");
	printf("\nPreorder:\n");
	preorder(root);
	printf("\nInorder:\n");
	inorder(root);
	printf("\nBreadth First:\n");
	breadth(root);
	destroy(root);
	printf("\n");
	return 0;
}
