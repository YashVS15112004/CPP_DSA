#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath(vector<vector<int>>& adj, int src) 
{
    int n = adj.size();
    vector<int> dist (n,INT_MAX);
    queue<pair<int,int>> q;
    q.push({src,0});
    dist[src] = 0;
    while(!q.empty())
    {
        pair<int,int> Node = q.front();
        q.pop();
        for(auto it:adj[Node.first])
        {
            int dt = Node.second + 1;
            if(dt<=dist[it]) 
            {
                dist[it] = dt;
                q.push({it,dt});
            }
        }
    }
    for(int i=0;i<n;i++) if(dist[i]==INT_MAX) dist[i] = -1;
    return dist;
}
int main()
{
    vector<vector<int>> graph = {{3},{3},{},{0,1}};
    int src =  3;
    vector<int> path = shortestPath(graph,src);
    for(auto it:path) cout<<it<<" ";
}