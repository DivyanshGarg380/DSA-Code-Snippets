#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Global adjacency matrix for graph representation
int g[100][100];

class Graph {
public:
    int V; // Number of vertices in the graph

    // Constructor to initialize the number of vertices
    Graph(int vertices) {
        V = vertices;
    }

    // Function to add an undirected edge with a given weight
    void addEdge(int src, int v, int wt) {
        g[src][v] = wt;
        g[v][src] = wt; // because the graph is undirected
    }

    // Function to implement Prim's Algorithm
    void Prims(int src) {
        // Min-heap (priority queue) to store (weight, vertex)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // mst[i] = true if vertex i is included in MST
        vector<bool> mst(V, false);

        // Start from the source vertex
        pq.push(make_pair(0, src));

        int ans = 0; // To store the total weight of MST

        // While there are edges in the priority queue
        while (!pq.empty()) {
            int u = pq.top().second;  // Get the vertex
            int edgewt = pq.top().first;  // Get the edge weight
            pq.pop();

            // If the vertex is not already included in MST
            if (!mst[u]) {
                mst[u] = true;           // Mark vertex as included
                ans = ans + edgewt;      // Add edge weight to MST cost

                // Traverse all adjacent vertices
                for (int i = 0; i < V; i++) {
                    // If there is an edge and vertex i is not in MST
                    if (g[u][i] != 0 && !mst[i]) {
                        // Push the edge (weight, vertex) to priority queue
                        pq.push(make_pair(g[u][i], i));
                    }
                }
            }
        }

        // Print the total weight of MST
        cout << "The MST of given graph is: " << ans << endl;
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph g1(5);

    // Add weighted edges
    g1.addEdge(0, 1, 5);
    g1.addEdge(1, 2, 6);
    g1.addEdge(0, 2, 13);
    g1.addEdge(1, 3, 20);
    g1.addEdge(3, 4, 15);

    // Run Prim's algorithm starting from vertex 0
    g1.Prims(0);

    return 0;
}

