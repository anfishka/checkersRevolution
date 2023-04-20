
#include <iostream>
using namespace std;

const int BOARD_S = 8;
const char EMPTY = '-';
const char O = 'O';
const char X = 'X';
const char O_KING = 'o';
const char X_KING = 'x';

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

void printBoard()
{
    cout << "  ";
    for (int i = 0; i < BOARD_S; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < BOARD_S; i++)
    {
        cout << i << " ";
        for (int j = 0; j < BOARD_S; j++)
        {
            if (board[i][j] != X && EMPTY != board[i][j])
            {
                cout << "\x1b[43m" << board[i][j] << " " << "\033[0m";
            }
            else if (board[i][j] == X)
            {
                cout << "\x1b[44m" << board[i][j] << " " << "\033[0m";
            }
            else
            {
                cout << "\x1b[49m" << board[i][j] << " " << "\033[0m";
            }

        }
        cout << endl;
    }
}

bool isMoveValid(int startRow, int startCol, int endRow, int endCol, char player)
{
    // check start pos
    if (player == X && board[startRow][startCol] != X && board[startRow][startCol] != X_KING) {
        return false;
    }
    if (player == O && board[startRow][startCol] != O && board[startRow][startCol] != O_KING) {
        return false;
    }

    // check is the end pos == empty
    if (board[endRow][endCol] != EMPTY) {
        return false;
    }
    // check diagonally steps
    int delta_x = endRow - startRow;
    int delta_y = endCol - startCol;
    if (player != X_KING && player != O_KING) {
        // check distance start and end pos == 2 
        if (abs(delta_x) == 2 && abs(delta_y) == 2) {
            //check is opponent in our way
            int capture_x = (startRow + endRow) / 2;
            int capture_y = (startCol + endCol) / 2;
            if (board[capture_x][capture_y] == EMPTY) {
                return false;
            }
            // check is opponenet
            if (player == X && (board[capture_x][capture_y] != O && board[capture_x][capture_y] != O_KING)) {
                return false;
            }
            if (player == O && (board[capture_x][capture_y] != X && board[capture_x][capture_y] != X_KING)) {
                return false;
            }
        }
        else {
            // check end and start pos ==  1
            if (abs(delta_x) != 1 || abs(delta_y) != 1) {
                return false;
            }
        }

        // check just 1 step
        if (abs(delta_x) == 1) {
            //check direcrion
            if (delta_x > 0 && player == O) {
                return false;
            }
            if (delta_x < 0 && player == X) {
                return false;
            }
        }
    }
    else {
        //check kings
        if (abs(delta_x) != abs(delta_y))
            return false;
    }
    return true;
}

bool forcedCapture() {
    // check capture
    return true;
}

// foo for moving
bool move(int startRow, int startCol, int endRow, int endCol) {
    char player = board[startRow][startCol];
    if (isMoveValid(startRow, startCol, endRow, endCol, player) && forcedCapture()) {
        board[endRow][endCol] = board[startRow][startCol];
        board[startRow][startCol] = EMPTY;
    }
    else {
        cout << "\n\x1b[31mInvalid move\033[0m" << endl;
        return false;
    }

    int take_x = endRow > startRow ? -1 : 1;
    int take_y = endCol > startCol ? -1 : 1;

    if (abs(endRow - startRow) != 1) {
        int capture_x = endRow + take_x;
        int capture_y = endCol + take_y;
        board[capture_x][capture_y] = EMPTY;
    }
    // king
    if (player == O && endRow == 0) {
        board[endRow][endCol] = O_KING;
    }
    if (player == X && endRow == 7) {
        board[endRow][endCol] = X_KING;
    }
}

// end of game
bool isGameOver() {
    int num_x = 0, num_o = 0;
    for (int i = 0; i < BOARD_S; i++) {
        for (int j = 0; j < BOARD_S; j++) {
            if (board[i][j] == X || board[i][j] == X_KING) {
                num_x++;
            }
            if (board[i][j] == O || board[i][j] == O_KING) {
                num_o++;
            }
        }
    }
    return (num_x == 0 || num_o == 0);
}

int main()
{
    int turn = 0;
    int startRow, startCol, endRow, endCol;
    char player = (turn % 2 == 0) ? X : O;

    while (!isGameOver())
    {
        printBoard();
        cout << "\n\x1b[45m" << player << " player's turn. Enter starting row, starting column, ending row, ending column: \n" << "\033[0m";

        cin >> startRow;
        cin >> startCol;
        cin >> endRow;
        cin >> endCol;
        if (move(startRow, startCol, endRow, endCol))
        {
            turn++;
            player = (turn % 2 == 0 ? X : O);
        }
    }
    printBoard();
    cout << "\n\x1b[42m" << " WIN!" << "\033[0m" << endl;
    return 0;
}