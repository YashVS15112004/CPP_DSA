#include <bits/stdc++.h>
using namespace std;

// ───── Memoization Version ─────
int getAnsMemo(vector<int> &Arr, int n, int ind, int buy, int cap, vector<vector<vector<int>>> &dp)
{
    if (ind == n || cap == 0)
        return 0;
    if (dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];

    int profit;
    if (buy == 0)
    {
        profit = max(0 + getAnsMemo(Arr, n, ind + 1, 0, cap, dp),
                     -Arr[ind] + getAnsMemo(Arr, n, ind + 1, 1, cap, dp));
    }
    else
    {
        profit = max(0 + getAnsMemo(Arr, n, ind + 1, 1, cap, dp),
                     Arr[ind] + getAnsMemo(Arr, n, ind + 1, 0, cap - 1, dp));
    }

    return dp[ind][buy][cap] = profit;
}

int maximumProfitMemo(vector<int> &prices, int n, int k)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
    return getAnsMemo(prices, n, 0, 0, k, dp);
}

// ───── Tabulation Version ─────
int maximumProfitTab(vector<int> &Arr, int n, int k)
{
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= k; cap++)
            {
                if (buy == 0)
                {
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][0][cap],
                                            -Arr[ind] + dp[ind + 1][1][cap]);
                }
                else
                {
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][1][cap],
                                            Arr[ind] + dp[ind + 1][0][cap - 1]);
                }
            }
        }
    }

    return dp[0][0][k];
}

// ───── Space Optimization Version ─────
int maximumProfitSpace(vector<int> &Arr, int n, int k)
{
    vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
    vector<vector<int>> cur(2, vector<int>(k + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= k; cap++)
            {
                if (buy == 0)
                {
                    cur[buy][cap] = max(0 + ahead[0][cap],
                                        -Arr[ind] + ahead[1][cap]);
                }
                else
                {
                    cur[buy][cap] = max(0 + ahead[1][cap],
                                        Arr[ind] + ahead[0][cap - 1]);
                }
            }
        }
        ahead = cur;
    }

    return ahead[0][k];
}

// ───── Main Function ─────
int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();
    int k = 2;

    cout << "Memoization: The maximum profit that can be generated is " << maximumProfitMemo(prices, n, k) << endl;
    cout << "Tabulation: The maximum profit that can be generated is " << maximumProfitTab(prices, n, k) << endl;
    cout << "Space Optimized: The maximum profit that can be generated is " << maximumProfitSpace(prices, n, k) << endl;

    return 0;
}
