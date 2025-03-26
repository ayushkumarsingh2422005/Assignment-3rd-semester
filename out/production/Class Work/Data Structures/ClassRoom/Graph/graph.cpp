#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> convertMatrixToList(int graph[][8], int size) {
    vector<vector<int>> adj_list(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (graph[i][j] == 1) {
                adj_list[i].push_back(j);
            }
        }
    }
    return adj_list;
}

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

void printAdjacencyList(const vector<vector<int>>& adj_list) {
    for (int i = 0; i < adj_list.size(); i++) {
        cout << i << " : ";
        for (int j : adj_list[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

// BFS
void BFS(vector<vector<int>> adj_list, int start_node) {
    queue<int> que;
    vector<int> visited(adj_list.size());
    que.push(start_node);
    visited[start_node] = 1;

    while (!que.empty()) {
        int front = que.front();
        que.pop();
        cout << front << " ";

        for (int j : adj_list[front]) {
            if (visited[j] != 1) {
                visited[j] = 1;
                que.push(j);
            }
        }
    }
}

// bfs
void BFS(int graph[][8], int size, int start_node) {
    queue<int> que;
    int visited[size + 1] = {0};
    que.push(start_node);
    visited[start_node] = 1;
    while (!que.empty()) {
        int front = que.front();
        que.pop();
        cout << front << " ";
        for (int j = 0; j <= size; j++) {
            if (graph[front][j] == 1) {
                if (visited[j] != 1) {
                    visited[j] = 1;
                    que.push(j);
                }
            }
        }
    }
}

int main() {
    int graph_matrix[][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 1, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 0}, {0, 0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 0, 1, 1, 0},
    };

    int size = sizeof(graph_matrix) / sizeof(graph_matrix[0]);
    cout << "Adjacency Matrix:" << endl;
    printAdjacencyMatrix(graph_matrix, size);
    // vector<vector<int>> adj_list = convertMatrixToList(graph_matrix, size);
    // cout << "Adjacency List:" << endl;
    // printAdjacencyList(adj_list);

    cout << "BFS:" << endl;
    // BFS(adj_list, 2);
    cout << endl;
    BFS(graph_matrix, size, 2);

    return 0;
}
