//Tic Tac Toe game between 2 players or playervscomputer
#include <stdio.h>
#include <stdbool.h>

int grid[3][3]; 
bool gameOver = false;
bool vsComputer = false;

void reset();
bool spotSelect();
bool checkWin();
void displayBoard();
char getSymbol();

void playerTurn();
void computerTurn();

int main(){

    
    reset();
    displayBoard();


    //prompt user for game they wish to play (vs human or vs computer)
    printf("Please choose the type of game (input number):\n\t1 - vs human\n\t2 - vs computer\n");

    int gameType;
    scanf("%d", &gameType);
    if (gameType = 2){
        vsComputer = true;
    }

    putchar(gameType);

    //need while loop for game working
    while (!gameOver){
        playerTurn(1);
        if (vsComputer){
            
        } else {
            playerTurn(2);
        }

    }
    

    
    

    

    /* functions needed:
        1. spot select
        2. check win
        3. reset
        4. display board
    */


    return 0;
}

void reset (){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            grid[i][j] = 0;
        }
    }
    gameOver = false;
    vsComputer = false;
}

bool spotSelect(int row, int column, int player){
    if (grid[row][column] == 0){
        grid[row][column] = player;
        return true;
    } else {
        return false;
    }
}

void displayBoard(){
    for (int i=0; i<3; i++){
        printf("+-----+\n");
        printf("|");
        for (int j=0; j<3; j++){
            printf("%c", getSymbol(grid[i][j]));
            printf("|");
        }
        printf("\n");
    }
    printf("+-----+\n");
}

char getSymbol(int player){
        if (player == 0){
            return ' ';
        } else if (player == 1){
            return 'X';
        } else if (player == 2){
            return 'O';
        }
}

void playerTurn(int player){
    printf("Player %d", player);
    printf(", please choose where to place your piece. (row 1-3, column 1-3)\n");
        int row;
        int column;
        scanf("%d", &row);
        scanf("%d", &column);
        spotSelect(row-1, column-1, player);
        displayBoard();
        checkWin(player);
}

bool checkWin(int player){

    //check horizontal win (row)
    for (int i=0; i<3; i++){
        if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player){
            gameOver = true;
        }
    }

    //check vertical win (column)
    for (int i=0; i<3; i++){
        if (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player){
            gameOver = true;
        }
    }

    //check diagonal win (top left to bottom right)
    if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player){
        gameOver = true;
    }

    //check diagonal win (bottom left to top right)
    if (grid[2][0] == player && grid[1][1] == player && grid[0][2] == player){
        gameOver = true;
    }

    if (gameOver){
        printf("game over");
    }
    return gameOver;
}