#include<bits/stdc++.h>
using namespace std;
bool Valid(int ele,vector<int> &nums,int n,int kc)
{
    for(int i=0;i<n;i++)
    {
        if(nums[i]<=ele)
        {
            kc--;
            i++;
        }
    }
    return kc<=0;
}
int minCapability(vector<int>& nums, int k) 
{
    int n = nums.size(),mx = INT_MIN,ans = INT_MAX;
    mx = *max_element(nums.begin(),nums.end());
    int low = 1,high = mx;
    while(low<high)
    {
        int mid = low+(high-low)/2;
        if(Valid(mid,nums,n,k)) high = mid;
        else low = mid+1;
    }
    return low;
}
int main()
{
    vector<int> nums = {7,3,9,5};
    int k = 2;
    cout<<minCapability(nums,k);
}