
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

int main()
{
    return 0;
}