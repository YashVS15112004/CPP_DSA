#include <bits/stdc++.h>
using namespace std;
string lcsTabular(const string &s1, const string &s2)
{
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp[i][j] = (s1[i - 1] == s2[j - 1]) ? 1 + dp[i - 1][j - 1]: max(dp[i - 1][j], dp[i][j - 1]);
    int len = dp[n][m],i = n,j = m,idx = len-1;
    string s = "";
    for(int i=0;i<len;i++) s += "$";
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            s[idx] = s1[i-1];
            idx--;
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    return s;
}
int main()
{
    string s1 = "abcde", s2 = "bdgek";
    cout<<lcsTabular(s1,s2);
}