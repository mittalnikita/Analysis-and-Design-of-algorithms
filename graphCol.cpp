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

    // Method to get the number of vertices
    int getVertices() const { return vertices; }

    // Method to check if there is an edge between two vertices
    bool isEdge(int u, int v) const { return adjMatrix[u][v] == 1; }
};

class GraphColoring {
private:
    Graph& graph;
    int numColors;
    vector<int> colors;

public:
    // Constructor to initialize the graph coloring problem with the graph and number of colors
    GraphColoring(Graph& g, int c) : graph(g), numColors(c), colors(g.getVertices(), 0) {}

    // Utility function to check if the current color assignment is safe
    bool isSafe(int v, int color) {
        for (int i = 0; i < graph.getVertices(); i++) {
            if (graph.isEdge(v, i) && colors[i] == color) {
                return false;
            }
        }
        return true;
    }

    // Recursive function to solve the graph coloring problem using backtracking
    bool solveColoring(int v) {
        if (v == graph.getVertices()) {
            return true;
        }

        for (int color = 1; color <= numColors; color++) {
            if (isSafe(v, color)) {
                colors[v] = color;
                if (solveColoring(v + 1)) {
                    return true;
                }
                colors[v] = 0; // Backtrack
            }
        }
        return false;
    }

    // Function to solve the graph coloring problem
    bool solve() {
        if (!solveColoring(0)) {
            cout << "Solution does not exist." << endl;
            return false;
        }

        printSolution();
        return true;
    }

    // Utility function to print the color assignment for each vertex
    void printSolution() {
        cout << "Color assignment for vertices:" << endl;
        for (int i = 0; i < graph.getVertices(); i++) {
            cout << "Vertex " << i << " ---> Color " << colors[i] << endl;
        }
    }
};

int main() {
    int V = 4; // Number of vertices
    int numColors = 3; // Number of colors

    Graph g(V);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);

    GraphColoring gc(g, numColors);
    gc.solve();

    return 0;
}
