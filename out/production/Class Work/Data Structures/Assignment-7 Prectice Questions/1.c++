#include <iostream>
#include <vector>
using namespace std;

// Function to create a magic square
void createMagicSquare(int n, vector<vector<int>>& square, int num, int row, int col) {
    // Base case: if the current number exceeds n^2, we are done
    if (num > n * n)
        return;

    // Place the number in the current position
    square[row][col] = num;

    // Calculate the next position
    int newRow = (row - 1 + n) % n;  // Move up (wrapping around)
    int newCol = (col + 1) % n;      // Move right (wrapping around)

    // If the new position is already filled, move down instead
    if (square[newRow][newCol] != 0) {
        newRow = (row + 1) % n;
        newCol = col;
    }

    // Recur to place the next number
    createMagicSquare(n, square, num + 1, newRow, newCol);
}

// Function to display the magic square
void displaySquare(const vector<vector<int>>& square) {
    for (const auto& row : square) {
        for (int num : row) {
            cout << num << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;

    cout << "Enter an odd integer for the size of the magic square: ";
    cin >> n;

    // Ensure the user enters an odd number
    if (n % 2 == 0) {
        cout << "Magic square is only possible for odd numbers. Please enter an odd integer." << endl;
        return 1;
    }

    // Initialize a 2D vector with zeroṇs
    vector<vector<int>> square(n, vector<int>(n, 0));

    // Start placing numbers from the top-middle cell
    createMagicSquare(n, square, 1, 0, n / 2);

    // Display the completed magic square
    cout << "Magic Square of size " << n << ":\n";
    displaySquare(square);

    return 0;
}
