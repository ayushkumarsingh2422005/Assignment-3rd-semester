#include <iostream>
#include <vector>
using namespace std;

void dfsCycleDetection(int node, const vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfsCycleDetection(neighbor, graph, visited, recStack);
        } else if (recStack[neighbor]) {
            cout << "Back edge detected: " << node << " -> " << neighbor << "\n";
        }
    }

    recStack[node] = false;
}

int main() {
    vector<vector<int>> graph = {{1, 2}, {2}, {0}, {3}};
    vector<bool> visited(graph.size(), false);
    vector<bool> recStack(graph.size(), false);

    for (int i = 0; i < graph.size(); ++i) {
        if (!visited[i]) dfsCycleDetection(i, graph, visited, recStack);
    }
    return 0;
}
