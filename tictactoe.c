//Tic Tac Toe game between 2 players or playervscomputer
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int grid[3][3]; 
bool gameOver = false;
bool vsComputer = false;

void reset();
bool spotSelect();
bool checkWin();
void displayBoard();
char getSymbol();

bool playerTurn();
void computerTurn();

int main(){

    srand(time(0));

    reset();
    displayBoard();


    //prompt user for game they wish to play (vs human or vs computer)
    printf("Please choose the type of game (input number):\n\t1 - vs human\n\t2 - vs computer\n");

    int gameType;
    scanf("%d", &gameType);
    if (gameType == 2){
        vsComputer = true;
    }

    //putchar(gameType);

    //need while loop for game working
    while (!gameOver){
        computerTurn(1);
        checkWin(1);
        if (vsComputer && !gameOver){
            //printf("Computer has placed a piece.\n");
            computerTurn(2);
            checkWin(2);

        } else if (!gameOver){
            printf("PLAYER 2 TURN\n");
            playerTurn(2);
            checkWin(2);
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
    if (0 <= row && row < 3 && 0 <= column && column < 3){
        if (grid[row][column] == 0){
            grid[row][column] = player;
            return true;
        } else {
            printf("Place already taken. Please choose another place.\n");
            playerTurn(player);
        }
    } else {
        printf("Place out of bounds. Please choose another place.\n");
            playerTurn(player);
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

bool playerTurn(int player){
    printf("Player %d", player);
    printf(", please choose where to place your piece. (row 1-3, column 1-3)\n");
        displayBoard();
        int row;
        int column;
        scanf("%d", &row);
        scanf("%d", &column);
        return spotSelect(row-1, column-1, player);
}

void computerTurn(int player){
    bool validMove = false;
    while (!validMove){
        printf("computerattempt)\n");
        int row = (rand() %(4));
        int column = (rand() %(4));
        if (grid[row][column] == 0){
            grid[row][column] = player;
            printf("Computer has placed a piece.\n");
            validMove = true;
        }
    }
    if (!checkWin(2)){
        displayBoard();
    }
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
        printf("game over\n");
        displayBoard();
    }
    return gameOver;
}