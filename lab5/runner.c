//Mark Madden
//14182986
//mcmpw6
//10/07/14
//lab d
// hackmizzou

#define BoardSize 10
#include "minesweeper.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main (int argc,char*argv[])
{

	int number;
	int row;
	int col;
	int guess;
	int  board[BoardSize][BoardSize];
	srand(time(NULL));
	if(argv[1]==NULL)
	{
		printf("Error:Please Enter Number");
		return 0;
	}
	 number = atoi(argv[1]);
	setBoard(board,number);
	DisplayBoard(board);
	printf("Enter a row :"); 
	scanf("%d",&row);
	printf("Enter a Col:");
	scanf("%d",&col);
//	guess=processGuess(board,row,col);



	return 0;	
}		
