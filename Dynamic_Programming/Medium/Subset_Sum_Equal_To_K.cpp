#include<bits/stdc++.h>
using namespace std;
bool solve(int idx,int target,vector<int> arr,vector<vector<int>> &dp)
{
    if(target==0) return true;
    if(idx==0) return (arr[0]==target);
    if(dp[idx][target]!=-1) return dp[idx][target];
    bool not_take = solve(idx-1,target,arr,dp);
    bool take = false;
    if(target>=arr[idx]) take = solve(idx-1,target-arr[idx],arr,dp);
    return dp[idx][target] = not_take || take;
}
bool subsetSumToK_MEM(int n, int k, vector<int> &arr) 
{
    vector<vector<int>> dp (n,vector<int> (k+1,-1));
    return solve(n-1,k,arr,dp);
}
bool subsetSumToK_TAB(int n,int k,vector<int> &arr)
{
    vector<vector<bool>> dp (n,vector<bool> (k+1,false));
    for(int i=0;i<n;i++) dp[i][0] = true;
    if (arr[0] <= k) dp[0][arr[0]] = true;
    for(int idx=1;idx<n;idx++)
    {
        for(int target=1;target<=k;target++)
        {
            bool not_take = dp[idx-1][target];
            bool take = false;
            if(target>=arr[idx]) take = dp[idx-1][target-arr[idx]];
            dp[idx][target] = not_take || take;
        }
    }
    return dp[n-1][k];
}
bool subsetSumToK_OPT(int n,int k,vector<int> &arr)
{
    vector<bool> prev (k+1,false);
    prev[0] = true;
    if (arr[0] <= k) prev[arr[0]] = true;
    for(int idx=1;idx<n;idx++)
    {
        vector<bool> curr(k+1,false);
        curr[0] = true;
        for(int target=1;target<=k;target++)
        {
            bool not_take = prev[target];
            bool take = false;
            if(target>=arr[idx]) take = prev[target-arr[idx]];
            curr[target] = not_take || take;
        }
        prev = curr;
    }
    return prev[k];
}
int main()
{
    int n = 4,k = 5;
    vector<int> arr = {4,3,2,1};
    cout<<subsetSumToK_OPT(n,k,arr);
}