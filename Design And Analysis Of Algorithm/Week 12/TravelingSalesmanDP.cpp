#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int tspDP(vector<vector<int>> &graph, int mask, int pos, vector<vector<int>> &dp, int n) {
    if (mask == (1 << n) - 1) {
        return graph[pos][0] ? graph[pos][0] : INT_MAX;
    }

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int minCost = INT_MAX;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0 && graph[pos][city]) {
            int newCost = graph[pos][city] + tspDP(graph, mask | (1 << city), city, dp, n);
            minCost = min(minCost, newCost);
        }
    }

    dp[mask][pos] = minCost;
    return minCost;
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int n = graph.size();
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));

    int minCost = tspDP(graph, 1, 0, dp, n);

    cout << "Minimum Cost (Dynamic Programming): " << minCost << endl;
    return 0;
}
