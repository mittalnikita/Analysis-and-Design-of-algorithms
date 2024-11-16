#include <iostream>
#include <vector>
#include <limits.h>
#include <set>

const int INF = INT_MAX;

using namespace std;

class Graph
{
public:
    vector<vector<int>> costMatrix;
    int numCities;

public:
    Graph(int n) : numCities(n), costMatrix(n, vector<int>(n, 0)) {}

    void setCostMatrix(const vector<vector<int> > &matrix)
    {
        costMatrix = matrix;
    }
};

class TravelingSalesman
{
private:
    Graph &graph;

public:
    TravelingSalesman(Graph &g) : graph(g) {}

    int tsp(int pos, const set<int> &rem)
    {
        if (rem.empty())
        {
            return graph.costMatrix[pos][0];
        }

        int ans1 = INF;
        for (int v : rem)
        {
            set<int> newrem = rem;
            newrem.erase(v);

            int ans2 = graph.costMatrix[pos][v] + tsp(v, newrem);
            ans1 = min(ans1, ans2);
        }

        return ans1;
    }
};

int main()
{
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    Graph graph(n);
    vector<vector<int> > costMatrix(n, vector<int>(n));

    cout << "Enter the cost matrix (0 if no direct path):\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> costMatrix[i][j];
        }
    }

    set<int> rem;
    for (int i = 1; i < n; i++)
    {
        rem.insert(i);
    }

    graph.setCostMatrix(costMatrix);
    TravelingSalesman p1(graph);

    int minCost = p1.tsp(0, rem);
    if (minCost == INF)
    {
        cout << "It is not possible to visit all cities." << endl;
    }
    else
    {
        cout << "Minimum cost of traveling is: " << minCost << endl;
    }

    return 0;
}