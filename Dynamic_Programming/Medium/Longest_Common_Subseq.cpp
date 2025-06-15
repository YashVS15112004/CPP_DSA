#include <bits/stdc++.h>
using namespace std;
// Utility function for LCS with memoization
int lcsUtil(const string &s1, const string &s2, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = 1 + lcsUtil(s1, s2, i - 1, j - 1, dp);
    else
        return dp[i][j] = max(lcsUtil(s1, s2, i - 1, j, dp), lcsUtil(s1, s2, i, j - 1, dp));
}
// Wrapper function
int lcs(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return lcsUtil(s1, s2, n - 1, m - 1, dp);
}
int lcsTabular(const string &s1, const string &s2)
{
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp[i][j] = (s1[i - 1] == s2[j - 1]) ? 1 + dp[i - 1][j - 1]
                                                : max(dp[i - 1][j], dp[i][j - 1]);
    return dp[n][m];
}
int lcs_Opt(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    // Initialize two vectors to store the current and previous rows of the DP table
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    // Base case is covered as we have initialized the prev and cur vectors to 0.

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                cur[ind2] = 1 + prev[ind2 - 1]; // Characters match, increment LCS length
            else
                cur[ind2] = max(prev[ind2], cur[ind2 - 1]); // Characters don't match, consider the maximum from above or left
        }
        prev = cur; // Update the previous row with the current row
    }

    return prev[m]; // Return the length of the Longest Common Subsequence
}
int main()
{
    string s1 = "acd", s2 = "ced";
    cout << lcs_Opt(s1, s2) << endl;
    return 0;
}
