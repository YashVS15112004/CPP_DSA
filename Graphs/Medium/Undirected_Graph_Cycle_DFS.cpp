#include<bits/stdc++.h>
using namespace std;
void dfs(int Node,int Parent,vector<int> &vis,vector<vector<int>> &adj,bool &flag)
{
    for(auto it:adj[Node])
    {
        if(vis[it] && it!=Parent) flag = true;
        else if(!vis[it])
        {
            vis[it] = 1;
            dfs(it,Node,vis,adj,flag);
        }
    }
}
bool isCycle(vector<vector<int>>& adj) 
{
        int n = adj.size();
        vector<int> vis (n,0);
        bool flag = false;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vis[i] = 1;
                dfs(i,i,vis,adj,flag);
            }
        }
        return flag;
}
int main()
{
    vector<vector<int>> adj = {{1},{0,2,4},{1,3},{2,4},{1,3}};
    cout<<isCycle(adj);
}