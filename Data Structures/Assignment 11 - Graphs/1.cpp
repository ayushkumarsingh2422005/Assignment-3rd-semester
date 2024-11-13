#include <iostream>
#include <queue>
using namespace std;

// Function to print adjacency matrix
void printAdjacencyMatrix(int graph[][8], int size) {
    for (int i = 0; i < size; i++) {
        cout << i << " : ";
        for (int j = 0; j < size; j++) {
            if (graph[i][j] == 1) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// BFS with cycle detection
void BFS(int graph[][8], int size, int start_node) {
    bool isCyclic = false;
    queue<int> que;
    int visited[8] = {0};
    int parent[8] = {-1};

    que.push(start_node);
    visited[start_node] = 1;
    cout << "BFS Traversal: ";

    while (!que.empty()) {
        int front = que.front();
        que.pop();
        cout << front << " ";

        for (int j = 0; j < size; j++) {
            if (graph[front][j] == 1) {
                if (visited[j] == 0) {
                    visited[j] = 1;
                    que.push(j);
                    parent[j] = front;
                } else if (parent[front] != j) {
                    isCyclic = true;
                    cout << "\nCycle detected between nodes " << front << " and " << j << endl;
                }
            }
        }
    }

    if (!isCyclic) {
        cout << "\nNo cycles detected." << endl;
    }
}

bool DFSUtil(int graph[][8], int size, int node, int visited[], int recStack[]) {
    visited[node] = 1;
    recStack[node] = 1;  // Mark node as part of the recursion stack
    cout << node << " ";

    // Explore all adjacent nodes
    for (int j = 0; j < size; j++) {
        if (graph[node][j] == 1) {
            if (!visited[j]) {
                // Recursive call to DFS on unvisited node
                if (DFSUtil(graph, size, j, visited, recStack)) {
                    return true;  // Cycle detected in recursive call
                }
            } else if (recStack[j]) {
                // Back edge detected, indicating a cycle
                cout << "\nBack edge detected between nodes " << node << " and " << j << " (Cycle found)" << endl;
                return true;
            }
        }
    }
    
    // Remove the node from the recursion stack
    recStack[node] = 0;
    return false;
}

// DFS with cycle detection
void DFS(int graph[][8], int size, int start_node) {
    int visited[8] = {0};
    int recStack[8] = {0};  // Recursion stack for cycle detection

    cout << "DFS Traversal: ";
    if (DFSUtil(graph, size, start_node, visited, recStack)) {
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "\nNo cycles detected in the graph." << endl;
    }
}

int main() {
    int graph_matrix[][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 1, 1, 0},
    };

    int size = sizeof(graph_matrix) / sizeof(graph_matrix[0]);
    cout << "Adjacency Matrix:" << endl;
    printAdjacencyMatrix(graph_matrix, size);

    cout << "\nPerforming BFS with cycle detection from node 2:" << endl;
    BFS(graph_matrix, size, 2);

    cout << "\nPerforming DFS with cycle detection from node 2:" << endl;
    DFS(graph_matrix, size, 2);

    return 0;
}
