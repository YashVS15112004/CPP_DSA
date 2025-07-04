#include <bits/stdc++.h>
using namespace std;

// ─── Memoization Version ─────────────────────────────────────
long getAnsMemo(long *Arr, int ind, int buy, int n, vector<vector<long>> &dp)
{
    if (ind == n)
        return 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];

    long profit = 0;
    if (buy == 0)
        profit = max(0 + getAnsMemo(Arr, ind + 1, 0, n, dp), -Arr[ind] + getAnsMemo(Arr, ind + 1, 1, n, dp));
    if (buy == 1)
        profit = max(0 + getAnsMemo(Arr, ind + 1, 1, n, dp), Arr[ind] + getAnsMemo(Arr, ind + 1, 0, n, dp));

    return dp[ind][buy] = profit;
}

long getMaximumProfitMemo(long *Arr, int n)
{
    vector<vector<long>> dp(n, vector<long>(2, -1));
    if (n == 0)
        return 0;
    return getAnsMemo(Arr, 0, 0, n, dp);
}

// ─── Tabulation Version ─────────────────────────────────────
long getMaximumProfitTab(long *Arr, int n)
{
    vector<vector<long>> dp(n + 1, vector<long>(2, -1));
    dp[n][0] = dp[n][1] = 0;

    long profit;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy == 0)
                profit = max(0 + dp[ind + 1][0], -Arr[ind] + dp[ind + 1][1]);
            if (buy == 1)
                profit = max(0 + dp[ind + 1][1], Arr[ind] + dp[ind + 1][0]);
            dp[ind][buy] = profit;
        }
    }

    return dp[0][0];
}

// ─── Space Optimized Version ─────────────────────────────────
long getMaximumProfitSpace(long *Arr, int n)
{
    vector<long> ahead(2, 0), cur(2, 0);
    ahead[0] = ahead[1] = 0;

    long profit;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy == 0)
                profit = max(0 + ahead[0], -Arr[ind] + ahead[1]);
            if (buy == 1)
                profit = max(0 + ahead[1], Arr[ind] + ahead[0]);
            cur[buy] = profit;
        }
        ahead = cur;
    }

    return cur[0];
}

// ─── Main Function ──────────────────────────────────────────
int main()
{
    int n = 6;
    long Arr[n] = {7, 1, 5, 3, 6, 4};

    cout << "Memoization: The maximum profit is " << getMaximumProfitMemo(Arr, n) << endl;
    cout << "Tabulation: The maximum profit is " << getMaximumProfitTab(Arr, n) << endl;
    cout << "Space Optimized: The maximum profit is " << getMaximumProfitSpace(Arr, n) << endl;

    return 0;
}
