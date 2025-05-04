#include<bits/stdc++.h>
using namespace std;
int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) 
{
    vector<vector<char>> grid (m,vector<char>(n,'F'));
    int ans = 0;
    for(int i=0;i<walls.size();i++) grid[walls[i][0]][walls[i][1]] = 'W';
    for(int i=0;i<guards.size();i++) grid[guards[i][0]][guards[i][1]] = 'G';
    for(int i=0;i<guards.size();i++) 
    {
        // Top
        for(int j=guards[i][0]-1;j>=0;j--)
        {
            if(grid[j][guards[i][1]]=='W' || grid[j][guards[i][1]]=='G') break;
            grid[j][guards[i][1]] = 'T';
        }
    //Bottom
     for(int j=guards[i][0]+1;j<m;j++)
        {
            if(grid[j][guards[i][1]]=='W' || grid[j][guards[i][1]]=='G') break;
            grid[j][guards[i][1]] = 'T';
        }
    //Right
        for(int j=guards[i][1]+1;j<n;j++)
        {
            if(grid[guards[i][0]][j]=='W' || grid[guards[i][0]][j]=='G') break;
            grid[guards[i][0]][j] = 'T';
        }
    //Left
        for(int j=guards[i][1]-1;j>=0;j--)
        {
            if(grid[guards[i][0]][j]=='W' || grid[guards[i][0]][j]=='G') break;
            grid[guards[i][0]][j] = 'T';
        }
    }
    for(auto it:grid) for(auto it1:it) if(it1=='F') ans++;
    return ans; 
}
int main()
{
    int m = 6, n = 10;
    vector<vector<int>> guards = {
        {0, 6}, {2, 2}, {2, 5}, {1, 2}, {4, 9}, {2, 9}, {5, 6}, {4, 6}
    };
    vector<vector<int>> walls = {
        {1, 5}
    };
    cout<<countUnguarded(m,n,guards,walls);
}