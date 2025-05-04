#include<bits/stdc++.h>
using namespace std;
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
{
    int n = prerequisites.size();
    vector<vector<int>> adj(numCourses);
    for(int i=0;i<n;i++) adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    vector<int> inDegree (numCourses,0);
    vector<int> topo;
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
    return topo.size()==numCourses;   
}
int main()
{
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}};
    cout<<canFinish(numCourses,prerequisites);
}