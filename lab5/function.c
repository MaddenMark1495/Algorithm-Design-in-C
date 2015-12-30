#include<stdio.h>
#include<time.h>
#include"minesweeper.h"
#define BoardSize 10
void setBoard(positionType board[BoardSize][BoardSize],int NumMines)
{
	int i;
	int j;
	
	for (i=0;i<NumMines;i++){
	
		for(j=0;j<NumMines;j++){
			board[i][j]=rand()%10;
		}

	}
}




void DisplayBoard(positionType board[BoardSize][BoardSize],int num){

	int i;
	int j;

	for(i=0;i<BoardSize;i++){
		for(j=0;j<BoardSize;j++)
			{
				printf("%d ",board[i][j]);
			}
	printf("\n");
	}
	printf("\n");
}	
	



//int processGuess(PositionType board[],int row,int col)
//{



	
