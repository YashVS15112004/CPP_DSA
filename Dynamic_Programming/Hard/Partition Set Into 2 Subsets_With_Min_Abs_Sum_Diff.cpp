#include <bits/stdc++.h>
using namespace std;
// Function to solve the subset sum problem with memoization
bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    // Base case: If the target sum is 0, return true
    if (target == 0)
        return dp[ind][target] = true;
    // Base case: If we have considered all elements and the target is still not 0, return false
    if (ind == 0)
        return dp[ind][target] = (arr[0] == target);
    // If the result for this state is already calculated, return it
    if (dp[ind][target] != -1)
        return dp[ind][target];
    // Recursive cases
    // 1. Exclude the current element
    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);
    // 2. Include the current element if it doesn't exceed the target
    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);
    // Store the result in the DP table and return
    return dp[ind][target] = notTaken || taken;
}
// Function to find the minimum absolute difference between two subset sums
int minSubsetSumDifference_MEM(vector<int>& arr, int n) {
    int totSum = 0;
    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }
    // Initialize a DP table to store the results of the subset sum problem
    vector<vector<int>> dp(n, vector<int>(totSum + 1, -1));
    // Calculate the subset sum for each possible sum from 0 to the total sum
    for (int i = 0; i <= totSum; i++) {
        bool dummy = subsetSumUtil(n - 1, i, arr, dp);
    }
    int mini = 1e9;
    for (int i = 0; i <= totSum; i++) {
        if (dp[n - 1][i] == true) {
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}
int minSubsetSumDifference_TAB(vector<int>& arr, int n) {
    int totSum = 0;
    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }
    // Initialize a DP table to store the results of the subset sum problem
    vector<vector<bool>> dp(n, vector<bool>(totSum + 1, false));
    // Base case: If no elements are selected (sum is 0), it's a valid subset
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }
    // Initialize the first row based on the first element of the array
    if (arr[0] <= totSum)
        dp[0][totSum] = true;
    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= totSum; target++) {
            // Exclude the current element
            bool notTaken = dp[ind - 1][target];
            // Include the current element if it doesn't exceed the target
            bool taken = false;
            if (arr[ind] <= target)
                taken = dp[ind - 1][target - arr[ind]];

            dp[ind][target] = notTaken || taken;
        }
    }
    int mini = 1e9;
    for (int i = 0; i <= totSum; i++) {
        if (dp[n - 1][i] == true) {
            // Calculate the absolute difference between two subset sums
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}
int minSubsetSumDifference_OPT(vector<int>& arr, int n) {
    int totSum = 0;
    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }
    // Initialize a boolean vector 'prev' to represent the previous row of the DP table
    vector<bool> prev(totSum + 1, false);
    // Base case: If no elements are selected (sum is 0), it's a valid subset
    prev[0] = true;
    // Initialize the first row based on the first element of the array
    if (arr[0] <= totSum)
        prev[arr[0]] = true;

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        // Create a boolean vector 'cur' to represent the current row of the DP table
        vector<bool> cur(totSum + 1, false);
        cur[0] = true;
        for (int target = 1; target <= totSum; target++) {
            // Exclude the current element
            bool notTaken = prev[target];
            // Include the current element if it doesn't exceed the target
            bool taken = false;
            if (arr[ind] <= target)
                taken = prev[target - arr[ind]];

            cur[target] = notTaken || taken;
        }
        // Set 'cur' as the 'prev' for the next iteration
        prev = cur;
    }
    int mini = 1e9;
    for (int i = 0; i <= totSum; i++) {
        if (prev[i] == true) {
            // Calculate the absolute difference between two subset sums
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}
int main() {
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();
    cout << "The minimum absolute difference is: " << minSubsetSumDifference_OPT(arr, n);
    return 0;
}