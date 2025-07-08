#include <bits/stdc++.h>
using namespace std;

// ───── Memoization Version ─────
int getAnsMemo(vector<int> &Arr, int ind, int buy, int n, vector<vector<int>> &dp)
{
    if (ind >= n)
        return 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];

    int profit;
    if (buy == 0)
    {
        profit = max(0 + getAnsMemo(Arr, ind + 1, 0, n, dp),
                     -Arr[ind] + getAnsMemo(Arr, ind + 1, 1, n, dp));
    }
    else
    {
        profit = max(0 + getAnsMemo(Arr, ind + 1, 1, n, dp),
                     Arr[ind] + getAnsMemo(Arr, ind + 2, 0, n, dp));
    }

    return dp[ind][buy] = profit;
}

int stockProfitMemo(vector<int> &Arr)
{
    int n = Arr.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return getAnsMemo(Arr, 0, 0, n, dp);
}

// ───── Tabulation Version ─────
int stockProfitTabulation(vector<int> &Arr)
{
    int n = Arr.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit;
            if (buy == 0)
            {
                profit = max(0 + dp[ind + 1][0], -Arr[ind] + dp[ind + 1][1]);
            }
            else
            {
                profit = max(0 + dp[ind + 1][1], Arr[ind] + dp[ind + 2][0]);
            }
            dp[ind][buy] = profit;
        }
    }

    return dp[0][0];
}

// ───── Space Optimized Version ─────
int stockProfitSpaceOptimized(vector<int> &Arr)
{
    int n = Arr.size();
    vector<int> cur(2, 0), front1(2, 0), front2(2, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit;
            if (buy == 0)
            {
                profit = max(0 + front1[0], -Arr[ind] + front1[1]);
            }
            else
            {
                profit = max(0 + front1[1], Arr[ind] + front2[0]);
            }
            cur[buy] = profit;
        }
        front2 = front1;
        front1 = cur;
    }

    return cur[0];
}

// ───── Main Function ─────
int main()
{
    vector<int> prices{4, 9, 0, 4, 10};

    cout << "Memoization: The maximum profit that can be generated is " << stockProfitMemo(prices) << endl;
    cout << "Tabulation: The maximum profit that can be generated is " << stockProfitTabulation(prices) << endl;
    cout << "Space Optimized: The maximum profit that can be generated is " << stockProfitSpaceOptimized(prices) << endl;

    return 0;
}
