#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void primsMST(const vector<vector<pair<int, int>>> &graph) {
    int n = graph.size();
    vector<int> key(n, INT_MAX);
    vector<bool> mstSet(n, false);
    vector<int> parent(n, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 0});
    key[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        mstSet[u] = true;
        for (const pair<int, int> &edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!mstSet[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        cout << parent[i] << " - " << i << "\n";
    }
}

int main() {
    vector<vector<pair<int, int>>> graph = {
        {{1, 2}, {3, 6}}, 
        {{0, 2}, {2, 3}, {3, 8}, {4, 5}}, 
        {{1, 3}, {4, 7}}, 
        {{0, 6}, {1, 8}}, 
        {{1, 5}, {2, 7}}
    };
    primsMST(graph);
    return 0;
}
