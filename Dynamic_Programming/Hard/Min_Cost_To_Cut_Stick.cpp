#include <bits/stdc++.h>
using namespace std;

// ───── Tabulation-Based Approach ─────
int minimumCostTabulation(int n, int c, vector<int> cuts)
{
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    for (int i = c; i >= 1; i--)
    {
        for (int j = 1; j <= c; j++)
        {
            if (i > j)
                continue;

            int mini = INT_MAX;
            for (int ind = i; ind <= j; ind++)
            {
                int ans = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];
                mini = min(mini, ans);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][c];
}

// ───── Recursive + Memoization Approach ─────
int findMinimumCost(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;
    for (int ind = i; ind <= j; ind++)
    {
        int ans = cuts[j + 1] - cuts[i - 1] +
                  findMinimumCost(i, ind - 1, cuts, dp) +
                  findMinimumCost(ind + 1, j, cuts, dp);
        mini = min(mini, ans);
    }
    return dp[i][j] = mini;
}

int minimumCostRecursive(int n, int c, vector<int> cuts)
{
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
    return findMinimumCost(1, c, cuts, dp);
}

// ───── Main ─────
int main()
{
    vector<int> cuts = {3, 5, 1, 4};
    int c = cuts.size();
    int n = 7;

    cout << "Minimum cost (Tabulation): " << minimumCostTabulation(n, c, cuts) << endl;
    cout << "Minimum cost (Recursive): " << minimumCostRecursive(n, c, cuts) << endl;

    return 0;
}
