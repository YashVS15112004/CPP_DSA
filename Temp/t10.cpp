#include<bits/stdc++.h>
using namespace std;
int partitionArray(vector<int>& nums, int k) 
{
    int n = nums.size(),ans = 0,i = 0,j = 0;
    sort(nums.begin(),nums.end());
    while(j<n)
    {
        if(nums[j]-nums[i]<=k) j++;
        else 
        {
            ans++;
            i = j;
        }
    } 
    if(i<j && i<n) ans++;
    return ans;
}
int main()
{
    vector<int> nums = {3,1,3,4,2};
    int k = 0;
    cout<<partitionArray(nums,k);
}