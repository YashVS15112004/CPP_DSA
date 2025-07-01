#include <bits/stdc++.h>
using namespace std;

const int prime = 1e9 + 7;

// ─── Memoization Version ──────────────────────────────────────────────
int countUtil(string s1, string s2, int ind1, int ind2, vector<vector<int>>& dp) {
    if (ind2 < 0)
        return 1;
    if (ind1 < 0)
        return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    int result = 0;
    if (s1[ind1] == s2[ind2]) {
        int leaveOne = countUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
        int stay = countUtil(s1, s2, ind1 - 1, ind2, dp);
        result = (leaveOne + stay) % prime;
    } else {
        result = countUtil(s1, s2, ind1 - 1, ind2, dp);
    }

    dp[ind1][ind2] = result;
    return result;
}

int subsequenceCountingMemo(string &s1, string &s2, int lt, int ls) {
    vector<vector<int>> dp(lt, vector<int>(ls, -1));
    return countUtil(s1, s2, lt - 1, ls - 1, dp);
}

// ─── Tabulation Version ──────────────────────────────────────────────
int subsequenceCountingTab(string &s1, string &s2, int n, int m) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int i = 1; i <= m; i++) dp[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % prime;
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][m];
}

// ─── Space Optimized Version ─────────────────────────────────────────
int subsequenceCountingSpace(string &s1, string &s2, int n, int m) {
    vector<int> prev(m + 1, 0);
    prev[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            if (s1[i - 1] == s2[j - 1]) {
                prev[j] = (prev[j - 1] + prev[j]) % prime;
            }
        }
    }
    return prev[m];
}

// ─── Main Function ──────────────────────────────────────────────────
int main() {
    string s1 = "babgbag";
    string s2 = "bag";

    cout << "The Count of Distinct Subsequences (Memoization)   : " 
         << subsequenceCountingMemo(s1, s2, s1.size(), s2.size()) << endl;

    cout << "The Count of Distinct Subsequences (Tabulation)    : " 
         << subsequenceCountingTab(s1, s2, s1.size(), s2.size()) << endl;

    cout << "The Count of Distinct Subsequences (SpaceOptimized): " 
         << subsequenceCountingSpace(s1, s2, s1.size(), s2.size()) << endl;

    return 0;
}
