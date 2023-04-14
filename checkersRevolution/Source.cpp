
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

int main()
{
    printBoard();
    return 0;
}