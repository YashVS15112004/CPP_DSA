#include <bits/stdc++.h>
using namespace std;

// ─── 2‑D DP version ────────────────────────────────────────────────────────────
int minOps2D(const string &a, const string &b)
{
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp[i][j] = (a[i - 1] == b[j - 1])
                           ? 1 + dp[i - 1][j - 1]
                           : max(dp[i - 1][j], dp[i][j - 1]);
    int k = dp[n][m];
    return (n - k) + (m - k);
}

// ─── 1‑D space‑optimized version ───────────────────────────────────────────────
int minOps1D(const string &a, const string &b)
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
    int k = prev[m];
    return (n - k) + (m - k);
}

// ─── Main ──────────────────────────────────────────────────────────────────────
int main()
{
    string str1 = "abcd", str2 = "anc";
    cout << minOps2D(str1, str2) << '\n';
    cout << minOps1D(str1, str2) << '\n';
    return 0;
}
