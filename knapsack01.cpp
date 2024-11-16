#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Knapsack {

public:

    // Recursive approach 
    int kp_rec(int W, const vector<int>& weights, const vector<int>& values, int n) {
        //  Base or terminating case
        if (n == 0 || W == 0) {
            return 0;
        }

        // If weight of the nth item is more than bag's capacity, just ignore this item
        if (weights[n - 1] > W) {

            return kp_rec(W, weights, values, n - 1);
        } 

        else {
           
            return max(values[n - 1] + kp_rec(W - weights[n - 1], weights, values, n - 1),
                       kp_rec(W, weights, values, n - 1));
        }
    }

    // Memoization approach
    int kp_mem(int W, const vector<int>& weights, const vector<int>& values, int n, vector<vector<int>>& memo) {

        if (memo[n][W] != -1) {
            return memo[n][W];
        }

        // Base Case
        if (n == 0 || W == 0) {
            return 0;
        }

        if (weights[n - 1] > W) {
            memo[n][W] = kp_mem(W, weights, values, n - 1, memo);
        } 
        
        else {
           
            memo[n][W] = max(values[n - 1] + kp_mem(W - weights[n - 1], weights, values, n - 1, memo),
                             kp_mem(W, weights, values, n - 1, memo));
        }

        return memo[n][W];
    }
};

int main() {
    Knapsack knapsack;
    vector<int> weights = {20, 50, 70};
    vector<int> values = {500, 100, 300};
    int capacity = 60;
    int n = weights.size();

    int profitRec = knapsack.kp_rec(capacity, weights, values, n);
    cout <<"Maximum Profit (Using Recursion): "<< profitRec << endl;

    vector<vector<int>> memo(n + 1, vector<int>(capacity + 1, -1));
    int profitMem = knapsack.kp_mem(capacity, weights, values, n, memo);
    cout <<"Maximum Profit (Using recursion + memoization): "<< profitMem << endl;

    return 0;
}
