#include <iostream>
#include <queue>
#include <stack>
#include <vector>
// #include <priori
using namespace std;

void printGraphMatrix(int graph[][8]) {
    for (int i = 0; i < 8; i++) {
        cout << i << " : ";
        for (int j = 0; j < 8; j++) {
            if (graph[i][j] == 1) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}
vector<vector<int>> matrixToList(int matrix[][8]) {
    vector<vector<int>> adj_list(8);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (matrix[i][j] == 1) {
                adj_list[i].push_back(j);
            }
        }
    }
    return adj_list;
}
void printAdjacencyList(vector<vector<int>> adj_list) {
    for (int i = 0; i < 8; i++) {
        cout << i << " : ";
        for (int j = 0; j < adj_list[i].size(); j++) {
            cout << adj_list[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void BFS(vector<vector<int>> adj_list, int start) {
    queue<int> que;
    vector<int> visited(adj_list.size());
    que.push(start);
    visited[start] = 1;
    while (!que.empty()) {
        int current = que.front();
        cout << current << " ";
        que.pop();
        for (int i : adj_list[current]) {
            if (visited[i] != 1) {
                que.push(i);
                visited[i] = 1;
            }
        }
    }
}
void DFS(vector<vector<int>> adj_list, int start) {
    vector<int> visited(adj_list.size());
    stack<int> st;
    visited[start] = 1;
    st.push(start);
    while (!st.empty()) {
        int top = st.top();
        st.pop();
        cout << top << " ";
        for (int i : adj_list[top]) {
            if (visited[i] != 1) {
                st.push(i);
                visited[i] = 1;
            }
        }
    }
}
void dfsHelper(vector<vector<int>>& adj_list, vector<int>& visited, int start) {
    if (visited[start] == 1) {
        return;
    }
    cout << start << " ";
    visited[start] = 1;
    for (int i : adj_list[start]) {
        if (visited[i] != 1) {
            // visited[i] = 1;
            dfsHelper(adj_list, visited, i);
        }
    }
}
void dfs(vector<vector<int>> adj_list, int start) {
    vector<int> visited(adj_list.size());
    dfsHelper(adj_list, visited, start);
}
// void prims(vector<vector<int>>& adj_list, int start) {
//     struct Node {
//         int wt;
//         int data;
//         int parent;
//         bool operator<(const Node& other) const {
//             return wt > other.wt;  // For a min-heap, use `wt > other.wt`
//         }
//     };
//     priority_queue<Node> pq;
//     vector<int> visited(adj_list.size());
//     vector<Node> mst;
//     pq.push({0, start, -1});
//     while (!pq.empty()) {
//         Node node = pq.top();
//         pq.pop();
//         visited[node.data] = 1;
//         for (int i : adj_list[node.data])
//         {
//             if (visited[i]!=1)
//             {
//                 pq.push({})
//             }
            
//         }
        
//     }
// }

// int main() {
//     int graph_matrix[][8] = {
//         {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 1, 0, 0, 0},
//         {0, 1, 0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 1, 1, 0, 0},
//         {0, 1, 0, 1, 0, 1, 0, 0}, {0, 0, 0, 1, 1, 0, 1, 1},
//         {0, 0, 0, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 0, 1, 1, 0},
//     };
//     vector<vector<int>> adj_list = matrixToList(graph_matrix);
//     BFS(adj_list, 5);
//     cout << endl;
//     DFS(adj_list, 5);
//     cout << endl;
//     dfs(adj_list, 5);
// }

// Function to convert adjacency matrix to adjacency list
vector<pair<int, int>>* convertMatrixToList(int adjMatrix[][4], int n) {
    // Create an adjacency list as an array of vectors of pairs
    vector<pair<int, int>>* adjList = new vector<pair<int, int>>[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adjMatrix[i][j] != 0) { // Check for an edge with non-zero weight
                adjList[i].push_back({j, adjMatrix[i][j]});
            }
        }
    }

    return adjList;
}

// Function to print the adjacency list
void printAdjList(vector<pair<int, int>>* adjList, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Index " << i + 1 << ": ";
        for (const auto& pair : adjList[i]) {
            cout << "{" << pair.first + 1 << ", " << pair.second << "} ";
        }
        cout << endl;
    }
}

int main() {
    // Define the adjacency matrix
    int adjMatrix[4][4] = {
        {0, 2, 3, 0},
        {2, 0, 4, 5},
        {3, 4, 0, 6},
        {0, 5, 6, 0}
    };

    int n = 4; // Number of nodes

    // Convert the adjacency matrix to an adjacency list
    vector<pair<int, int>>* adjList = convertMatrixToList(adjMatrix, n);

    // Print the adjacency list
    printAdjList(adjList, n);

    // Free the dynamically allocated memory
    delete[] adjList;

    return 0;
}