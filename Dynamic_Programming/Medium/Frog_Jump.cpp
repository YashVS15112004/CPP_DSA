#include<bits/stdc++.h>
using namespace std;
int mem(int n,int idx,vector<int> &dp,vector<int> height)
{
    if(idx==n) return 0;
    if(idx!=0 && dp[idx]!=-1) return dp[idx];
    int lt = mem(n,idx+1,dp,height) + abs(height[idx+1]-height[idx]);
    int rt = INT_MAX;
    if(idx<n-1) rt = mem(n,idx+2,dp,height)+abs(height[idx+2]-height[idx]);
    return dp[idx] = min(lt,rt);
}
int solve(int ind, vector<int>& height, vector<int>& dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int jumpTwo = INT_MAX;
    int jumpOne= solve(ind-1, height,dp)+ abs(height[ind]-height[ind-1]);
    if(ind>1)
        jumpTwo = solve(ind-2, height,dp)+ abs(height[ind]-height[ind-2]);
    
    return dp[ind]=min(jumpOne, jumpTwo);
}
int minCost_Striver(vector<int>& height) {
    int n = height.size();
    vector<int> dp (n,-1);
    return solve(n-1,height,dp);
}
int minCost(vector<int>& height) 
{
    int n = height.size();
    vector<int> dp (n,-1);
    dp[0] = 0;
    dp[n-1] = 0;
    return mem(n-1,0,dp,height);
}
int main()
{
    vector<int> height = {30, 20, 50, 10, 40};
    cout<<minCost_Striver(height);
}