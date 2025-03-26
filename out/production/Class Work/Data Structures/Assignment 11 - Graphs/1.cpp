#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

void bfsCycleDetection(const vector<vector<int>> &graph, int start) {
    vector<bool> visited(graph.size(), false);
    unordered_set<int> discovered;
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            } else if (discovered.find(neighbor) != discovered.end()) {
                cout << "\nCycle detected at edge: " << node << " -> " << neighbor;
            }
            discovered.insert(node);
        }
    }
}

int main() {
    vector<vector<int>> graph = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
    bfsCycleDetection(graph, 0);
    return 0;
}
