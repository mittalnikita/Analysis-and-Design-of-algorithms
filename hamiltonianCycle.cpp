#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjMatrix;

public:
    // Constructor to initialize the graph with a given number of vertices
    Graph(int V) : vertices(V), adjMatrix(V, vector<int>(V, 0)) {}

    // Method to add an edge between two vertices
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;  // Assuming undirected graph
    }

    // Method to check if there is an edge between two vertices
    bool isEdge(int u, int v) const {
        return adjMatrix[u][v] == 1;
    }

    // Method to get the number of vertices
    int getVertices() const {
        return vertices;
    }
};

class HamiltonianCycle {
private:
    Graph& graph;
    vector<int> path;
    
public:
    // Constructor to initialize the Hamiltonian Cycle class with a graph reference
    HamiltonianCycle(Graph& g) : graph(g), path(g.getVertices(), -1) {}

    // Utility function to check if the current vertex can be added to the Hamiltonian cycle
    bool isSafe(int v, int pos) {
        // Check if the vertex is adjacent to the previous vertex in the path
        if (!graph.isEdge(path[pos - 1], v)) {
            return false;
        }

        // Check if the vertex has already been included in the path
        for (int i = 0; i < pos; i++) {
            if (path[i] == v) {
                return false;
            }
        }
        return true;
    }

    // Recursive utility function to solve the Hamiltonian Cycle problem
    bool solveHamiltonianUtil(int pos) {
        // If all vertices are included in the path, check if there is an edge from the last included vertex to the first vertex
        if (pos == graph.getVertices()) {
            return graph.isEdge(path[pos - 1], path[0]);
        }

        // Try different vertices as the next candidate in the Hamiltonian cycle
        for (int v = 1; v < graph.getVertices(); v++) {
            if (isSafe(v, pos)) {
                path[pos] = v;

                // Recur to construct the rest of the path
                if (solveHamiltonianUtil(pos + 1)) {
                    return true;
                }

                // Backtrack
                path[pos] = -1;
            }
        }
        return false;
    }

    // Main function to solve the Hamiltonian Cycle problem
    bool solveHamiltonianCycle() {
        path[0] = 0; // Start at the first vertex

        if (!solveHamiltonianUtil(1)) {
            cout << "No Hamiltonian Cycle exists." << endl;
            return false;
        }

        printSolution();
        return true;
    }

    // Function to print the Hamiltonian cycle
    void printSolution() {
        cout << "Hamiltonian Cycle exists: ";
        for (int i = 0; i < graph.getVertices(); i++) {
            cout << path[i] << " ";
        }
        cout << path[0] << " ";  // Complete the cycle by returning to the starting vertex
        cout << endl;
    }
};

int main() {
    int V = 5;
    Graph g(V);

    // Add edges to form a Hamiltonian cycle
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
    g.addEdge(1, 3);

    HamiltonianCycle hc(g);
    hc.solveHamiltonianCycle();

    return 0;
}
