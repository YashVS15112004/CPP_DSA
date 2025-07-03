#include <bits/stdc++.h>
using namespace std;

// ─── isAllStars Helper ──────────────────────────────────────
bool isAllStars(string &S1, int i)
{
    for (int j = 0; j <= i; j++)
    {
        if (S1[j] != '*')
            return false;
    }
    return true;
}

// ─── Memoization Version ─────────────────────────────────────
bool wildcardMatchingUtil(string &S1, string &S2, int i, int j, vector<vector<bool>> &dp)
{
    if (i < 0 && j < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (j < 0 && i >= 0)
        return isAllStars(S1, i);
    if (dp[i][j] != -1)
        return dp[i][j];

    if (S1[i] == S2[j] || S1[i] == '?')
        return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j - 1, dp);
    else
    {
        if (S1[i] == '*')
            return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j, dp) || wildcardMatchingUtil(S1, S2, i, j - 1, dp);
        else
            return false;
    }
}

bool wildcardMatchingMemo(string &S1, string &S2)
{
    int n = S1.size(), m = S2.size();
    vector<vector<bool>> dp(n, vector<bool>(m, -1));
    return wildcardMatchingUtil(S1, S2, n - 1, m - 1, dp);
}

// ─── Tabulation Version ─────────────────────────────────────
bool isAllStars1(string &S1, int i)
{
    for (int j = 1; j <= i; j++)
    {
        if (S1[j - 1] != '*')
            return false;
    }
    return true;
}

bool wildcardMatchingTab(string &S1, string &S2)
{
    int n = S1.size(), m = S2.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;

    for (int j = 1; j <= m; j++)
        dp[0][j] = false;
    for (int i = 1; i <= n; i++)
        dp[i][0] = isAllStars1(S1, i);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (S1[i - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            else
                dp[i][j] = false;
        }
    }
    return dp[n][m];
}

// ─── Space Optimized Version ────────────────────────────────
bool isAllStars2(string &S1, int i)
{
    for (int j = 1; j <= i; j++)
    {
        if (S1[j - 1] != '*')
            return false;
    }
    return true;
}

bool wildcardMatchingSpace(string &S1, string &S2)
{
    int n = S1.size(), m = S2.size();
    vector<bool> prev(m + 1, false), cur(m + 1, false);
    prev[0] = true;

    for (int i = 1; i <= n; i++)
    {
        cur[0] = isAllStars2(S1, i);
        for (int j = 1; j <= m; j++)
        {
            if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
                cur[j] = prev[j - 1];
            else if (S1[i - 1] == '*')
                cur[j] = prev[j] || cur[j - 1];
            else
                cur[j] = false;
        }
        prev = cur;
    }

    return prev[m];
}

// ─── Main Function ──────────────────────────────────────────
int main()
{
    string S1 = "ab*cd";
    string S2 = "abdefcd";

    cout << "Memoization: ";
    if (wildcardMatchingMemo(S1, S2))
        cout << "String S1 and S2 do match\n";
    else
        cout << "String S1 and S2 do not match\n";

    cout << "Tabulation: ";
    if (wildcardMatchingTab(S1, S2))
        cout << "String S1 and S2 do match\n";
    else
        cout << "String S1 and S2 do not match\n";

    cout << "Space Optimized: ";
    if (wildcardMatchingSpace(S1, S2))
        cout << "String S1 and S2 do match\n";
    else
        cout << "String S1 and S2 do not match\n";

    return 0;
}
