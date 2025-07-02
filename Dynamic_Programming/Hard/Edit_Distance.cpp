#include <bits/stdc++.h>
using namespace std;

// ─── Memoization Version ─────────────────────────────────────────────
int editDistanceUtil(string &S1, string &S2, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (S1[i] == S2[j])
        return dp[i][j] = 0 + editDistanceUtil(S1, S2, i - 1, j - 1, dp);
    else
        return dp[i][j] = 1 + min(
                                  editDistanceUtil(S1, S2, i - 1, j - 1, dp),
                                  min(editDistanceUtil(S1, S2, i - 1, j, dp),
                                      editDistanceUtil(S1, S2, i, j - 1, dp)));
}

int editDistanceMemo(string &S1, string &S2)
{
    int n = S1.size();
    int m = S2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return editDistanceUtil(S1, S2, n - 1, m - 1, dp);
}

// ─── Tabulation Version ─────────────────────────────────────────────
int editDistanceTab(string &S1, string &S2)
{
    int n = S1.size();
    int m = S2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (S1[i - 1] == S2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
        }
    }
    return dp[n][m];
}

// ─── Space Optimized Version ────────────────────────────────────────
int editDistanceSpace(string &S1, string &S2)
{
    int n = S1.size();
    int m = S2.size();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    for (int j = 0; j <= m; j++)
        prev[j] = j;

    for (int i = 1; i <= n; i++)
    {
        cur[0] = i;
        for (int j = 1; j <= m; j++)
        {
            if (S1[i - 1] == S2[j - 1])
                cur[j] = prev[j - 1];
            else
                cur[j] = 1 + min(prev[j - 1], min(prev[j], cur[j - 1]));
        }
        prev = cur;
    }

    return cur[m];
}

// ─── Main Function ──────────────────────────────────────────────────
int main()
{
    string s1 = "horse";
    string s2 = "ros";

    cout << "Edit Distance (Memoization)   : " << editDistanceMemo(s1, s2) << endl;
    cout << "Edit Distance (Tabulation)    : " << editDistanceTab(s1, s2) << endl;
    cout << "Edit Distance (SpaceOptimized): " << editDistanceSpace(s1, s2) << endl;

    return 0;
}
