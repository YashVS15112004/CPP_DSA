#include <bits/stdc++.h>
using namespace std;
int countPartitionsUtil(int ind, int target, vector<int> &nums, vector<vector<int>> &dp)
{
    // Base cases
    if (ind == 0)
    {
        if (target == 0 && nums[0] == 0)
            return 2; // Two ways to partition: include or exclude the element
        if (target == 0 || target == nums[0])
            return 1; // One way to partition: include or exclude the element
        return 0;     // No way to partition
    }

    // If the result for this index and target sum is already calculated, return it
    if (dp[ind][target] != -1)
        return dp[ind][target];

    // Calculate the number of ways without taking the current element
    int notTaken = countPartitionsUtil(ind - 1, target, nums, dp);

    // Calculate the number of ways by taking the current element
    int taken = 0;
    if (nums[ind] <= target)
        taken = countPartitionsUtil(ind - 1, target - nums[ind], nums, dp);

    // Store the sum of ways in the DPnumsay and return it
    return dp[ind][target] = (notTaken + taken);
}
int findTargetSumWays_MEM(vector<int> &nums, int target)
{
    int n = nums.size();
    int totSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        totSum += nums[i];
    }

    // Checking for edge cases
    if (totSum - target < 0)
        return 0; // Not possible to achieve the target sum
    if ((totSum - target) % 2 == 1)
        return 0; // The difference between the total sum and target sum must be even

    int s2 = (totSum - target) / 2; // Calculate the required sum for each subset

    vector<vector<int>> dp(n, vector<int>(s2 + 1, -1)); // Initialize DP table
    return countPartitionsUtil(n - 1, s2, nums, dp);    // Call the helper function
}
const int mod = (int)1e9 + 7;
// Function to count the number of ways to achieve the target sum
int findWays_TAB(vector<int> &num, int tar) {
    int n = num.size();

    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

    if (num[0] == 0)
        dp[0][0] = 2;  // 2 cases - pick and not pick
    else
        dp[0][0] = 1;  // 1 case - not pick

    if (num[0] != 0 && num[0] <= tar)
        dp[0][num[0]] = 1;  // 1 case - pick

    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= tar; target++) {

            int notTaken = dp[ind - 1][target];

            int taken = 0;
            if (num[ind] <= target)
                taken = dp[ind - 1][target - num[ind]];

            dp[ind][target] = (notTaken + taken) % mod;
        }
    }
    return dp[n - 1][tar];
}
// Function to calculate the number of ways to achieve the target sum
int targetSum_TAB(int n, int target, vector<int>& arr) {
    int totSum = 0;
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    // Checking for edge cases
    if (totSum - target < 0 || (totSum - target) % 2 != 0)
        return 0;  // Not possible to achieve the target sum

    return findWays_TAB(arr, (totSum - target) / 2);
}
int findWays_OPT(vector<int> &num, int tar) {
    int n = num.size();

    vector<int> prev(tar + 1, 0);

    if (num[0] == 0)
        prev[0] = 2;  // 2 cases - pick and not pick
    else
        prev[0] = 1;  // 1 case - not pick

    if (num[0] != 0 && num[0] <= tar)
        prev[num[0]] = 1;  // 1 case - pick

    for (int ind = 1; ind < n; ind++) {
        vector<int> cur(tar + 1, 0);
        for (int target = 0; target <= tar; target++) {
            int notTaken = prev[target];

            int taken = 0;
            if (num[ind] <= target)
                taken = prev[target - num[ind]];

            cur[target] = (notTaken + taken) % mod;
        }
        prev = cur;
    }
    return prev[tar];
}

// Function to calculate the number of ways to achieve the target sum
int targetSum_OPT(int n, int target, vector<int>& arr) {
    int totSum = 0;
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    // Checking for edge cases
    if (totSum - target < 0 || (totSum - target) % 2 != 0)
        return 0;  // Not possible to achieve the target sum

    return findWays_OPT(arr, (totSum - target) / 2);
}
int main()
{
    vector<int> nums = {1,1,1,1,1};
    int n = nums.size();
    int target = 3;
    cout << targetSum_OPT(n,target,nums);
}