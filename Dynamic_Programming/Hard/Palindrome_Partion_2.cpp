#include <bits/stdc++.h>
using namespace std;

// ───── Utility ─────
bool isPalindrome(int i, int j, string &s)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

// ───── Recursive + Memoization ─────
int minPartitions(int i, int n, string &str, vector<int> &dp)
{
    if (i == n)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int minCost = INT_MAX;
    for (int j = i; j < n; j++)
    {
        if (isPalindrome(i, j, str))
        {
            int cost = 1 + minPartitions(j + 1, n, str, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[i] = minCost;
}

int palindromePartitioningRecursive(string str)
{
    int n = str.size();
    vector<int> dp(n, -1);
    return minPartitions(0, n, str, dp) - 1;
}

// ───── Tabulation ─────
int palindromePartitioningTabulation(string str)
{
    int n = str.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int minCost = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, str))
            {
                int cost = 1 + dp[j + 1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }

    return dp[0] - 1;
}

// ───── Main ─────
int main()
{
    string str = "BABABCBADCEDE";

    cout << "Minimum partitions (Recursive): " << palindromePartitioningRecursive(str) << "\n";
    cout << "Minimum partitions (Tabulation): " << palindromePartitioningTabulation(str) << "\n";

    return 0;
}
