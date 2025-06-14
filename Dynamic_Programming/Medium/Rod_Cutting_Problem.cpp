#include <bits/stdc++.h>
using namespace std;

/* -------------------- Memoization -------------------- */
int memoUtil(const vector<int> &wt, const vector<int> &val,
             int idx, int W, vector<vector<int>> &dp)
{
    if (idx == 0)
        return (W / wt[0]) * val[0];
    if (dp[idx][W] != -1)
        return dp[idx][W];

    int notTaken = memoUtil(wt, val, idx - 1, W, dp);
    int taken = INT_MIN;
    if (wt[idx] <= W)
        taken = val[idx] + memoUtil(wt, val, idx, W - wt[idx], dp);

    return dp[idx][W] = max(notTaken, taken);
}

int unboundedKnapsackMemo(int n, int W,
                          const vector<int> &val, const vector<int> &wt)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return memoUtil(wt, val, n - 1, W, dp);
}

/* -------------------- Tabulation -------------------- */
int unboundedKnapsackTab(int n, int W,
                         const vector<int> &val, const vector<int> &wt)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    for (int cap = wt[0]; cap <= W; ++cap)
        dp[0][cap] = (cap / wt[0]) * val[0];

    for (int idx = 1; idx < n; ++idx)
    {
        for (int cap = 0; cap <= W; ++cap)
        {
            int notTaken = dp[idx - 1][cap];
            int taken = INT_MIN;
            if (wt[idx] <= cap)
                taken = val[idx] + dp[idx][cap - wt[idx]];
            dp[idx][cap] = max(notTaken, taken);
        }
    }
    return dp[n - 1][W];
}

/* -------------------- Space‑Optimized -------------------- */
int unboundedKnapsackSpaceOpt(int n, int W,
                              const vector<int> &val, const vector<int> &wt)
{
    vector<int> cur(W + 1, 0);

    for (int cap = wt[0]; cap <= W; ++cap)
        cur[cap] = (cap / wt[0]) * val[0];

    for (int idx = 1; idx < n; ++idx)
    {
        for (int cap = 0; cap <= W; ++cap)
        {
            int notTaken = cur[cap];
            int taken = INT_MIN;
            if (wt[idx] <= cap)
                taken = val[idx] + cur[cap - wt[idx]];
            cur[cap] = max(notTaken, taken);
        }
    }
    return cur[W];
}

/* ------------------------- main ------------------------ */
int main()
{
    vector<int> wt = {2, 4, 6};
    vector<int> val = {5, 11, 13};
    int W = 10;
    int n = wt.size();

    cout << "Memoization : " << unboundedKnapsackMemo(n, W, val, wt) << '\n';
    cout << "Tabulation  : " << unboundedKnapsackTab(n, W, val, wt) << '\n';
    cout << "Space Opt   : " << unboundedKnapsackSpaceOpt(n, W, val, wt) << '\n';

    return 0;
}
