#include <bits/stdc++.h>
using namespace std;
int minimumWays(vector<int> coins, int amt, int idx, vector<vector<int>> &dp)
{
    if (idx < 0)
        return 1e9;
    if (idx == 0)
    {
        if (amt % coins[idx] == 0)
            return amt / coins[idx];
        return 1e9;
    }
    if (dp[idx][amt] != -1)
        return dp[idx][amt];
    int notPick = minimumWays(coins, amt, idx - 1, dp);
    int Pick = 1e9;
    if (coins[idx] <= amt)
        Pick = 1 + minimumWays(coins, amt - coins[idx], idx, dp);
    return dp[idx][amt] = min(Pick, notPick);
}
int coinChange_MEM(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    long long ans = minimumWays(coins, amount, n - 1, dp);
    return (ans == 1e9) ? -1 : ans;
}
int coinChange_TAB(vector<int> &arr, int T)
{
    int n = arr.size();
    // Create a 2D DP (Dynamic Programming) table with n rows and T+1 columns
    vector<vector<int>> dp(n, vector<int>(T + 1, 0));
    // Initialize the first row of the DP table
    for (int i = 0; i <= T; i++)
    {
        if (i % arr[0] == 0)
            dp[0][i] = i / arr[0];
        else
            dp[0][i] = 1e9; // Set it to a very large value if not possible
    }
    // Fill the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= T; target++)
        {
            // Calculate the minimum elements needed without taking the current element
            int notTake = dp[ind - 1][target];
            // Calculate the minimum elements needed by taking the current element
            int take = 1e9; // Initialize 'take' to a very large value
            if (arr[ind] <= target)
                take = 1 + dp[ind][target - arr[ind]];
            // Store the minimum of 'notTake' and 'take' in the DP table
            dp[ind][target] = min(notTake, take);
        }
    }
    // The answer is in the bottom-right cell of the DP table
    int ans = dp[n - 1][T];
    // If 'ans' is still very large, it means it's not possible to form the target sum
    if (ans >= 1e9)
        return -1;
    return ans; // Return the minimum number of elements needed
}
int coinChange_OPT(vector<int> &arr, int T)
{
    int n = arr.size();
    // Create two vectors to store the previous and current DP states
    vector<int> prev(T + 1, 0);
    vector<int> cur(T + 1, 0);
    // Initialize the first row of the DP table
    for (int i = 0; i <= T; i++)
    {
        if (i % arr[0] == 0)
            prev[i] = i / arr[0];
        else
            prev[i] = 1e9; // Set it to a very large value if not possible
    }
    // Fill the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= T; target++)
        {
            // Calculate the minimum elements needed without taking the current element
            int notTake = prev[target];
            // Calculate the minimum elements needed by taking the current element
            int take = 1e9; // Initialize 'take' to a very large value
            if (arr[ind] <= target)
                take = 1 + cur[target - arr[ind]];
            // Store the minimum of 'notTake' and 'take' in the current DP state
            cur[target] = min(notTake, take);
        }
        // Update the previous DP state with the current state for the next iteration
        prev = cur;
    }
    // The answer is in the last row of the DP table
    int ans = prev[T];
    // If 'ans' is still very large, it means it's not possible to form the target sum
    if (ans >= 1e9)
        return -1;
    return ans; // Return the minimum number of elements needed
}
int main()
{
    vector<int> coins = {1};
    int amount = 2;
    cout << coinChange_OPT(coins, amount);
}