#include<bits/stdc++.h>
using namespace std;
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
{
    int n = prerequisites.size();
    vector<int> topo;
    if(n==0) 
    {
        for(int i=1;i<numCourses;i++) topo.push_back(i);
        topo.push_back(0);
        return topo;
    }
    vector<vector<int>> adj(numCourses);
    for(int i=0;i<n;i++) adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    vector<int> inDegree (numCourses,0);
    queue<int> q;
    for(int i=0;i<n;i++) inDegree[prerequisites[i][0]]++;
    for(int i=0;i<numCourses;i++) if(inDegree[i]==0) q.push(i);
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
    if(topo.size()<numCourses) return {};
    return topo;
}
int main()
{
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    vector<int> topo = findOrder(numCourses,prerequisites);
    for(auto it:topo) cout<<it<<" ";
}