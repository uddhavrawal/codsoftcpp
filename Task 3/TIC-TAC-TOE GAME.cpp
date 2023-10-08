#include <iostream>
using namespace std;

char board[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char currentPlayer = 'X';
bool gameover = false;
 
void displayBoard() {
    system("clear");  
    cout << "Tic-Tac-Toe Game" << endl;
    cout << "Player 1 (X) - Player 2 (O)" << endl;
    cout << "-------------------" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------------" << endl;
    }
}
 
void getPlayerMove() {
    int move;
    cout << "Player " << currentPlayer << ", enter your move (1-9): ";
    cin >> move;
  
    if (move < 1 || move > 9) {
        cout << "Invalid move! Please enter a number between 1 and 9." << endl;
        getPlayerMove();
        return;
    }

    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
 
    if (board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "That cell is already occupied. Try again." << endl;
        getPlayerMove();
        return;
    }

    board[row][col] = currentPlayer;
}
 
bool checkWin() {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true;  // Row win
        }
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            return true;  // Column win
        }
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true;  // Diagonal win
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true;  // Diagonal win
    }

    return false;
}
 
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;  // There are still empty cells
            }
        }
    }
    return true;  // All cells are filled (draw)
} 
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    int moves = 0;

    while (!gameover) {
        displayBoard();
        getPlayerMove();
        moves++;

        if (checkWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameover = true;
        } else if (checkDraw()) {
            displayBoard();
            cout << "It's a draw!" << endl;
            gameover = true;
        }

        switchPlayer();

        if (moves >= 9) {
            gameover = true;
        }
    }

    return 0;
}
