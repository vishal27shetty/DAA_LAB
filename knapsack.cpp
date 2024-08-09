#include <iostream>
#include <vector>
#include <algorithm>  // For the max function

using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapsack(int W, const vector<int>& wt, const vector<int>& val) {
    int n = wt.size();  // Number of items
    // Create a 2D DP table with dimensions (n+1) x (W+1)
    // dp[i][w] will hold the maximum value of items that can be included in a knapsack with capacity 'w' using the first 'i' items.
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Iterate over all items
    for (int i = 1; i <= n; ++i) {
        // Iterate over all possible knapsack capacities from 0 to W
        for (int w = 0; w <= W; ++w) {
            if (wt[i - 1] <= w) {
                // If the current item's weight (wt[i-1]) is less than or equal to the current capacity 'w',
                // we have two choices:
                // 1. Exclude the item: The value is the same as without this item (dp[i-1][w])
                // 2. Include the item: The value is the item's value (val[i-1]) plus the maximum value with the remaining capacity (dp[i-1][w-wt[i-1]])
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
            } else {
                // If the current item's weight exceeds the current capacity 'w', we cannot include it in the knapsack.
                // The value remains the same as without this item (dp[i-1][w])
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The value at dp[n][W] is the maximum value that can be obtained with the full capacity of the knapsack and all items considered.
    return dp[n][W];
}

int main() {
    int W = 50; // Knapsack capacity
    vector<int> wt = {10, 20, 30}; // Weights of the items
    vector<int> val = {60, 100, 120}; // Values of the items

    // Output the maximum value that can be obtained by filling the knapsack with the given items and capacity
    cout << "Max value: " << knapsack(W, wt, val) << endl;

    return 0;
}
