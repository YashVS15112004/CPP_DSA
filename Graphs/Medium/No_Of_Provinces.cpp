#include<bits/stdc++.h>
using namespace std;
int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size(),count = 0;
    vector<int> vis (n+1,0);
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(!vis[i+1])
        {
            q.push(i);
            vis[i+1] = 1;
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                for(int j=0;j<isConnected[node].size();j++){
                if(isConnected[node][j]==1 && !vis[j+1])
                {
                    q.push(j);
                    vis[j+1] = 1;
                }
            }
        }
        count++;
    }
    }
    return count;    
}
int main()
{
    vector<vector<int>> isConnected = {
        {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
        {0,1,0,1,0,0,0,0,0,0,0,0,0,1,0},
        {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,0,1,0,0,0,1,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,1,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0,0,0,0,0,1,0,0},
        {0,1,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}
    };
    cout<<findCircleNum(isConnected);
}