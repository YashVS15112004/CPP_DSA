#include <bits/stdc++.h>
using namespace std;
// Function to count the number of subsets with a given sum
int findWaysUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if(ind == 0){
        if(target==0 && arr[0]==0)
            return 2;
        if(target==0 || target == arr[0])
            return 1;
        return 0;
    }
    // If the result for this state is already calculated, return it
    if (dp[ind][target] != -1)
        return dp[ind][target];
    // Recursive cases
    // 1. Exclude the current element
    int notTaken = findWaysUtil(ind - 1, target, arr, dp);
    // 2. Include the current element if it doesn't exceed the target
    int taken = 0;
    if (arr[ind] <= target)
        taken = findWaysUtil(ind - 1, target - arr[ind], arr, dp);
    // Store the result in the DP table and return
    return dp[ind][target] = notTaken + taken;
}
// Function to count the number of subsets with a given sum
int findWays_MEM(vector<int>& num, int k) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return findWaysUtil(n - 1, k, num, dp);
}
int findWays_TAB(vector<int>& num, int k) {
    int n = num.size();
    // Create a 2D DP table with dimensions n x k+1, initialized with zeros
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    if(num[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
    else dp[0][0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=k) dp[0][num[0]] = 1;  // 1 case -pick

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {
            // Exclude the current element
            int notTaken = dp[ind - 1][target];
            // Include the current element if it doesn't exceed the target
            int taken = 0;
            if (num[ind] <= target) {
                taken = dp[ind - 1][target - num[ind]];
            }
            // Update the DP table
            dp[ind][target] = notTaken + taken;
        }
    }
    // The final result is in the last cell of the DP table
    return dp[n - 1][k];
}
int findWays_OPT(vector<int>& num, int k) {
    int n = num.size();
    // Initialize a vector 'prev' to represent the previous row of the DP table
    vector<int> prev(k + 1, 0);
    if(num[0] == 0) prev[0] =2;  // 2 cases -pick and not pick
    else prev[0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=k) prev[num[0]] = 1;  // 1 case -pick
    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        // Create a vector 'cur' to represent the current row of the DP table
        vector<int> cur(k + 1, 0);
        cur[0] = 1;
        for (int target = 1; target <= k; target++) {
            // Exclude the current element
            int notTaken = prev[target];
            // Include the current element if it doesn't exceed the target
            int taken = 0;
            if (num[ind] <= target) {
                taken = prev[target - num[ind]];
            }
            // Update the current row of the DP table
            cur[target] = notTaken + taken;
        }
        // Set 'cur' as 'prev' for the next iteration
        prev = cur;
    }
    // The final result is in the last cell of the 'prev' vector
    return prev[k];
}
int main() {
    vector<int> arr = {1, 2, 2, 3};
    int k = 3;
    cout << "The number of subsets found are " << findWays_OPT(arr, k);
    return 0;
}