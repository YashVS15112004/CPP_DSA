#include<bits/stdc++.h>
using namespace std;
int mem(int n,vector<int> &dp)
{
    if(n<=1) return 1;
    if(dp[n]!=-1) return dp[n];
    dp[n] = mem(n-1,dp) + mem(n-2,dp);
    return dp[n];
}
int climbStairs(int n)
{
    vector<int> dp (n+1,-1);
    dp[0] = 1;
    dp[1] = 1;
    return mem(n,dp);   
}
int tab_climbStairs(int n)
{
    int prev2 = 1,prev = 1,curri = 0;
    for(int i=2; i<=n; i++)
    {
        curri = prev2+ prev;
        prev2 = prev;
        prev= curri;
    }
  return curri;
}
int main()
{
    int n = 5;
    cout<<climbStairs(n)<<" ";
    cout<<tab_climbStairs(n);
}