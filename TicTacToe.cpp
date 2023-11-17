#include <iostream>
#include <vector>

using namespace std;

void grid(vector<vector<char>> & matrix) {
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

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

bool sanitizeInput(int playerChoice, vector<vector<char>> &matrix) {
    if (playerChoice < 1 || playerChoice > 9) {
        grid(matrix);
        cout << "Please pick a number from  1-9!\n";
        return false;
    }
    if (matrix[(playerChoice-1)/3][(playerChoice-1)%3] == 'X' ||
                matrix[(playerChoice-1)/3][(playerChoice-1)%3] == 'O') {
        grid(matrix);
        cout << "Pick an unoccupied square!\n";
        return false;
    }
    return true;
}

bool checkWinner(vector<vector<char>> &matrix, bool playerOne) {
    char token = (playerOne) ? 'X' : 'O';

    for (int i = 0; i < 3; i++) {
        if (matrix[i][0] == token && matrix[i][1] == token && matrix[i][2] == token) return true;
    } //check columns for three in a row
    for (int i = 0; i < 3; i++) {
        if (matrix[0][i] == token && matrix[1][i] == token && matrix[2][i] == token) return true;
    } //check columns for three in a row
    if (matrix[0][0] == token && matrix[1][1] == token && matrix[2][2] == token) return true;
    if (matrix[0][2] == token && matrix[1][1] == token && matrix[2][0] == token) return true;

    return false;
}

int changeBox(int playerChoice, vector<vector<char>> &matrix, bool playerOne) {
    while(!sanitizeInput(playerChoice, matrix)) {
        cin >> playerChoice;
    }

    matrix[(playerChoice-1)/3][(playerChoice-1)%3] = (playerOne) ? 'X' : 'O';

    return checkWinner(matrix, playerOne);
}

int main() {

    int row, column;
    int squaresRemaining = 9; 

    bool playerOne = 1;
    int playerChoice;

    vector<vector<char>> matrix = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

    grid(matrix);

    while (squaresRemaining > 0) {
        if (playerOne) cout << "Player1's Turn (pick a number from 1-9): ";
        else cout << "Player2's Turn (pick a number from 1-9): ";

        cin >> playerChoice;
        
        if(changeBox(playerChoice, matrix, playerOne)) { // changeBox returns true if a player has won
            squaresRemaining = -1;
            grid(matrix);

            break;
        }

        grid(matrix);

        squaresRemaining--;
        playerOne = !playerOne;
    }

    if (!squaresRemaining) {
        cout << "It's a tie!!";
    }
    else {
        cout << (playerOne ? "Player1 has Won!!" : "Player2 has Won!!");
    }


}