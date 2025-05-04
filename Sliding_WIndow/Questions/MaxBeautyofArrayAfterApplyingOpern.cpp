#include<bits/stdc++.h>
using namespace std;
int maximumBeauty(vector<int>& nums, int k) 
{
    int n = nums.size(),i = 0,j = 1,count = 1,ans = 0;
    sort(nums.begin(),nums.end());
    while(i<n && j<n)
    {
        if(nums[j]-nums[i] <= 2*k)
        {
            count++;
            j++;
        }
        else
        {
            ans = max(ans,count);
            count--;
            i++;
        }
    }
    return max(ans,count);
}
int main()
{
    vector<int> nums = {1,1,1,1};
    int k = 2;
    cout<<maximumBeauty(nums,k);
}