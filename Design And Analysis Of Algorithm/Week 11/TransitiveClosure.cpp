#include <iostream>
using namespace std;

void transitiveClosure(int graph[][4], int n) {
    int reach[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            reach[i][j] = graph[i][j];

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }

    cout << "Transitive closure matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << reach[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int graph[4][4] = {
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    };
    transitiveClosure(graph, 4);
    return 0;
}
