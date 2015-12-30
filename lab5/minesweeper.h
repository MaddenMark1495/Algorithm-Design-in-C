typedef enum{
        covered,
        uncovered,
        coveredBomb,
        uncovredBomb
        }positionType;

#define BoardSize 10

void setBoard(positionType board[BoardSize][BoardSize],int);
void displayBoard(positionType board[BoardSize][BoardSize]);
int processGuess(positionType board[BoardSize][BoardSize],int,int);



