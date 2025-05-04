#include<bits/stdc++.h>
using namespace std;
long long int td(int n,vector<long long int> &dp)
    {
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        const long long int mod = 1e9 + 7;
        dp[n] = (td(n-1,dp) + td(n-2,dp))%mod;
        return dp[n];
    }
    long long int topDown(int n) {
        vector<long long int> dp(n+1,-1);
        dp[0] = 0;
        dp[1] = 1;
        return td(n,dp);
    }
    long long int bottomUp(int n) {
        if(n<=1) return n;
        long long int prev2 = 0,prev1 = 1,curr = 0;
        const long long int mod = 1e9 + 7;
        for(int i=2;i<=n;i++)
        {
            curr = (prev2+prev1)%mod;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
int main()
{
    int n = 69;
    cout<<topDown(n)<<" ";
    cout<<bottomUp(n);
}