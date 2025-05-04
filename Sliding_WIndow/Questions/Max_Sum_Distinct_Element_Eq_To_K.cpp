#include<bits/stdc++.h>
using namespace std;
long long maximumSubarraySum(vector<int>& nums, int k)
{
    int n=nums.size(),l=0,r=0,cnt=0;
     long long sum = 0LL,ms = 0LL;
     unordered_map<int,int> mp;
     while(r<n)
     {
        if(mp.size()<k && cnt!=k)
        {
            mp[nums[r]]++;
            sum += nums[r];
        } 
        cnt++;
        if(mp.size()<k && cnt==k)
        {
            mp[nums[l]]--;
            sum -= nums[l];
            if(mp[nums[l]]==0) mp.erase(nums[l]);
            l++;
            cnt--;
        }
        if(mp.size()==k && cnt==k)
        {
            ms = max(ms,sum);
            mp[nums[l]]--;
            sum -= nums[l];
            if(mp[nums[l]]==0) mp.erase(nums[l]);
            l++;
            cnt--;
        }
        r++;
     }
     return ms; 
}
int main()
{
    vector<int> nums = {1,5,4,2,9,9,9};
    int k = 3;
    cout<<maximumSubarraySum(nums,k);
}