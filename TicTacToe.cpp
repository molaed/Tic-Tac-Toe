#include <iostream>
#include <vector>

using namespace std;

void grid(vector<vector<char>> matrix) {

    cout << "   |   |   \n";
    cout << " " << matrix[0][0] << " | " << matrix[0][1] << " | " << matrix[0][2] << endl;
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " " << matrix[1][0] << " | " << matrix[1][1] << " | " << matrix[1][2] << endl;
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " " << matrix[2][0] << " | " << matrix[2][1] << " | " << matrix[2][2] << endl;
    cout << "   |   |   \n";

}

int main() {
    const char X = 'X';
    const char O = 'O';

    int row, column;
    int squaresRemaining = 9; 

    bool playerOne = 1;
    int playerChoice;



    vector<vector<char>> matrix = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

    while (squaresRemaining) {
        if (playerOne) {
            cout << "Player1's Turn: ";
            cin >> playerChoice;
        }
        else {
            cout << "Player2's Turn: ";
            cin >> playerChoice;
        }
        
        grid(matrix);
    }
}