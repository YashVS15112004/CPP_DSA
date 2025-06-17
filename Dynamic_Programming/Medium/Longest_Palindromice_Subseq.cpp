#include <bits/stdc++.h>
using namespace std;
// 2D DP version of LCS
int lcs2D(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }
    return dp[n][m];
}

// Optimized 1D space version of LCS
int lcsOptimized(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                cur[ind2] = 1 + prev[ind2 - 1];
            else
                cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
        }
        prev = cur;
    }
    return prev[m];
}

// Longest Palindromic Subsequence using given LCS function
int longestPalindromeSubsequence(string s, bool optimized)
{
    string t = s;
    reverse(t.begin(), t.end());

    if (optimized)
        return lcsOptimized(s, t);
    else
        return lcs2D(s, t);
}

int main()
{
    string s = "bbabcbcab";

    cout << "Using 2D DP: Length of Longest Palindromic Subsequence is "
         << longestPalindromeSubsequence(s, false) << endl;

    cout << "Using Optimized 1D DP: Length of Longest Palindromic Subsequence is "
         << longestPalindromeSubsequence(s, true) << endl;

    return 0;
}
