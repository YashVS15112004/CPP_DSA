#include<bits/stdc++.h>
using namespace std;
vector<int> eventualSafeNodes(vector<vector<int>>& graph)
{
    int n = graph.size();
    vector<vector<int>> adj(n);
    vector<int> outDegree (n,0);
    vector<int> safeStates (n,0);
    queue<int> q;
    vector<int> topo;
    for(int i=0;i<n;i++) for(auto it:graph[i]) adj[it].push_back(i);
    for(int i=0;i<n;i++) for(auto it:adj[i]) outDegree[it]++;
    for(int i=0;i<n;i++) if(outDegree[i]==0) q.push(i);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        safeStates[node] = 1;
        for(auto it:adj[node]) 
        {
            outDegree[it]--;
            if(outDegree[it]==0) q.push(it);
        }
    }
    for(int i=0;i<n;i++)
    if(safeStates[i]==1) topo.push_back(i);
    return topo;
}
int main()
{
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> states = eventualSafeNodes(graph);
    for(auto it:states) cout<<it<<" ";
}