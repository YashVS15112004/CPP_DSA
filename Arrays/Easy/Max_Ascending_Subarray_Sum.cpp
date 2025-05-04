#include<bits/stdc++.h>
using namespace std;
int maxAscendingSum(vector<int>& nums) 
{
    int n = nums.size(),maxs = 1,sum = 0;
    if(n==1) return nums[0];
    for(int i=0;i<n-1;i++)
    {
        if(nums[i]<nums[i+1]) sum += nums[i];
        if(i==n-2 && nums[i]<nums[i+1]) sum += nums[i+1]; 
        else if(nums[i]>=nums[i+1])
        {
            sum += nums[i];
            maxs = max(maxs,sum);
            sum = 0;
        }
    }
    maxs = max(maxs,sum);
   return maxs;
}
int main()
{
    vector<int> nums = {10,20,30,40,50};
    cout<<maxAscendingSum(nums);
}