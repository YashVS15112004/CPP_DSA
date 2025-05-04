#include<bits/stdc++.h>
using namespace std;
int solveUtil(int n, vector<int>& height, vector<int>& dp, int k) {
    dp[0] = 0;
    // Loop through the array to fill in the dp array
    for (int i = 1; i < n; i++) {
        int mmSteps = INT_MAX;

        // Loop to try all possible jumps from '1' to 'k'
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int jump = dp[i - j] + abs(height[i] - height[i - j]);
                mmSteps = min(jump, mmSteps);
            }
        }
        dp[i] = mmSteps;
    }
    return dp[n - 1]; // The result is stored in the last element of dp
}
// Function to find the minimum cost to reach the end of the array
int solve(int n, vector<int>& height, int k) {
    vector<int> dp(n, -1); // Initialize a memoization array to store calculated results
    return solveUtil(n, height, dp, k);
}
int solve(int k,int ind, vector<int>& height, vector<int>& dp,int &mn){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    for(int i=1;i<=k;i++)
    {
        if(ind-i>=0)
        {
            int jmp = solve(k,ind-i,height,dp,mn) + abs(height[ind]-height[ind-i]);
            mn = min(mn,jmp);
        }
    }
    dp[ind] = mn;
    mn = INT_MAX;
    return dp[ind];
}
int minmizeCost(int k,vector<int>& height) {
    int n = height.size(),mn = INT_MAX;
    vector<int> dp (n,-1);
    dp[0] = 0;
    return solve(k,n-1,height,dp,mn);
}
int main()
{
    int k = 3;
    vector<int> height = {10, 30, 40, 50, 20};
    cout<<minmizeCost(k,height);
}