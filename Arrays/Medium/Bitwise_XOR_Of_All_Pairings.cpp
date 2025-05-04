#include<bits/stdc++.h>
using namespace std;
int xorAllNums(vector<int>& nums1, vector<int>& nums2) 
{
    int n = nums1.size(),m = nums2.size(),xr1 = 0,xr2 = 0,ans = 0;
    for(auto it:nums2) xr2^=it;
    for(auto it:nums1) xr1 = (m%2==0)?0:it,ans ^= (xr1^xr2);
    return ans;
}
int main()
{
    vector<int> nums1 = {1,2}, nums2 = {3,4};
    cout<<xorAllNums(nums1,nums2);
}