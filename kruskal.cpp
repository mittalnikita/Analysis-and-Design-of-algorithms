#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet {
private:
    vector<int> parent, rank;

public:
    DisjointSet(int v) {
        parent.resize(v, -1);
        rank.resize(v, 1);
    }

    int find(int node) {
        if (parent[node] == -1) {
            return node;
        }
        find(parent[node]);
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } 
            else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } 
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

struct Edge {
    int u, v, weight;

    // Comparator for sorting edges by weight
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class Graph {
private:
    int V;  // Number of vertices
    vector<Edge> edges;  // List of edges

public:
    Graph(int V) : V(V) {}

    void addEdge(int u, int v, int weight) {
        edges.push_back({u, v, weight});
    }

    void kruskalMST() {
        
        sort(edges.begin(), edges.end());

        DisjointSet ds(V);

        vector<Edge> mst;  

        for (const auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;

            int set_u = ds.find(u);
            int set_v = ds.find(v);

            if (set_u != set_v) {
                mst.push_back(edge);
                ds.unionSets(set_u, set_v);
            }
        }

        cout << "Edges in the Minimum Spanning Tree :\n";
        for (const auto& edge : mst) {
            cout << edge.u << " ---- " << edge.v << " == " << edge.weight <<endl;
        }
    }
};

int main() {
    int V = 6;
    Graph g(V);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 3);
    g.addEdge(0, 3, 2);
    g.addEdge(1, 2, 4);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 6);

    g.kruskalMST();

    return 0;
}
