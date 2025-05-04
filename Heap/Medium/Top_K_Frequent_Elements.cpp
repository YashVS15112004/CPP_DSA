#include<bits/stdc++.h>
using namespace std;
vector<int> topKFrequent(vector<int>& nums, int k) 
{
    unordered_map<int,int> mp;
    vector<int> ans(k,0);
    for(auto it:nums) mp[it]++;
    priority_queue<pair<int,int>> maxh;
    for(auto it:mp) maxh.push({it.second,it.first});
    for(int i=0;i<k;i++)
    {
        ans[i] = maxh.top().second;
        maxh.pop();
    }
    return ans;
}
int main()
{
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> ans = topKFrequent(nums,k);
    for(auto it:ans) cout<<it<<" ";
}