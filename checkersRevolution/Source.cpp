
#include <iostream>
using namespace std;

const int BOARD_S = 8;
const char EMPTY = '-';
const char O = 'O';
const char X = 'X';

char board[BOARD_S][BOARD_S] = {
    { EMPTY, X, EMPTY, X, EMPTY, X, EMPTY, X },
    { X, EMPTY, X, EMPTY, X, EMPTY, X, EMPTY },
    { EMPTY, X, EMPTY, X, EMPTY, X, EMPTY, X },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { O, EMPTY, O, EMPTY, O, EMPTY, O, EMPTY },
    { EMPTY, O, EMPTY, O, EMPTY, O, EMPTY, O },
    { O, EMPTY, O, EMPTY, O, EMPTY, O, EMPTY }
};

void printBoard() {
    cout << "  ";
    for (int i = 0; i < BOARD_S; i++) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < BOARD_S; i++) {
        cout << i << " ";
        for (int j = 0; j < BOARD_S; j++) {
            if (board[i][j] != X && EMPTY != board[i][j]) {
                cout << "\x1b[43m" << board[i][j] << " " << "\033[0m";
            }
            else if (board[i][j] == X) {
                cout << "\x1b[44m" << board[i][j] << " " << "\033[0m";
            }
            else {
                cout << "\x1b[49m" << board[i][j] << " " << "\033[0m";
            }

        }
        cout << endl;
    }
}

bool isMoveValid(int startRow, int startCol, int endRow, int endCol, char player) {

    // Check: chacker moves diagonally
    if (abs(startRow - endRow) != abs(startCol - endCol)) {
        return false;
    }
    // Check : chacker moves only one square or two squares if it captures an opponent's checker 
    if (abs(startRow - endRow) != 1 && abs(startRow - endRow) != 2) {
        return false;
    }
    // Check: chacker moves to the right or to the left
    if (abs(startCol - endCol) != 1 && abs(startCol - endCol) != 2) {
        return false;
    }
    // Check: chacker moved and captured opponent's chacker
    if (abs(startRow - endRow) == 2 && abs(startCol - endCol) == 2) {
        int enemyRow = (startRow + endRow) / 2;
        int enemyCol = (startCol + endCol) / 2;
        if (board[enemyRow][enemyCol] == EMPTY || board[enemyRow][enemyCol] == player) {
            return false;
        }
        board[enemyRow][enemyCol] = EMPTY;
    }
    return true;

}

int main()
{
    printBoard();
    return 0;
}