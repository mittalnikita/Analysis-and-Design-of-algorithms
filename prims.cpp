#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
 
const int INF = 1e9;  // Infinite value to represent unreachable nodes

// (for an undirected graph)
void addEdge(vector<pair<int, int>> adj[], int u, int v, int weight) {
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
}

// Prim's Algorithm to find the Minimum Spanning Tree (MST)
void primMST(vector<pair<int, int>> adj[], int V) {
    // Min-heap priority queue to select the edge with the smallest weight
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Array to store the minimum edge weight to reach each vertex
    vector<int> key(V, INF);

    // Array to check if a vertex is included in the MST or not
    vector<bool> inMST(V, false);

    // Array to store the parent (previous vertex) of each vertex in the MST
    vector<int> parent(V, -1);

    // Start from the first vertex (vertex 0) and set its key value to 0
    key[0] = 0;
    pq.push({0, 0});  // {key, vertex}

    // Prim's algorithm: process the graph until the priority queue is empty
    while (!pq.empty()) {
        // Extract the vertex with the smallest key value
        int u = pq.top().second;
        pq.pop();

        // Mark the vertex as included in the MST
        inMST[u] = true;

        // Traverse all the adjacent vertices of the current vertex u
        for (auto &[v, weight] : adj[u]) {
            // If vertex v is not in the MST and the weight of u-v is smaller than the current key of v
            if (!inMST[v] && weight < key[v]) {
                // Update the key and parent for vertex v
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    // Print the edges of the Minimum Spanning Tree
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " -- " << i << " == " << key[i] << "\n";
    }
}

int main() {

    vector<pair<int, int>> adj[5]; // No. of vertices = 5

    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 3, 6);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 1, 3, 8);
    addEdge(adj, 1, 4, 5);
    addEdge(adj, 2, 4, 7);
    addEdge(adj, 3, 4, 9);

    primMST(adj, 5);

    return 0;
}
