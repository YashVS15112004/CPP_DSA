#include<bits/stdc++.h>
using namespace std;
vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
{
    int n = mat.size(),m = mat[0].size();
    int i = 0,j = 0;
    int mov = 1; // 1 -> up,0 -> down
    vector<int> ans;
    while(i<=n && j<=m)
    {
        if(i==n-1 && j==m-1)
        {
            ans.push_back(mat[i][j]);
            break;
        }
        if(mov==1)
        {
            //Up Mov.
            ans.push_back(mat[i][j]);
            i--;
            j++;
        }
        else
        {
            //Down Mov.
            ans.push_back(mat[i][j]);
            i++;
            j--;
        }
        if(i<0 || j==m)
        {
            mov = 0;
            if(j==m)
            {
                i = i+2;
                j = m-1;
            }
            else if(i<0) i = 0;
        } 
        else if(j<0 || i==n)
        {
            mov = 1;
            if(i==n)
            {
                j = j+2;
                i = n-1;
            }
            else if(j<0) j = 0;
        } 
    }
    return ans;
}
int main()
{
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans = findDiagonalOrder(mat);
    for(auto it:ans) cout<<it<<" ";
}