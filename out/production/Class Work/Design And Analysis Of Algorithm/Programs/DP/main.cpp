#include <iostream>
using namespace std;

int fibonachi(int n, int dp[]) {
    if (n <= 1) {
        return n;  // Base case
    }
    if (dp[n] == -1) {
        dp[n] = fibonachi(n - 1, dp) + fibonachi(n - 2, dp);
    }
    return dp[n];
}

int fibonachi(int n) {
    int prev1 = 1;
    int prev2 = 0;
    for (int i = 2; i <= n; i++) {
        int temp = prev1 + prev2;
        prev2 = prev1;
        prev1 = temp;
    }
    return prev1;
}

int stair(int n) {
    if (n <= 1) {
        return 1;
    }
    return stair(n - 1) + stair(n - 2);
}

int main() {
    long long n = 4;
    int dp[n + 1];
    fill_n(dp, n + 1, -1);  // Initialize dp array to -1

    cout << "Fibonacci of " << n << " is: " << stair(n) << endl;
    return 0;
}
