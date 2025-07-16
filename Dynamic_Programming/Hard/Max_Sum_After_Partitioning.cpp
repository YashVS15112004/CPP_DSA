#include <bits/stdc++.h>
using namespace std;

// ───── Recursive + Memoization ─────
int f(int ind, vector<int> &num, int k, vector<int> &dp)
{
    int n = num.size();
    if (ind == n)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];

    int len = 0, maxi = INT_MIN, maxAns = INT_MIN;
    for (int j = ind; j < min(ind + k, n); j++)
    {
        len++;
        maxi = max(maxi, num[j]);
        int sum = len * maxi + f(j + 1, num, k, dp);
        maxAns = max(maxAns, sum);
    }
    return dp[ind] = maxAns;
}

int maxSumAfterPartitioningRecursive(vector<int> &num, int k)
{
    int n = num.size();
    vector<int> dp(n, -1);
    return f(0, num, k, dp);
}

// ───── Tabulation ─────
int maxSumAfterPartitioningTabulation(vector<int> &num, int k)
{
    int n = num.size();
    vector<int> dp(n + 1, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        int len = 0, maxi = INT_MIN, maxAns = INT_MIN;
        for (int j = ind; j < min(ind + k, n); j++)
        {
            len++;
            maxi = max(maxi, num[j]);
            int sum = len * maxi + dp[j + 1];
            maxAns = max(maxAns, sum);
        }
        dp[ind] = maxAns;
    }
    return dp[0];
}

// ───── Main ─────
int main()
{
    vector<int> num = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;

    cout << "The maximum sum (Recursive): " << maxSumAfterPartitioningRecursive(num, k) << "\n";
    cout << "The maximum sum (Tabulation): " << maxSumAfterPartitioningTabulation(num, k) << "\n";

    return 0;
}
