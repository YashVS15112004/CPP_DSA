#include<bits/stdc++.h>
using namespace std;
int check(vector<int> &nums,int threshold,int mid)
{
    int n = nums.size();
    int temp = 0;
    for(int i=0;i<n;i++)
    {
        int div = ceil((double)nums[i]/(double)mid);
        temp+=div;   
    }
    if(temp<=threshold) return 1;
    else return 0;
}
int max_ele(vector<int> &nums)
{
    int max = INT_MIN;
    for(auto it:nums) if(it>max) max=it;
    return max;
}
int smallestDivisor(vector<int>& nums, int threshold) 
{
        int low=1;
        int high=max_ele(nums);
        int ans;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int chk = check(nums,threshold,mid);
            if(chk)
            {
                high = mid-1;
                ans = mid;
            }
            else low = mid+1; 
        } 
        return ans;       
}
int main()
{
    vector<int> nums = {1,2,3,4,5};
    cout<<smallestDivisor(nums,8);
}