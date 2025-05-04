#include <bits/stdc++.h>
using namespace std;
// Function to solve the unbounded knapsack problem
int knapsackUtil(vector<int> &wt, vector<int> &val, int ind, int W, vector<vector<int>> &dp)
{
    // Base case: if we're at the first item
    if (ind == 0)
    {
        // Calculate and return the maximum value for the given weight limit
        return (W / wt[0]) * val[0];
    }

    // If the result for this index and weight limit is already calculated, return it
    if (dp[ind][W] != -1)
        return dp[ind][W];

    // Calculate the maximum value without taking the current item
    int notTaken = 0 + knapsackUtil(wt, val, ind - 1, W, dp);

    // Calculate the maximum value by taking the current item
    int taken = INT_MIN;
    if (wt[ind] <= W)
        taken = val[ind] + knapsackUtil(wt, val, ind, W - wt[ind], dp);

    // Store the maximum value in the DP table and return it
    return dp[ind][W] = max(notTaken, taken);
}
// Function to solve the unbounded knapsack problem
int unboundedKnapsack_MEM(int n, int W, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, -1)); // Create a DP table

    // Call the utility function to calculate the maximum value
    return knapsackUtil(wt, val, n - 1, W, dp);
}
int unboundedKnapsack_TAB(int n, int W, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0)); // Create a DP table

    // Base Condition
    for (int i = wt[0]; i <= W; i++)
    {
        dp[0][i] = (i / wt[0]) * val[0]; // Calculate the maximum value for the first item
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int cap = 0; cap <= W; cap++)
        {
            int notTaken = 0 + dp[ind - 1][cap]; // Maximum value without taking the current item

            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + dp[ind][cap - wt[ind]]; // Maximum value by taking the current item

            dp[ind][cap] = max(notTaken, taken); // Store the maximum value in the DP table
        }
    }

    return dp[n - 1][W]; // Return the maximum value considering all items and the knapsack capacity
}
int unboundedKnapsack_ON_OPT(int n, int W, vector<int> &val, vector<int> &wt)
{
    vector<int> cur(W + 1, 0); // Create a vector to store the current DP state

    // Base Condition
    for (int i = wt[0]; i <= W; i++)
    {
        cur[i] = (i / wt[0]) * val[0]; // Calculate the maximum value for the first item
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int cap = 0; cap <= W; cap++)
        {
            int notTaken = cur[cap]; // Maximum value without taking the current item

            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + cur[cap - wt[ind]]; // Maximum value by taking the current item

            cur[cap] = max(notTaken, taken); // Store the maximum value in the current DP state
        }
    }

    return cur[W]; // Return the maximum value considering all items and the knapsack capacity
}
int main()
{
    vector<int> wt = {2, 4, 6};    // Weight of items
    vector<int> val = {5, 11, 13}; // Value of items
    int W = 10;                    // Weight capacity of the knapsack
    int n = wt.size();             // Number of items

    // Call the function to calculate and output the maximum value the thief can steal
    cout << "The Maximum value of items the thief can steal is " << unboundedKnapsack_ON_OPT(n, W, val, wt) << endl;

    return 0; // Return 0 to indicate successful program execution
}