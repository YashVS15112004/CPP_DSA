#include<bits/stdc++.h>
using namespace std;
long long countFairPairs(vector<int>& nums, int lower, int upper) 
{
    sort(nums.begin(),nums.end());
    int n = nums.size();
    long long ans = 0;
    for(int i=0;i<n;i++)
    {
        int low=i+1,high=n-1,li=0,ri=0; 
        while(low<=high)
        {
            int mid = low+(high-low)/2,sum = nums[i]+nums[mid];
            if(lower<=sum && sum<=upper)
            {
                low = mid+1;
                ri = mid;
            }
            else if(sum>upper) high = mid-1;
            else if(sum<lower) low = mid+1;
        }
        low=i+1,high=n-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2,sum = nums[i]+nums[mid];
            if(lower<=sum && sum<=upper)
            {
                high = mid-1;
                li = mid;
            }
            else if(sum<lower) low = mid+1;
            else if(sum>upper) high = mid-1;
        }
        ans += (ri!=0 && li!=0)?(ri-li)+1:0;
    }
    return ans;
}
int main()
{
    vector<int> nums = {1,7,9,2,5};
    int lower = 11, upper = 11;
    cout<<countFairPairs(nums,lower,upper);
}