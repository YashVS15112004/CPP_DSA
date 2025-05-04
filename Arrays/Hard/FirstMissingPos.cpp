#include<bits/stdc++.h> 
using namespace std;
int firstMissingPositive_Better(vector<int>& nums) 
{
    int n = nums.size();
    unordered_map<int,int> mp;
    int max = *max_element(nums.begin(),nums.end());
    for(int i=0;i<n;i++) mp[nums[i]]++;
    for(int i=1;i<=max;i++) if(mp[i]==0) return i;
    return (max>=1)?max+1:1;
} 
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    int max = *max_element(nums.begin(),nums.end());
    int ans = 1;
    for(int i=1;i<=max;i++)
    {
        if()
    }
}
int main()
{
    vector<int> nums = {3,4,-1,1};
    cout<<firstMissingPositive_Better(nums);
}