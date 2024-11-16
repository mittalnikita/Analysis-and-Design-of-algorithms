#include <iostream>  // all pair shortest path
#include <vector>
#define INF 99999

using namespace std;

class FloydWarshall {
private:
    int V; // Number of vertices
    vector<vector<int>> dist; // Distance matrix ---> result

public:
    // Constructor to initialize the graph with vertices
    FloydWarshall(int vertices) {
        V = vertices;
        dist.resize(V, vector<int>(V, INF)); // Initialize all distances to infinity
    }

    void addEdge(int u, int v, int weight) {
        dist[u][v] = weight; // Add the weight to the distance matrix
    }

    // Main algorithm to calculate shortest paths
    void shortestPathMatrix() {

        for (int k = 0; k < V; k++) {  // k is the intermediatory node
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    // If vertex k is on the shortest path from i to j, update the distance
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    void printDistances() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INF)
                    cout << "INF" << " ";
                else
                    cout << dist[i][j] << "   ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices = 3;
    FloydWarshall g(vertices);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 10);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 1, 9);
    g.addEdge(2, 0, 8);

    cout << "Initial distances' matrix :" << endl;
    g.printDistances();

    g.shortestPathMatrix();

    cout << "\nShortest path matrix showing distances between every pair of vertices:" << endl;
    g.printDistances();

    return 0;
}
