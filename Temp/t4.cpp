#include<bits/stdc++.h>
using namespace std;
bool cmp(vector<int> &a,vector<int> &b) 
{ 
    return  a[1]< b[1]; 
} 
vector<int> frequencySort(vector<int>& nums)
{
    if(nums.size()<=1) return nums;
    vector<int> ans;
    map<int,int> mp;
    for(auto it:nums) mp[it]++;
    vector<vector<int>> vec;
    for(auto it:mp)
    {
        vector<int> temp;
        temp.push_back(it.first);
        temp.push_back(it.second);
        vec.push_back(temp);
    }
    sort(vec.begin(),vec.end(),cmp);
    for(int i=0;i<vec.size();i++)
    ans.push_back(vec[i][0]);
    nums.clear();
    for(int i=0;i<ans.size();i++)
    {
        int k = mp[ans[i]];
        for(int j=0;j<k;+j++)
        {
            nums.push_back(ans[i]);
        }
    }
    //sort(nums.begin(),nums.end(),greater<int>());
    return nums;
}
int main()
{
    vector<int> nums = {-1,1,-6,4,5,-6,1,4,1};
    vector<int> ans = frequencySort(nums);
    for(auto it:ans) cout<<it<<" ";
}