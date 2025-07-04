#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,int parent,vector<vector<int>> &adj,vector<int> &vis)
{
    vis[node] = 1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            if(dfs(it,node,adj,vis)) return true;
        }
        else if(it!=parent) return true;
    }
    return false;
}
bool hasCycle(int N,vector<vector<int>> &adj)
{
    vector<int> vis(N,0);
    for(int i=0;i<N;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,-1,adj,vis)) return true;
        }
    }
    return false;
}
int main()
{
    int N = 5;
    vector<vector<int>> adj(5);
    adj[0] = {1,2};
    adj[1] = {0,3};
    adj[2] = {0,3};
    adj[3] = {2,3};
    adj[4] = {3};
    cout<<hasCycle(N,adj);
}