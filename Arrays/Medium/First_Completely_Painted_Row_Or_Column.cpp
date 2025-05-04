#include<bits/stdc++.h>
using namespace std;
int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat)
{
    int m = mat.size(),sz = arr.size(),n = mat[0].size(),k = 0;
    vector<pair<int,int>> idx(m*n,{0,0});
    vector<int> col (n,m);
    vector<int> row (m,n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int index = mat[i][j]-1;
            idx[index] = {i,j};
        }
    }
    for(k=0;k<sz;k++)
    {
        int ele = arr[k]-1,x = idx[ele].first,y = idx[ele].second;
        row[x]--;
        col[y]--;
        if(row[x]==0 || col[y]==0) return k;
    }
    return k-1;
}
int main()
{
    vector<int> arr = {2,8,7,4,1,3,5,6,9};
    vector<vector<int>> mat = {{3,2,5},{1,4,6},{8,7,9}};
    cout<<firstCompleteIndex(arr,mat);
}