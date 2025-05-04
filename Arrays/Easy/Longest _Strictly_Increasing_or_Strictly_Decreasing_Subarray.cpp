#include<bits/stdc++.h>
using namespace std;
int longestMonotonicSubarray(vector<int>& nums) 
{
    int n = nums.size(),ans = 1,cnt1 = 1,cnt2 = 1,j = n-1;
   for(int i=1;i<n;i++)
   {
    if(nums[i]>nums[i-1]) 
    {
        cnt1++;
        ans = max(ans,cnt1);
    }
    if(nums[j-1]>nums[j]) 
    {
        cnt2++;
        ans = max(ans,cnt2);
    }
    if(nums[i]<=nums[i-1]) cnt1 = 1;
    if(nums[j-1]<=nums[j]) cnt2 = 1;
    j--;
   }
   return ans;
}
int main()
{
    vector<int> nums = {1,4,3,3,2};
    cout<<longestMonotonicSubarray(nums);
}