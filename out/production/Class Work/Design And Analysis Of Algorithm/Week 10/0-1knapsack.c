#include <stdio.h>

// A utility function that returns the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Returns the maximum value that can be put in a knapsack of capacity W
int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    // Build the table K[][] in a bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            } else {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    // K[n][W] contains the maximum value that can be obtained with the given weight limit W
    return K[n][W];
}

int main() {
    int val[] = {60, 100, 120}; // Values (profits)
    int wt[] = {10, 20, 30};    // Weights
    int W = 50;                 // Knapsack capacity
    int n = sizeof(val) / sizeof(val[0]);

    int max_value = knapsack(W, wt, val, n);
    printf("Maximum value in the knapsack = %d\n", max_value);

    return 0;
}
