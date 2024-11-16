#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Item {
public:
    int value;
    int weight;

    Item(int v, int w) : value(v), weight(w) {}
};

class FractionalKnapsack {
private:
    vector<Item> items;
    vector<vector<double>> memo;

    double knapsack(int W, int index) {
        // Base case: no items left or no capacity
        if (index >= items.size() || W <= 0) {
            return 0.0;
        }

        // Check if already computed
        if (memo[index][W] != -1) {
            return memo[index][W];
        }

        // Take the whole item if it fits
        if (items[index].weight <= W) {
            memo[index][W] = items[index].value + knapsack(W - items[index].weight, index + 1);
        } 
        else {
            // Take a fraction of the item
            double fractionValue = (double)items[index].value * (W / (double)items[index].weight);
            memo[index][W] = fractionValue + knapsack(0, index + 1);
        }

        return memo[index][W];
    }

public:
    FractionalKnapsack(vector<Item> itemsList) : items(itemsList) {
        // Initialize memoization table
        memo.resize(items.size(), vector<double>(1001, -1)); // Assuming max weight of 1000
    }

    double getMaxValue(int W) {
        return knapsack(W, 0);
    }
};

int main() {
    int W = 50; // Maximum weight of the knapsack
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}}; // {value, weight}

    FractionalKnapsack knapsackSolver(items);
    double maxValue = knapsackSolver.getMaxValue(W);

    cout << "Maximum value in Knapsack = " << maxValue << endl;
    return 0;
}
