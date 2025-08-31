#include <iostream>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

bool isOver(char board[ROWS][COLS]);

int main() {

    // initialize important variables
    char board[ROWS][COLS];
    char playerTurn = 'O';
    int turnCount = 0;

    // game loop
    while(turnCount < 9 && !isOver(board)) {

        // switch player turn
        playerTurn = (playerTurn == 'O') ? 'X' : 'O';

        //increment turn
        turnCount++;

        // print board
        for(int row = 0; row < ROWS; row++) {
            for(int col = 0; col < COLS; col++) {
                if(board[row][col] != 'O' && board[row][col] != 'X') cout << "_";
                else cout << board[row][col];
            }
            cout << "\n";
        }

        // read user input
        cout << "\n> ";
        int actionRow = 0, actionCol = 0;
        cin >> actionRow >> actionCol;

        // place player symbol on grid
        board[actionRow][actionCol] = playerTurn;
    }

    // print board and player who won (if any)
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            if(board[row][col] != 'O' && board[row][col] != 'X') cout << "_";
            else cout << board[row][col];
        }     
        cout << "\n";
    }
    if(playerTurn == 9) cout << "TIE!";
    else cout << "PLAYER " << playerTurn << " WON!";

    return 0;
}

bool isOver(char board[ROWS][COLS]) {

    // check horizontals 
    for(int row = 0; row < ROWS; row++) {
        if((board[row][0] == 'X' || board[row][0] == 'O') && board[row][0] == board[row][1] && board[row][1] == board[row][2])
            return true;
    }

    //check verticals
    for(int col = 0; col < COLS; col++) {
        if((board[0][col] == 'X' || board[0][col] == 'O') && board[0][col] == board[1][col] && board[1][col] == board[2][col]) 
            return true;
    }

    //check diagonals
    if((board[0][0] == 'X' || board[0][0] == 'O') && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if((board[0][2] == 'X' || board[0][2] == 'O') && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    return false;
}