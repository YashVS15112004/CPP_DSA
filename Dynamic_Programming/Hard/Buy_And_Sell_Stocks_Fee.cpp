#include <bits/stdc++.h>
using namespace std;

// ───── Memoization Version ─────
int getAnsMemo(vector<int> &Arr, int ind, int buy, int n, int fee, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];

    int profit;
    if (buy == 0)
    {
        profit = max(getAnsMemo(Arr, ind + 1, 0, n, fee, dp),
                     -Arr[ind] + getAnsMemo(Arr, ind + 1, 1, n, fee, dp));
    }
    else
    {
        profit = max(getAnsMemo(Arr, ind + 1, 1, n, fee, dp),
                     Arr[ind] - fee + getAnsMemo(Arr, ind + 1, 0, n, fee, dp));
    }

    return dp[ind][buy] = profit;
}

int maximumProfitMemo(int n, int fee, vector<int> &Arr)
{
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return getAnsMemo(Arr, 0, 0, n, fee, dp);
}

// ───── Tabulation Version ─────
int maximumProfitTabulation(int n, int fee, vector<int> &Arr)
{
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy == 0)
            {
                dp[ind][buy] = max(dp[ind + 1][0], -Arr[ind] + dp[ind + 1][1]);
            }
            else
            {
                dp[ind][buy] = max(dp[ind + 1][1], Arr[ind] - fee + dp[ind + 1][0]);
            }
        }
    }
    return dp[0][0];
}

// ───── Space Optimized Version ─────
int maximumProfitSpaceOptimized(int n, int fee, vector<int> &Arr)
{
    vector<long> ahead(2, 0), cur(2, 0);
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy == 0)
            {
                cur[buy] = max(ahead[0], -Arr[ind] + ahead[1]);
            }
            else
            {
                cur[buy] = max(ahead[1], Arr[ind] - fee + ahead[0]);
            }
        }
        ahead = cur;
    }
    return cur[0];
}

// ───── Main Function ─────
int main()
{
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int n = prices.size();
    int fee = 2;

    cout << "Memoization: The maximum profit is " << maximumProfitMemo(n, fee, prices) << endl;
    cout << "Tabulation: The maximum profit is " << maximumProfitTabulation(n, fee, prices) << endl;
    cout << "Space Optimized: The maximum profit is " << maximumProfitSpaceOptimized(n, fee, prices) << endl;

    return 0;
}
