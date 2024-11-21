#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

void printGraphMatrix(int graph[][8]) {
    for (int i = 0; i < 8; i++) {
        cout << i << " : ";
        for (int j = 0; j < 8; j++) {
            if (graph[i][j] > 0) {
                cout << "(" << j << ", " << graph[i][j] << ") ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<pair<int, int>>> matrixToList(int matrix[][8]) {
    vector<vector<pair<int, int>>> adj_list(8);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (matrix[i][j] > 0) {  // Only include edges with positive weights
                adj_list[i].emplace_back(j, matrix[i][j]);
            }
        }
    }
    return adj_list;
}

void printAdjacencyList(vector<vector<pair<int, int>>> adj_list) {
    for (int i = 0; i < 8; i++) {
        cout << i << " : ";
        for (auto &neighbor : adj_list[i]) {
            cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

// BFS for weighted graph
void BFS(vector<vector<pair<int, int>>> adj_list, int start) {
    queue<int> que;
    vector<int> visited(adj_list.size());
    que.push(start);
    visited[start] = 1;
    while (!que.empty()) {
        int current = que.front();
        cout << current << " ";
        que.pop();
        for (auto &neighbor : adj_list[current]) {
            if (visited[neighbor.first] != 1) {
                que.push(neighbor.first);
                visited[neighbor.first] = 1;
            }
        }
    }
}

// DFS for weighted graph (iterative)
void DFS(vector<vector<pair<int, int>>> adj_list, int start) {
    vector<int> visited(adj_list.size());
    stack<int> st;
    visited[start] = 1;
    st.push(start);
    while (!st.empty()) {
        int top = st.top();
        st.pop();
        cout << top << " ";
        for (auto &neighbor : adj_list[top]) {
            if (visited[neighbor.first] != 1) {
                st.push(neighbor.first);
                visited[neighbor.first] = 1;
            }
        }
    }
}

// Recursive DFS helper
void dfsHelper(vector<vector<pair<int, int>>> &adj_list, vector<int> &visited,
               int start) {
    if (visited[start] == 1) {
        return;
    }
    cout << start << " ";
    visited[start] = 1;
    for (auto &neighbor : adj_list[start]) {
        if (visited[neighbor.first] != 1) {
            dfsHelper(adj_list, visited, neighbor.first);
        }
    }
}

// Recursive DFS
void dfs(vector<vector<pair<int, int>>> adj_list, int start) {
    vector<int> visited(adj_list.size());
    dfsHelper(adj_list, visited, start);
}

struct PrimsNode {
    int n;
    int p;
    int wt;
    bool operator<(const PrimsNode &other) const {
        return wt > other.wt;  // Min-heap behavior
    }
};

void prims(vector<vector<pair<int, int>>> adj_list, int start) {
    priority_queue<PrimsNode> que;
    vector<int> visited(adj_list.size(), 0);
    que.push({start, -1, -1});
    while (!que.empty()) {
        PrimsNode pn = que.top();
        que.pop();
        if (visited[pn.n]) continue;
        if (pn.p != -1) {
            cout << pn.n << " -> " << pn.p << " : " << pn.wt << endl;
        }

        visited[pn.n] = 1;
        for (pair<int, int> p : adj_list[pn.n]) {
            if (visited[p.first] != 1) {
                que.push({p.first, pn.n, p.second});
            }
        }
    }
}

struct DisjointSet {
    vector<int> parent;
    vector<int> rank;
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;  // Set each node as its own parent initially
        }
    }
    int ultimateParent(int n) {
        if (parent[n] == n) {
            return n;
        }
        return parent[n] = ultimateParent(parent[n]);
    }
    void unionByRank(int i, int j) {
        int rootI = ultimateParent(i);  // Find the root of i
        int rootJ = ultimateParent(j);  // Find the root of j

        if (rootI != rootJ) {  // Only union if they are different sets
            if (rank[rootI] > rank[rootJ]) {
                parent[rootJ] = rootI;
            } else if (rank[rootI] < rank[rootJ]) {
                parent[rootI] = rootJ;
            } else {
                parent[rootJ] = rootI;
                rank[rootI]++;  // Increase rank if both have the same rank
            }
        }
    }
};

struct KruskalNode {
    int node;
    int connectedNode;
    int weight;
    bool operator<(const KruskalNode &other) const {
        return weight > other.weight;  // Min-heap behavior
    }
};

void kruskal(vector<vector<pair<int, int>>> adj_list, int start) {
    priority_queue<KruskalNode> edges;
    DisjointSet ds(adj_list.size());
    for (int i = 0; i < adj_list.size(); i++) {
        // auto k = adj_list[i];
        for (auto &j : adj_list[i]) {
            if (i < j.first) {
                edges.push({i, j.first, j.second});  // i -> j
            }
        }
    }

    while (!edges.empty()) {
        KruskalNode edge = edges.top();
        edges.pop();
        // cout << edge.node << " - " << edge.connectedNode << " : " <<
        // edge.weight
        //      << endl;
        if (ds.ultimateParent(edge.node) !=
            ds.ultimateParent(edge.connectedNode)) {
            ds.unionByRank(edge.node, edge.connectedNode);
            cout << edge.node << " - " << edge.connectedNode << " : "
                 << edge.weight << endl;
        }
    }
}

int main() {
    // Fixed weighted graph represented as an adjacency matrix
    int graph[8][8] = {
        {0, 4, 8, 0, 0, 0, 0, 0},  // Edge from 0 to 1 (4), 0 to 2 (8)
        {4, 0, 0, 7, 9, 0, 0,
         0},  // Edge from 1 to 0 (4), 1 to 3 (7), 1 to 4 (9)
        {8, 0, 0, 0, 6, 2, 0,
         0},  // Edge from 2 to 0 (8), 2 to 4 (6), 2 to 5 (2)
        {0, 7, 0, 0, 0, 0, 14, 0},  // Edge from 3 to 1 (7), 3 to 6 (14)
        {0, 9, 6, 0, 0, 0, 0,
         10},  // Edge from 4 to 1 (9), 4 to 2 (6), 4 to 7 (10)
        {0, 0, 2, 0, 0, 0, 0, 11},  // Edge from 5 to 2 (2), 5 to 7 (11)
        {0, 0, 0, 14, 0, 0, 0, 0},  // Edge from 6 to 3 (14)
        {0, 0, 0, 0, 10, 11, 0, 0}  // Edge from 7 to 4 (10), 7 to 5 (11)
    };

    // Print the graph as an adjacency matrix
    // cout << "Graph as adjacency matrix (with weights):" << endl;
    // printGraphMatrix(graph);

    // Convert adjacency matrix to adjacency list
    vector<vector<pair<int, int>>> adj_list = matrixToList(graph);

    // Print the adjacency list representation
    cout << "Graph as adjacency list (with weights):" << endl;
    printAdjacencyList(adj_list);

    // Perform BFS traversal
    // cout << "BFS traversal starting from node 0:" << endl;
    // BFS(adj_list, 0);
    // cout << endl;

    // Perform iterative DFS traversal
    // cout << "Iterative DFS traversal starting from node 0:" << endl;
    // DFS(adj_list, 0);
    // cout << endl;

    // Perform recursive DFS traversal
    // cout << "Recursive DFS traversal starting from node 0:" << endl;
    // dfs(adj_list, 0);
    // cout << endl;

    prims(adj_list, 0);
    cout << endl;
    kruskal(adj_list, 0);

    return 0;
}
