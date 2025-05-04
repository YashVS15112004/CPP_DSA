#include<bits/stdc++.h>
using namespace std;
int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) 
{
    map<string,int> mp;
    int n = matrix.size(),m = matrix[0].size(); 
    for(int i=0;i<n;i++)
    {
        string s = "";
        for(int j=0;j<m-1;j++)
        {
            if(matrix[i][j]==matrix[i][j+1]) s += "*";
            else s += "*|";
        }
        s += "*";
        mp[s]++;
    }
    int ans = 0;
    for(auto it:mp) ans = max(ans,it.second);
    return ans;        
}
int main()
{
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 0}
    };
    cout<<maxEqualRowsAfterFlips(matrix);
}