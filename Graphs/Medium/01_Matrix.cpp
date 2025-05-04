#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
{
    int n = mat.size(),m = mat[0].size();
    vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
    map<pair<int,int>,int> mp;
    queue<pair<pair<int,int>,int>> q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==0)
            {
                ans[i][j] = 0;
                q.push({{i,j},0});
            }
        }
    }
    vector<int> dx = {-1,0,+1,0};
    vector<int> dy = {0,+1,0,-1};
    while(!q.empty())
    {
        pair<int,int> Node = q.front().first;
        int val = q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = Node.first + dx[i];
            int ny = Node.second + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || mat[nx][ny]==0) continue;
            ans[nx][ny] = min(ans[nx][ny],mat[nx][ny]+val);
            if(mp[{nx,ny}]==0 || mp[{nx,ny}]>ans[nx][ny])
            {
                q.push({{nx,ny},ans[nx][ny]});
                mp[{nx,ny}] = ans[nx][ny];
            }
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> mat = {{0},{0},{0},{0},{0}};
    vector<vector<int>> ans = updateMatrix(mat);
    for(auto it:ans)
    {
        for(auto it1:it) cout<<it1<<" ";
        cout<<endl;
    }
}