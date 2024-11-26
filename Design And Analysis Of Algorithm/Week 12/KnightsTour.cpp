#include <iostream>
#include <vector>
using namespace std;

const int movesX[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int movesY[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isSafe(int x, int y, int n, vector<vector<int>> &board) {
    return (x >= 0 && y >= 0 && x < n && y < n && board[x][y] == -1);
}

bool solveKnightTourUtil(int x, int y, int moveCount, vector<vector<int>> &board, int n) {
    if (moveCount == n * n)
        return true;

    for (int i = 0; i < 8; i++) {
        int nextX = x + movesX[i];
        int nextY = y + movesY[i];
        if (isSafe(nextX, nextY, n, board)) {
            board[nextX][nextY] = moveCount;
            if (solveKnightTourUtil(nextX, nextY, moveCount + 1, board, n))
                return true;
            board[nextX][nextY] = -1;
        }
    }
    return false;
}

void solveKnightTour(int n) {
    vector<vector<int>> board(n, vector<int>(n, -1));

    board[0][0] = 0; // Starting position

    if (solveKnightTourUtil(0, 0, 1, board, n)) {
        for (const auto &row : board) {
            for (int cell : row)
                cout << cell << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists\n";
    }
}

int main() {
    int n = 8;
    solveKnightTour(n);
    return 0;
}
