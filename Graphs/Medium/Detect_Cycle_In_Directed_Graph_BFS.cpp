#include<bits/stdc++.h>
using namespace std;
vector<int> topoSort(vector<vector<int>> &adj)
{
        int n = adj.size();
        vector<int> inDegree (n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i]) inDegree[it]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        if(inDegree[i]==0) q.push(i);
        vector<int> topo;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node])
            {
                inDegree[it]--;
                if(inDegree[it]==0) q.push(it);
            }
        }
        return topo;
}
bool isCyclic(vector<vector<int>> &adj)
{
        int n = adj.size();
        vector<int> topo = topoSort(adj);
        return topo.size()<n;
}
int main()
{
    vector<vector<int>> adj = {{1}, {2}, {3}, {3}};
    cout<<isCyclic(adj);
}