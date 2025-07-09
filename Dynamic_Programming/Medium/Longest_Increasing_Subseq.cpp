#include <bits/stdc++.h>
using namespace std;

// ─── 1. Memoization Approach ───
int getAnsMemo(int arr[], int n, int ind, int prev_index, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;
    if (dp[ind][prev_index + 1] != -1)
        return dp[ind][prev_index + 1];

    int notTake = getAnsMemo(arr, n, ind + 1, prev_index, dp);
    int take = 0;
    if (prev_index == -1 || arr[ind] > arr[prev_index])
    {
        take = 1 + getAnsMemo(arr, n, ind + 1, ind, dp);
    }
    return dp[ind][prev_index + 1] = max(notTake, take);
}

int lisMemoization(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return getAnsMemo(arr, n, 0, -1, dp);
}

// ─── 2. Tabulation Approach ───
int lisTabulation(int arr[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_index = ind - 1; prev_index >= -1; prev_index--)
        {
            int notTake = dp[ind + 1][prev_index + 1];
            int take = 0;
            if (prev_index == -1 || arr[ind] > arr[prev_index])
            {
                take = 1 + dp[ind + 1][ind + 1];
            }
            dp[ind][prev_index + 1] = max(notTake, take);
        }
    }
    return dp[0][0];
}

// ─── 3. Space Optimized Approach ───
int lisSpaceOptimized(int arr[], int n)
{
    vector<int> next(n + 1, 0), cur(n + 1, 0);
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_index = ind - 1; prev_index >= -1; prev_index--)
        {
            int notTake = next[prev_index + 1];
            int take = 0;
            if (prev_index == -1 || arr[ind] > arr[prev_index])
            {
                take = 1 + next[ind + 1];
            }
            cur[prev_index + 1] = max(notTake, take);
        }
        next = cur;
    }
    return cur[0];
}

// ─── 4. 1D DP Approach ───
int lis1Ddp(int arr[], int n)
{
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int prev_index = 0; prev_index < i; prev_index++)
        {
            if (arr[prev_index] < arr[i])
            {
                dp[i] = max(dp[i], 1 + dp[prev_index]);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

// ─── Main Function ───
int main()
{
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Memoization: LIS length = " << lisMemoization(arr, n) << endl;
    cout << "Tabulation: LIS length = " << lisTabulation(arr, n) << endl;
    cout << "Space Optimized: LIS length = " << lisSpaceOptimized(arr, n) << endl;
    cout << "1D DP: LIS length = " << lis1Ddp(arr, n) << endl;

    return 0;
}
