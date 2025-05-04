#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {4,8,2,10};
    vector<int> ans;
    vector<vector<int>>queries = {{2,3},{1,3},{0,0},{0,3}};
    for(int i=0;i<queries.size();i++)
    {
        int a = queries[i][0];
        int b = queries[i][1];
        int xr = 0;
        for(int j=a;j<=b;j++)
        {
            xr ^= v[j];
        }
        ans.push_back(xr);
    }
    for(auto it:ans) cout<<it<<" ";   
}