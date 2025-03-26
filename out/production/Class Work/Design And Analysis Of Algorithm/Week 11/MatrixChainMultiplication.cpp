#include <iostream>
#include <climits>
using namespace std;

void matrixChainMultiplication(int p[], int n) {
    int dp[n][n];

    // Initialize the diagonal to 0
    for (int i = 1; i < n; i++) 
        dp[i][i] = 0;

    for (int length = 2; length < n; length++) {
        for (int i = 1; i < n - length + 1; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << "Minimum number of multiplications: " << dp[1][n - 1] << endl;
}

int main() {
    int p[] = {1, 2, 3, 4};
    int n = sizeof(p) / sizeof(p[0]);
    matrixChainMultiplication(p, n);
    return 0;
}
