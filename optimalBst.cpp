#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Items {
public:
    vector<int> keys;
    vector<int> freq;

    Items(int n) {
        keys.resize(n);
        freq.resize(n);
    }
};

class OptimalBST {
private:
    Items items;
    vector<vector<int>> cost; // Cost table
    vector<vector<int>> root; // Root table for reconstruction
    int n;

public:
    OptimalBST(Items& items) : items(items), n(items.keys.size()) {
        // Resize cost and root matrices to be of size (n+1) x (n+1)
        cost.resize(n + 1, vector<int>(n + 1, 0));
        root.resize(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= n; i++) {
            cost[i][i] = 0;  // Diagonal is initialized to 0
        }

        calculateOptimalBST();
    }

    int sum(int i, int j) {
        int s = 0;
        for (int k = i; k <= j; k++)
            s += items.freq[k-1];
        return s;
    }


    void calculateOptimalBST() {

        for (int i = 0; i < n; i++) {
            
            cost[i][i + 1] = items.freq[i];  // Upper diagonal initialized with frequencies
            root[i][i + 1] = i + 1;  // Root for single node is the node itself (1-based index)
        }

        for (int l = 2; l <= n; l++) { 
            for (int i = 0; i <= n - l; i++) {
                int j = i + l; 
                cost[i][j] = INT_MAX;

                // Try all roots k from i+1 to j
                int s = sum(i+1, j);
                for (int k = i + 1; k <= j; k++) {
                    int c = cost[i][k - 1] + cost[k][j] + s;

                    if (c < cost[i][j]) {
                        cost[i][j] = c;
                        root[i][j] = k; 
                    }
                }
            }
        }
    }

    void printCost() {
        cout << "Cost Table:\n";
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i <= j) {
                    cout << (cost[i][j] == INT_MAX ? 0 : cost[i][j]) << "\t";
                } else {
                    cout << "-\t"; 
                }
            }
            cout << endl;
        }
    }

    void printRoot() {
        cout << "Root Table:\n";
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i <= j) {
                    cout << root[i][j] << "\t";
                } else {
                    cout << "-\t";
                }
            }
            cout << endl;
        }
    }
};

class Graph {
public:
    Graph() {}

    void optimalBSTFromAdjMatrix(vector<vector<int>>& adjMatrix) {
        int n = adjMatrix.size(); // Number of keys

        Items items(n);

        for (int i = 0; i < n; i++) {
            items.keys[i] = adjMatrix[i][0]; // First column as keys
            items.freq[i] = adjMatrix[i][1]; // Second column as frequencies
        }

        OptimalBST optimalBST(items);
        optimalBST.printCost();
        optimalBST.printRoot();
    }
};

int main() {
   
    // [key, frequency]
    vector<vector<int>> adjMatrix = {
        {10, 2},
        {12, 4},
        {20, 3}
    };

    Graph g;
    g.optimalBSTFromAdjMatrix(adjMatrix);

    return 0;
}