
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

int main()
{
    int startRow, startCol, endRow, endCol;
    char player = O;
    while (true) 
    {
        printBoard();
        cout << " player's turn. Enter starting row, starting column, ending row, ending column: ";
        cin >> startRow;
        cin >> startCol;
        cin >> endRow;
        cin >> endCol;

        if (!isMoveValid(startRow, startCol, endRow, endCol, player)) 
        {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[endRow][endCol] = player;
        board[startRow][startCol] = EMPTY;

        player = (player == O) ? X : O;
    }
    return 0;
}