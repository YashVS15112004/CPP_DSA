#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) 
{
    vector<vector<int>> adjList(V);
    for(int i=0;i<edges.size();i++)
    {
        adjList[edges[i].first].push_back(edges[i].second);
        adjList[edges[i].second].push_back(edges[i].first);
    }
    return adjList;
}
int main()
{
    int V = 5, E = 7;
    vector<pair<int,int>> edges = {{0,1},{0,4},{4,1},{4,3},{1,3},{1,2},{3,2}};
    vector<vector<int>> ans = printGraph(V,edges);
    for(auto it:ans) 
    {
        for(auto it1:it) cout<<it1<<" ";
        cout<<endl;
    }
}