#include<bits/stdc++.h>
using namespace std;
bool isCycle(vector<vector<int>>& adj) 
{
        int n = adj.size();
        queue<pair<int,int>> q;
        vector<int> vis (n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                q.push({i,i});
                vis[i] = 1;
               while(!q.empty())
                {
                    pair<int,int> Node = q.front();
                    q.pop();
                    int parent = Node.second;
                    int ele = Node.first;
                    for(auto it:adj[ele])
                    {
                        if(vis[it] && it!=parent) return true;
                        if(!vis[it])
                        {
                            q.push({it,ele});
                            vis[it] = 1;
                        }
                    }
                } 
            }
        }
        return false;
}
int main()
{
    vector<vector<int>> adj = {{1},{0,2,4},{1,3},{2,4},{1,3}};
    cout<<isCycle(adj);
}