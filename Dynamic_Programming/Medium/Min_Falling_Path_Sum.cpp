#include<bits/stdc++.h>
using namespace std;
int solve_mem(int n,int i,int j,vector<vector<int>> &dp,vector<vector<int>> &matrix)
{
    if(i==0) return matrix[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int ul = 1e9,up = 1e9,ur = 1e9;
    if(i>0 && j>0) ul = solve_mem(n,i-1,j-1,dp,matrix) + matrix[i][j];
    if(i>0) up = solve_mem(n,i-1,j,dp,matrix) + matrix[i][j];
    if(i>0 && j<n) ur = solve_mem(n,i-1,j+1,dp,matrix) + matrix[i][j];
    return dp[i][j] = min({ul,up,ur});
}
int minFallingPathSum_MEM(vector<vector<int>>& matrix) 
{
    int n = matrix.size();
    vector<vector<int>> dp(n,vector<int> (n,-1));
    for(int i=0;i<n;i++) dp[n-1][i] = solve_mem(n-1,n-1,i,dp,matrix);
    int ans = 1e9;
    for(int i=0;i<n;i++) ans = min(ans,dp[n-1][i]);
    return ans;
}
int minFallingPathSum_TAB(vector<vector<int>>& matrix) 
{
    int n = matrix.size();
    vector<vector<int>> dp(n,vector<int> (n,-1));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0) dp[i][j] =  matrix[i][j];
            else
            {
                int ul = 1e9,up = 1e9,ur = 1e9;
                if(i>0 && j>0) ul = dp[i-1][j-1] + matrix[i][j];
                if(i>0) up = dp[i-1][j] + matrix[i][j];
                if(i>0 && j<n-1) ur = dp[i-1][j+1] + matrix[i][j];
                dp[i][j] = min({ul,up,ur});
            }
        }
    }
    int ans = 1e9;
    for(int i=0;i<n;i++) ans = min(ans,dp[n-1][i]); 
    return ans;
}
int minFallingPathSum_OPT(vector<vector<int>>& matrix) 
{
    int n = matrix.size();
    vector<int> prev (n,-1);
    for(int i=0;i<n;i++)
    {
        vector<int> curr(n,-1);
        for(int j=0;j<n;j++)
        {
            if(i==0) curr[j] =  matrix[i][j];
            else
            {
                int ul = 1e9,up = 1e9,ur = 1e9;
                if(i>0 && j>0) ul = prev[j-1] + matrix[i][j];
                if(i>0) up = prev[j] + matrix[i][j];
                if(i>0 && j<n-1) ur = prev[j+1] + matrix[i][j];
                curr[j] = min({ul,up,ur});
            }
        }
        prev = curr;
    }
    int ans = 1e9;
    for(int i=0;i<n;i++) ans = min(ans,prev[i]); 
    return ans;
}
int main()
{
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    cout<<minFallingPathSum_MEM(matrix);
}