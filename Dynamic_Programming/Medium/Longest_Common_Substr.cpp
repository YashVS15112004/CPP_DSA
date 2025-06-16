#include <bits/stdc++.h>
using namespace std;
// 2‑D DP approach
int lcsDP(const string &s1, const string &s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            } else dp[i][j] = 0;
    return ans;
}
// Space‑optimized approach
int lcsOptimized(const string &s1, const string &s2) {
    int n = s1.size(), m = s2.size();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                cur[j] = 1 + prev[j - 1];
                ans = max(ans, cur[j]);
            } else cur[j] = 0;
        }
        prev.swap(cur);
    }
    return ans;
}
int main() {
    string s1 = "abcjklp", s2 = "acjkp";
    cout << lcsDP(s1, s2) << '\n';
    cout << lcsOptimized(s1, s2) << '\n';
    return 0;
}
