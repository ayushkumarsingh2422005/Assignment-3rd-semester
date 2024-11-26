#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void tspBacktracking(vector<vector<int>> &graph, vector<bool> &visited, int currPos, int n, int count, int cost, int &minCost) {
    if (count == n && graph[currPos][0]) {
        minCost = min(minCost, cost + graph[currPos][0]);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[currPos][i]) {
            visited[i] = true;
            tspBacktracking(graph, visited, i, n, count + 1, cost + graph[currPos][i], minCost);
            visited[i] = false;
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int n = graph.size();
    vector<bool> visited(n, false);
    visited[0] = true;

    int minCost = INT_MAX;
    tspBacktracking(graph, visited, 0, n, 1, 0, minCost);

    cout << "Minimum Cost (Backtracking): " << minCost << endl;
    return 0;
}
