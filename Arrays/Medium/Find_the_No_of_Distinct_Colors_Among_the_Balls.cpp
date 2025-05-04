#include<bits/stdc++.h>
using namespace std;
vector<int> queryResults(int limit, vector<vector<int>>& queries) 
{
    int n = queries.size();
    vector<int> ans;
    unordered_map<int,int> mp;
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++)
    {
        int col = (mp[queries[i][0]]==0)?-1:mp[queries[i][0]];
        mp[queries[i][0]] = queries[i][1];
        mpp[queries[i][1]]++;
        if(col!=-1)mpp[col]--;
        if(col!=-1 && mpp[col]<=0) mpp.erase(col);
        ans.push_back(mpp.size());
    }
    return ans;
}
int main()
{
    int limit = 4;
    vector<vector<int>> queries = {{1,4},{2,5},{1,3},{3,4}};
    vector<int> ans = queryResults(limit,queries);
    for(auto it:ans) cout<<it<<" ";
}