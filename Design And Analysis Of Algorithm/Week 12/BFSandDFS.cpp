#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Graph {
    int V;
    vector<int> *adj;
};

void initializeGraph(Graph &graph, int V) {
    graph.V = V;
    graph.adj = new vector<int>[V];
}

void addEdge(Graph &graph, int u, int v) {
    graph.adj[u].push_back(v);
    graph.adj[v].push_back(u); // For undirected graph
}

void BFS(Graph &graph, int start) {
    vector<bool> visited(graph.V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph.adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void DFSUtil(Graph &graph, int node, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph.adj[node]) {
        if (!visited[neighbor]) {
            DFSUtil(graph, neighbor, visited);
        }
    }
}

void DFS(Graph &graph, int start) {
    vector<bool> visited(graph.V, false);
    DFSUtil(graph, start, visited);
}

int main() {
    Graph graph;
    initializeGraph(graph, 5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    cout << "BFS: ";
    BFS(graph, 0);
    cout << "\nDFS: ";
    DFS(graph, 0);

    delete[] graph.adj; // Clean up memory
    return 0;
}
