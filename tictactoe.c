//Tic Tac Toe game between 2 players or playervscomputer
#include <stdio.h>
#include <stdbool.h>

int grid[3][3]; 

void reset();
bool spotSelect();
bool checkWin();
void displayBoard();
char getSymbol();

int main(){

    
    reset();
    displayBoard();

    //prompt user for game they wish to play (vs human or vs computer)
    printf("Please choose the type of game (input number):\n\t1 - vs human\n\t2 - vs computer\n");

    int gameType;
    gameType = getchar();

    putchar(gameType);

    
    

    

    /* functions needed:
        1. spot select
        2. check win
        3. reset
        4. display board
    */

   

    //read information from console

    //asfasdf


    return 0;
}

void reset (){
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                grid[i][j] = 0;
            }
        }
        printf("grid reset\n");
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
    

    /*
    printf("+-----------+\n");
    printf("|");
    for (int i=0; i<3; i++){
        printf(getSymbol(grid[0][i]));
        printf("|");
    }
    printf("+-----------+\n");
    printf("|");
    for (int i=0; i<3; i++){
        printf(getSymbol(grid[1][i]));
        printf("|");
    }
    printf("+-----------+\n");
    printf("|");
    for (int i=0; i<3; i++){
        printf(getSymbol(grid[2][i]));
        printf("|");
    }
    */

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