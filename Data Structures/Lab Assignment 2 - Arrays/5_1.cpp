#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int matrix1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    int matrix2[3][3] = {
        {11, 12, 13},
        {14, 15, 16},
        {17, 18, 19},
    };

    // addition
    int ans[3][3];
    cout << "Matrix Addition" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ans[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    // multiplication
    cout << "\nMatrix multiplication" << endl;
    int multipliction_ans[3];
    for (int i = 0; i < 3; i++) {
        int temp = 0;
        for (int j = 0; j < 3; j++) {
            temp += matrix1[i][j] * matrix2[j][i];
        }
        multipliction_ans[i] = temp;
    }
    for (int i = 0; i < 3; i++) {
        cout << multipliction_ans[i] << endl;
    }

    // substraction

    return 0;
}
