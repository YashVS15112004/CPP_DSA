#include<bits/stdc++.h>
using namespace std;
int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
{
    int n = grid.size(),m = grid[0].size();
    vector<int> dx = {-1,-1,-1,0,+1,+1,+1,0};
    vector<int> dy = {-1,0,+1,+1,+1,0,-1,-1};
    queue<pair<pair<int,int>,int>> q;
    vector<vector<int>> dis (n,vector<int> (m,INT_MAX));
    if(grid[0][0]!=1)
    {
        q.push({{0,0},1}); 
        dis[0][0] = 1;
    }
    while(!q.empty())
    {
        pair<int,int> p = q.front().first;
        int dist = q.front().second;
        q.pop();
        for(int i=0;i<8;i++)
        {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]==1) continue;
            if(dist+1<dis[nx][ny])
            {
                dis[nx][ny] = dist+1;
                q.push({{nx,ny},dist+1});
            }
        }
    }
    if(dis[n-1][m-1]!=INT_MAX) return dis[n-1][m-1];
    return -1;
}
int main()
{
    vector<vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};
    cout<<shortestPathBinaryMatrix(grid);
}