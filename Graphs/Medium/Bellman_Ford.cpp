#include<bits/stdc++.h>
using namespace std;
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src)
{
        vector<int> dis(V,1e8);
        dis[src] = 0;
        for(int i=0;i<V;i++)
        {
            for(auto it:edges)
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dis[u]!=1e8 && dis[u]+wt<dis[v]) dis[v] = dis[u]+wt;
            }
        }
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dis[u]!=1e8 && dis[u]+wt<dis[v]) return {-1};
        }
        return dis;
}
int main()
{
    vector<vector<int>> edges = {{0,1,5}, {1,0,3}, {1,2,-1}, {2,0,1}};
    int src = 2;
    vector<int> ans = bellmanFord(3,edges,src);
    for(auto it:ans) cout<<it<<" ";
}