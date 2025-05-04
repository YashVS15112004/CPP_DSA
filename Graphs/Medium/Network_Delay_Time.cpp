#include<bits/stdc++.h>
using namespace std;
int networkDelayTime(vector<vector<int>>& times, int n, int k) 
{
    int m = times.size();
    vector<vector<pair<int,int>>> adj (n+1);
    for(int i=0;i<m;i++)
    adj[times[i][0]].push_back({times[i][1],times[i][2]});
    vector<int> dis (n+1,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> mh;
    dis[0] = 0;
    dis[k] = 0;
    mh.push({k,0});
    while(!mh.empty())
    {
        pair<int,int> p = mh.top();
        mh.pop();
        for(auto it:adj[p.first])
        {
            int node = it.first;
            int wt = it.second;
            if(wt+p.second<dis[node])
            {
                dis[node] = wt+p.second;
                mh.push({node,wt+p.second});
            }
        }
    }
    int ans = -1;
    for(auto it:dis)
    {
        if(it==INT_MAX) return -1;
        ans = max(ans,it);
    }
    return ans;
}
int main()
{
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4, k = 2;
    cout<<networkDelayTime(times,n,k);
}