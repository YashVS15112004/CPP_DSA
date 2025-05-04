#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) 
{
    int n = edges.size(),src = 0;
    vector<vector<pair<int,int>>> adj (V);
    for(int i=0;i<n;i++)
    adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    vector<int> dist (V,INT_MAX);
    queue<pair<int,int>> q;
    q.push({src,0});
    dist[src] = 0;
    while(!q.empty())
    {
        pair<int,int> Node = q.front();
        q.pop();
        for(auto it:adj[Node.first])
        {
            int ele = it.first;
            int dt = Node.second + it.second;
            if(dt<=dist[ele])
            {
                dist[ele] = dt;
                q.push({ele,dt});
            }
        }
    }
    for(int i=0;i<V;i++) if(dist[i]==INT_MAX) dist[i] = -1;
    return dist;
}
int main()
{
    vector<vector<int>> edges = {{0, 2, 2},  // Row 0
    {1, 3, 4},  // Row 1
    {2, 3, 2},  // Row 2
    {2, 5, 5},  // Row 3
    {3, 4, 2}};
    int V = 6, E = 5;
    vector<int> path = shortestPath(V,E,edges);
    for(auto it:path) cout<<it<<" ";
}