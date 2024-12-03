#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int u, vector<int> &parent) {
    if (u != parent[u]) parent[u] = findParent(parent[u], parent);
    return parent[u];
}

void unionSets(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

void kruskalMST(vector<Edge> &edges, int n, vector<pair<int, int>> constraints) {
    sort(edges.begin(), edges.end(), compare);
    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;

    int mstWeight = 0;
    for (auto &edge : edges) {
        if (find(constraints.begin(), constraints.end(), make_pair(edge.u, edge.v)) != constraints.end())
            continue;
        int uParent = findParent(edge.u, parent);
        int vParent = findParent(edge.v, parent);
        if (uParent != vParent) {
            cout << edge.u << " - " << edge.v << " : " << edge.weight << "\n";
            mstWeight += edge.weight;
            unionSets(edge.u, edge.v, parent, rank);
        }
    }
    cout << "Total weight of MST: " << mstWeight << "\n";
}

int main() {
    vector<Edge> edges = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
    vector<pair<int, int>> constraints = {{0, 2}};
    kruskalMST(edges, 4, constraints);
    return 0;
}
