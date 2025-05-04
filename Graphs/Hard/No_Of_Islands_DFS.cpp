#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>> grid,vector<vector<int>> &vis,int x,int y,int n,int m)
{
        vis[x][y] = 1;
        vector<int> dx = {-1,-1,-1,0,+1,+1,+1,0};
        vector<int> dy = {-1,0,+1,+1,+1,0,-1,-1};
        for(int i=0;i<8;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]=='0') continue;
            if(!vis[nx][ny])dfs(grid,vis,nx,ny,n,m);
        }
}
int numIslands(vector<vector<char>>& grid) 
{
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<pair<int,int>> isl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='0') vis[i][j] = 1;
                else isl.push_back({i,j});
            }
        }
        int k = isl.size(),islands = 0;
        for(int i=0;i<k;i++)
        {
            int x = isl[i].first,y = isl[i].second;
            if(!vis[x][y])
            {
                islands++;
                vis[x][y] = 1;
                dfs(grid,vis,x,y,n,m);
            }
        }
        return islands;
}
int main()
{
    vector<vector<char>> grid = 
    {
        {'1', '0', '1', '1', '1'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    cout<<numIslands(grid);
}