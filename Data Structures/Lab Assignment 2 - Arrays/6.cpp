#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix_size = sizeof(matrix) / sizeof(matrix[0]);

    cout << "Upper triangular matrix" << endl;
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size - i; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Lower triangular matrix" << endl;
    for (int i = 0; i < matrix_size; i++) {
        for (int j = matrix_size - i - 1; j < matrix_size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
