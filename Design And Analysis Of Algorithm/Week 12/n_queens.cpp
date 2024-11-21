#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isSafe(const vector<vector<int>>& board, int row, int col, int N) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int row, int N) {
    // Base case: If all queens are placed
    if (row >= N) {
        return true;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1; // Place the queen

            // Recur to place the next queen
            if (solveNQueens(board, row + 1, N)) {
                return true;
            }

            // If placing queen in the current position leads to a solution, remove it (backtrack)
            board[row][col] = 0;
        }
    }

    return false; // No safe place for queen in the current row
}

void printSolution(const vector<vector<int>>& board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] == 1 ? "Q" : ".");
        }
        cout << endl;
    }
}

int main() {
    int N;
    cout << "Enter the number of queens: ";
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQueens(board, 0, N)) {
        printSolution(board, N);
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
