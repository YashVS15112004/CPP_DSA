#include <bits/stdc++.h>
using namespace std;

// ─── LCS (2‑D DP) ────────────────────────────────────────────────────────────────
int lcs2D(const string &a, const string &b)
{
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp[i][j] = (a[i - 1] == b[j - 1])
                           ? 1 + dp[i - 1][j - 1]
                           : max(dp[i - 1][j], dp[i][j - 1]);
    return dp[n][m];
}

// ─── LCS (1‑D space‑optimized) ───────────────────────────────────────────────────
int lcsOptimized(const string &a, const string &b)
{
    int n = a.size(), m = b.size();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            cur[j] = (a[i - 1] == b[j - 1])
                         ? 1 + prev[j - 1]
                         : max(prev[j], cur[j - 1]);
        prev.swap(cur);
    }
    return prev[m];
}

// ─── Longest Palindromic Subsequence & Min Insertions ────────────────────────────
int longestPalSubseq(const string &s, bool opt)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    return opt ? lcsOptimized(s, rev) : lcs2D(s, rev);
}

int minInsertion(const string &s, bool opt)
{
    return static_cast<int>(s.size()) - longestPalSubseq(s, opt);
}

// ─── Main ────────────────────────────────────────────────────────────────────────
int main()
{
    string s = "abcaa";

    cout << "Using 2D DP    : " << minInsertion(s, false) << '\n';
    cout << "Using 1D DP opt: " << minInsertion(s, true) << '\n';
    return 0;
}
