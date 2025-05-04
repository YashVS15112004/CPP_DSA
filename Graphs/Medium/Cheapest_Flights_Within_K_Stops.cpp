#include<bits/stdc++.h>
using namespace std;
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
{
    int m = flights.size();
    vector<vector<pair<int,int>>> adj (n);
    for(int i=0;i<m;i++) adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> mh;
    vector<int> dis (n,INT_MAX);
    dis[src] = 0;
    mh.push({-1,{src,0}});
    while(!mh.empty())
    {
        int st = mh.top().first;
        pair<int,int> p = mh.top().second;
        mh.pop();
        for(auto it:adj[p.first])
        {
            int node = it.first;
            int d = it.second;
            if(d+p.second<dis[node])
            {
                if(st+1<=k) 
                {
                    dis[node] = d+p.second;
                    mh.push({st+1,{node,d+p.second}});
                }
            }
        }
    }
    return (dis[dst]==INT_MAX)?-1:dis[dst];
}
int main()
{
    int n = 5, src = 0, dst = 4, k = 1;
    vector<vector<int>> flights = 
    {
        {1, 2, 10}, // Row 0
        {2, 0, 7},  // Row 1
        {1, 3, 8},  // Row 2
        {4, 0, 10}, // Row 3
        {3, 4, 2},  // Row 4
        {4, 2, 10}, // Row 5
        {0, 3, 3},  // Row 6
        {3, 1, 6},  // Row 7
        {2, 4, 5} 
    };
    cout<<findCheapestPrice(n,flights,src,dst,k);
}