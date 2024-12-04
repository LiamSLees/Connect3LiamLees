/* Liam Lees, TTH 5:30-6:45pm
 * CS 210-09
 *
 */#include <iostream>
#include <vector>
#include <string>
using namespace std;




class ConnectThree {
public:
    vector<vector<char>> gameBoard = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };


    void printGameBoard() {
        for (int i = 0; i < gameBoard.size(); i++) {
            for (int j = 0; j < gameBoard[i].size(); j++) {
                cout << gameBoard[i][j] << " ";
            }
            cout << endl;
        }
    }


    void modifyGameBoard(char player, int position) {
        int row = (position - 1) / 3;
        int col = (position - 1) % 3;
        gameBoard[row][col] = player;
    }

    char checkWinner() const {
        // checks rows and columns
        for (int j = 0; j < 3; ++j) {

            // checks diagonals (X cross): 159, 357
            if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]) {
                return gameBoard[0][0];
            }
            if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0]) {
                return gameBoard[0][2];
            }

            if (gameBoard[0][j] == gameBoard[1][j] && gameBoard[1][j] == gameBoard[2][j]) {
                return gameBoard[0][j]; // Columns: 147, 258, 369
            }
            if (gameBoard[j][0] == gameBoard[j][1] && gameBoard[j][1] == gameBoard[j][2]) {
                return gameBoard[j][0]; // Rows: 123, 456, 789
            }
        }
        return ' ';
    }


    bool isDraw() const {
        for (const auto& row : gameBoard) {
            for (char cell : row) {
                if (cell != 'X' && cell != 'O') {
                    return false; // if not full keep going
                }
            }
        }
        return true; // all cells are full and no winner = draw
    }
};

int main() {
    ConnectThree connect;

    //iterates while true
    while (true) {

        connect.printGameBoard();
        cout << "Enter the value for the position on the board you wish to replace: ";
        int num;
        cin >> num;

        cout << "Enter X or O, whichever is going to replace the number: ";
        char userVal;
        cin >> userVal;
        userVal = toupper(userVal);


        connect.modifyGameBoard(userVal, num);
        connect.printGameBoard();

        // winner check
        char winner = connect.checkWinner();
        if (winner == 'X') {
            cout << "X wins!" << endl;
            break;
        } else if (winner == 'O') {
            cout << "O wins!" << endl;
            break;
        }

        // draw check
        if (connect.isDraw()) {
            cout << "It's a draw!" << endl;
            break;
        }
    }

    return 0;
}
