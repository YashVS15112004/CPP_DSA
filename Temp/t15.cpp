#include<bits/stdc++.h>
using namespace std;
vector<int> bfsOfGraph(vector<vector<int>> &adj) 
{
        int n = adj.size();
        vector<int> trav;
        vector<int> visited(n,0);
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        while(!q.empty())
        {
            int node = q.front();
            trav.push_back(node);
            q.pop();
            vector<int> temp = adj[node];
            for(auto it:temp)
            {
                if(!visited[it])
                {
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
        return trav;
}
void dfs(int node,vector<int>&visited,vector<vector<int>>&adj,vector<int>&trav)
{
    visited[node] = 1;
    trav.push_back(node);
    for(auto it:adj[node]) if(!visited[it]) dfs(it,visited,adj,trav);
}
vector<int> dfsOfGraph(vector<vector<int>>& adj) {
    int n = adj.size(),node = 0;
    vector<int> visited (n,0);
    vector<int> trav;
    dfs(node,visited,adj,trav);
    return trav;
}
int main()
{
    vector<vector<int>> adj = {{1, 2}, {0, 2}, {0, 1, 3, 4}, {2}, {2}};
    vector<int> trav = bfsOfGraph(adj);
    for(auto it:trav) cout<<it<<" ";
}