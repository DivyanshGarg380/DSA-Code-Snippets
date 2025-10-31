#include <iostream>
#include <vector>
using namespace std;

const int V = 5; // Number of vertices
vector<pair<int, int>> adjList[V]; // Adjacency list

// Function to add an edge
void addEdge(int u, int v, int weight) {
    adjList[u].push_back({v, weight});
    adjList[v].push_back({u, weight}); // Because the graph is undirected
}

// Function to print the graph
void printGraph() {
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": ";
        for (auto& neighbor : adjList[i]) {
            cout << "(" << neighbor.first << ", weight=" << neighbor.second << ") ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Maitry A.Santoshwar" << endl;
    cout << "Roll No: 241071064" << endl;

    // New set of edges
    addEdge(0, 2, 15);
    addEdge(0, 3, 25);
    addEdge(1, 2, 35);
    addEdge(1, 4, 45);
    addEdge(2, 4, 55);
    addEdge(3, 4, 65);

    // Printing the graph
    printGraph();

    return 0;
}
