#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Graph {
    int V;                        // Number of vertices
    vector<vector<int>> adjList;  // Adjacency list
    vector<bool> visited_dfs;

   public:
    // Constructor
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
        visited_dfs.resize(V, false);
    }

    // Add an edge to the graph (undirected graph)
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Print the adjacency list
    void printGraph() {
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << ":";
            for (auto v : adjList[i]) {
                cout << " -> " << v;
            }
            cout << endl;
        }
    }
    void BFS(int start) {
        vector<bool> visited(V, false);  // Track visited vertices
        queue<int> q;

        // Start BFS from the starting vertex
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            cout << vertex << " ";

            // Explore all adjacent vertices
            for (auto adj : adjList[vertex]) {
                if (!visited[adj]) {
                    visited[adj] = true;
                    q.push(adj);
                }
            }
        }
    }
     // Track visited vertices
    void DFS(int start) {
        visited_dfs[start] = true;
        cout << start << " ";
        for (auto adj : adjList[start]) {
            if (!visited_dfs[adj]) {
                DFS(adj);
            }
        }
    }

    void dfs_helper(vector<bool>& visited, int start) {
        visited[start] = true;
        cout << start << " ";
        for (auto adj : adjList[start]) {
            if (!visited[adj]) {
                dfs_helper(visited, adj);
            }
        }
    }


    void dfs(int start){
        vector<bool> visited(V, false);
        dfs_helper(visited, start);
    }
};

int main() {
    int V = 5;  // Number of vertices
    Graph graph(V);

    // Adding edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Printing the adjacency list
    graph.printGraph();
    cout << "BFS traversal: ";  // Start BFS from vertex 0
    graph.BFS(0);
    cout << endl;
    cout << "DFS traversal: ";
    graph.dfs(0);
    graph.dfs(0);
    cout << endl;

    return 0;
}
