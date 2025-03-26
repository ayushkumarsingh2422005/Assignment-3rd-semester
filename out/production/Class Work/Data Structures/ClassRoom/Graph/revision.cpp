#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
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


int main() {
    // Dummy graph represented as an adjacency matrix
    int graph[8][8] = {
        {0, 1, 1, 0, 0, 0, 0, 0}, // Edges from node 0 to 1 and 2
        {1, 0, 0, 1, 1, 0, 0, 0}, // Edges from node 1 to 0, 3, and 4
        {1, 0, 0, 0, 1, 1, 0, 0}, // Edges from node 2 to 0, 4, and 5
        {0, 1, 0, 0, 0, 0, 1, 0}, // Edge from node 3 to 1 and 6
        {0, 1, 1, 0, 0, 0, 0, 1}, // Edges from node 4 to 1, 2, and 7
        {0, 0, 1, 0, 0, 0, 0, 1}, // Edges from node 5 to 2 and 7
        {0, 0, 0, 1, 0, 0, 0, 0}, // Edge from node 6 to 3
        {0, 0, 0, 0, 1, 1, 0, 0}  // Edges from node 7 to 4 and 5
    };

    // Print the graph as an adjacency matrix
    cout << "Graph as adjacency matrix:" << endl;
    printGraphMatrix(graph);

    // Convert adjacency matrix to adjacency list
    vector<vector<int>> adj_list = matrixToList(graph);

    // Print the adjacency list representation
    cout << "Graph as adjacency list:" << endl;
    printAdjacencyList(adj_list);

    // Perform BFS traversal
    cout << "BFS traversal starting from node 0:" << endl;
    BFS(adj_list, 0);
    cout << endl;

    // Perform iterative DFS traversal
    cout << "Iterative DFS traversal starting from node 0:" << endl;
    DFS(adj_list, 0);
    cout << endl;

    // Perform recursive DFS traversal
    cout << "Recursive DFS traversal starting from node 0:" << endl;
    dfs(adj_list, 0);
    cout << endl;

    return 0;
}
