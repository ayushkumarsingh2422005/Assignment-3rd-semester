#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// A structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Function to implement the Bellman-Ford algorithm
void bellmanFord(int vertices, int edges, vector<Edge> &graph, int src) {
    // Initialize distances from source to all vertices as infinite
    vector<int> distance(vertices, INT_MAX);
    distance[src] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 0; i < vertices - 1; i++) {
        for (int j = 0; j < edges; j++) {
            int u = graph[j].src;
            int v = graph[j].dest;
            int weight = graph[j].weight;

            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (int j = 0; j < edges; j++) {
        int u = graph[j].src;
        int v = graph[j].dest;
        int weight = graph[j].weight;

        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }

    // Print the shortest distances
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < vertices; i++) {
        cout << i << "\t" << (distance[i] == INT_MAX ? "INF" : to_string(distance[i])) << endl;
    }
}

int main() {
    int vertices = 5; // Number of vertices
    int edges = 8;    // Number of edges

    // Create a graph with 8 edges
    vector<Edge> graph = {
        {0, 1, -1}, {0, 2, 4},
        {1, 2, 3}, {1, 3, 2}, {1, 4, 2},
        {3, 2, 5}, {3, 1, 1},
        {4, 3, -3}};

    int source = 0;
    bellmanFord(vertices, edges, graph, source);

    return 0;
}
