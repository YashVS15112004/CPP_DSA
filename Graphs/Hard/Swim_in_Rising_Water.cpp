#include<bits/stdc++.h>
using namespace std;
int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> mh;
        vector<vector<int>> vis (n,vector<int> (m,1e9));
        int ans = 0;
        mh.push({grid[0][0],{0,0}});
        vis[0][0] = 0;
        while(!mh.empty())
        {
            auto it = mh.top();
            mh.pop();
            int diff = it.first;
            int x = it.second.first;
            int y = it.second.second;
            if(x==n-1 && y==m-1) return diff;
            vector<int> dx = { -1, 0, 1, 0};
            vector<int> dy = {0, -1, 0, 1};
            for(int i=0;i<4;i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                int ndf = max(diff,grid[nx][ny]);
                if(ndf<vis[nx][ny])
                {
                    vis[nx][ny] = ndf;
                    mh.push({ndf,{nx,ny}});
                }
            }
        }
        return -1;    
}
int main()
{
    vector<vector<int>> grid = {
        {0,2,},
        {1,3},
    };
    cout<<swimInWater(grid);
}