#include <bits/stdc++.h>
using namespace std;
int knapsackMemo(int i, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        return (wt[0] <= W) ? val[0] : 0;
    }

    if (dp[i][W] != -1)
        return dp[i][W];

    int notTake = knapsackMemo(i - 1, W, wt, val, dp);
    int take = (wt[i] <= W) ? val[i] + knapsackMemo(i - 1, W - wt[i], wt, val, dp) : 0;

    return dp[i][W] = max(take, notTake);
}
int knapsackTab(int n, int W, vector<int> &wt, vector<int> &val)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    for (int w = wt[0]; w <= W; ++w)
        dp[0][w] = val[0];

    for (int i = 1; i < n; ++i)
    {
        for (int w = 0; w <= W; ++w)
        {
            int notTake = dp[i - 1][w];
            int take = (wt[i] <= w) ? val[i] + dp[i - 1][w - wt[i]] : 0;
            dp[i][w] = max(take, notTake);
        }
    }

    return dp[n - 1][W];
}
int knapsackSpaceOptimized(int n, int W, vector<int> &wt, vector<int> &val)
{
    vector<int> prev(W + 1, 0), curr(W + 1, 0);

    for (int w = wt[0]; w <= W; ++w)
        prev[w] = val[0];

    for (int i = 1; i < n; ++i)
    {
        for (int w = 0; w <= W; ++w)
        {
            int notTake = prev[w];
            int take = (wt[i] <= w) ? val[i] + prev[w - wt[i]] : 0;
            curr[w] = max(take, notTake);
        }
        prev = curr;
    }

    return prev[W];
}
int knapsackON(int n, int W, vector<int> &wt, vector<int> &val) //Most Opt
{
    vector<int> dp(W + 1, 0);

    // Initialize first item
    for (int w = wt[0]; w <= W; ++w)
        dp[w] = val[0];

    for (int i = 1; i < n; ++i)
    {
        for (int w = W; w >= 0; --w)
        { // Reverse loop for correct dependency
            if (wt[i] <= w)
            {
                dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
            }
        }
    }

    return dp[W];
}
int main() {
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int W = 7;
    int n = wt.size();
    cout<<knapsackON(n, W, wt, val) << endl;
    return 0;
}
