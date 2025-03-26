#include <iostream>
#include <climits>
using namespace std;

bool checkSaddlePoint(int arr[][3], int n, int m) {
    int minRow[n];
    int maxCol[m];
    
    for (int i = 0; i < n; i++)
        minRow[i] = INT_MAX;
    for (int j = 0; j < m; j++)
        maxCol[j] = INT_MIN;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] < minRow[i])
                minRow[i] = arr[i][j];
            if (arr[i][j] > maxCol[j])
                maxCol[j] = arr[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == minRow[i] && arr[i][j] == maxCol[j]) {
                cout << "Saddle point found at position (" << i << ", " << j << "): " << arr[i][j] << endl;
                return true;
            }
        }
    }

    cout << "No saddle point found." << endl;
    return false;
}

int main() {
    int n = 3, m = 3;
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    bool hasSaddlePoint = checkSaddlePoint(arr, n, m);

    return 0;
}
