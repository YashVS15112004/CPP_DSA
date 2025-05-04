#include<bits/stdc++.h>
using namespace std;
int solveUtil(int ind, vector<int>& arr, vector<int>& dp) {
    // Base cases
    if (ind == 0) 
        return arr[ind];
    if (ind < 0)  
        return 0;
    // If the result for this index is already computed, return it
    if (dp[ind] != -1)
        return dp[ind];
    // Choose the current element or skip it, and take the maximum
    int pick = arr[ind] + solveUtil(ind - 2, arr, dp); // Choosing the current element
    int nonPick = 0 + solveUtil(ind - 1, arr, dp);      // Skipping the current element
    // Store the result in the DP table and return it
    return dp[ind] = max(pick, nonPick);
}
// Function to initiate the solving process
int solve_mem(int n, vector<int>& arr) {
    vector<int> dp(n, -1); // Initialize the DP table with -1
    return solveUtil(n - 1, arr, dp); // Start solving from the last element
}
int solve_tab(int n, vector<int>& arr) {
    int prev = arr[0];   // Initialize the maximum sum ending at the previous element
    int prev2 = 0;       // Initialize the maximum sum ending two elements ago
    for (int i = 1; i < n; i++) {
        int pick = arr[i];  // Maximum sum if we pick the current element
        if (i > 1)
            pick += prev2;  // Add the maximum sum two elements ago
        int nonPick = 0 + prev;  // Maximum sum if we don't pick the current element
        int cur_i = max(pick, nonPick);  // Maximum sum ending at the current element
        prev2 = prev;   // Update the maximum sum two elements ago
        prev = cur_i;   // Update the maximum sum ending at the previous element
    }
    return prev;  // Return the maximum sum
}
int main()
{
    vector<int> arr = {2, 1, 4, 9};
    int n = arr.size();
    cout<<solve_mem(n,arr);
}