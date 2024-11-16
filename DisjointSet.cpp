#include <iostream>
#include <vector>

class DisjointSet {
private:
    std::vector<int> parent;  // Stores the parent of each element
    std::vector<int> rank;    // Stores the rank (or depth) of each tree

public:
    // Constructor to initialize the disjoint set with n elements
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        // Initially, each element is its own parent (a separate set)
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Find the representative (root) of the set that element x is in
    int find(int x) {
        if (parent[x] != x) {
            // Path compression heuristic: make the found root the parent of x
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union the sets that contain x and y
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        // If they are already in the same set, no need to union
        if (rootX != rootY) {
            // Union by rank heuristic
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    // Check if elements x and y are in the same set
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    // Create a Disjoint Set with 5 elements (0 to 4)
    DisjointSet ds(5);

    ds.unionSets(0, 2);
    ds.unionSets(4, 2);
    ds.unionSets(3, 1);

    std::cout << "0 and 4 connected: " << ds.connected(0, 4) << std::endl; // Should print 1 (true)
    std::cout << "1 and 0 connected: " << ds.connected(1, 0) << std::endl; // Should print 0 (false)

    ds.unionSets(1, 0);

    std::cout << "1 and 0 connected after union: " << ds.connected(1, 0) << std::endl; // Should print 1 (true)

    return 0;
}
