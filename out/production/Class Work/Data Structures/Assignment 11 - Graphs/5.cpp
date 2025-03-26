#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool pathExists(int src, int dest, int k, const vector<vector<int>> &graph) {
    if (k == 0) return src == dest;
    for (int neighbor : graph[src]) {
        if (pathExists(neighbor, dest, k - 1, graph)) return true;
    }
    return false;
}

int main() {
    int vertices = 4;
    vector<vector<int>> graph(vertices);
    graph[0] = {1, 2};
    graph[1] = {2};
    graph[2] = {0, 3};
    graph[3] = {3};

    int src = 0, dest = 3, k = 2;
    if (pathExists(src, dest, k, graph)) {
        cout << "Path exists with " << k << " edges from " << src << " to " << dest << ".\n";
    } else {
        cout << "No such path exists.\n";
    }
    return 0;
}
