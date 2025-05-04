#include<bits/stdc++.h>
using namespace std;
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
{
    int ans = INT_MAX,city = INT_MIN;
    vector<vector<int>> mat (n,vector<int>(n,1e9));
    for(auto it:edges)
    {
        mat[it[0]][it[1]] = it[2];
        mat[it[1]][it[0]] = it[2];
    }
	for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) 
    mat[i][j] = min(mat[i][j],mat[i][k] + mat[k][j]);
    for(int i=0;i<n;i++)
    {
        int cnt = 0;
        for(int j=0;j<n;j++) if(i!=j && mat[i][j]<=distanceThreshold) cnt++;
        if(cnt<=ans)
        {
            ans = cnt;
            if(i>city) city = i;
        }
    }
    return city;
}
int main()
{
    int n = 4, distanceThreshold = 4;
    vector<vector<int>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    cout<<findTheCity(n,edges,distanceThreshold);
}