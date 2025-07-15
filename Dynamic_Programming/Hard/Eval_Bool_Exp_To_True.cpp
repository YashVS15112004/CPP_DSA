#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1000000007;

// ───── Recursive + Memoization ─────
int f(int i, int j, int isTrue, string &exp, vector<vector<vector<ll>>> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue == 1)
            return exp[i] == 'T' ? 1 : 0;
        else
            return exp[i] == 'F' ? 1 : 0;
    }
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    ll ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2)
    {
        ll lT = f(i, ind - 1, 1, exp, dp);
        ll lF = f(i, ind - 1, 0, exp, dp);
        ll rT = f(ind + 1, j, 1, exp, dp);
        ll rF = f(ind + 1, j, 0, exp, dp);

        if (exp[ind] == '&')
        {
            if (isTrue)
                ways = (ways + (lT * rT) % mod) % mod;
            else
                ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
        }
        else if (exp[ind] == '|')
        {
            if (isTrue)
                ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
            else
                ways = (ways + (lF * rF) % mod) % mod;
        }
        else
        {
            if (isTrue)
                ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
            else
                ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
        }
    }
    return dp[i][j][isTrue] = ways;
}

int evaluateExpRecursive(string &exp)
{
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    return f(0, n - 1, 1, exp, dp);
}

// ───── Tabulation ─────
int evaluateExpTabulation(string &exp)
{
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, 0)));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j)
                continue;
            for (int isTrue = 0; isTrue <= 1; isTrue++)
            {
                if (i == j)
                {
                    if (isTrue == 1)
                        dp[i][j][isTrue] = exp[i] == 'T';
                    else
                        dp[i][j][isTrue] = exp[i] == 'F';
                    continue;
                }

                ll ways = 0;
                for (int ind = i + 1; ind <= j - 1; ind += 2)
                {
                    ll lT = dp[i][ind - 1][1];
                    ll lF = dp[i][ind - 1][0];
                    ll rT = dp[ind + 1][j][1];
                    ll rF = dp[ind + 1][j][0];

                    if (exp[ind] == '&')
                    {
                        if (isTrue)
                            ways = (ways + (lT * rT) % mod) % mod;
                        else
                            ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
                    }
                    else if (exp[ind] == '|')
                    {
                        if (isTrue)
                            ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
                        else
                            ways = (ways + (lF * rF) % mod) % mod;
                    }
                    else
                    {
                        if (isTrue)
                            ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
                        else
                            ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
                    }
                }
                dp[i][j][isTrue] = ways;
            }
        }
    }
    return dp[0][n - 1][1];
}

// ───── Main ─────
int main()
{
    string exp = "F|T^F";
    cout << "Total number of ways (Recursive): " << evaluateExpRecursive(exp) << "\n";
    cout << "Total number of ways (Tabulation): " << evaluateExpTabulation(exp) << "\n";
    return 0;
}
