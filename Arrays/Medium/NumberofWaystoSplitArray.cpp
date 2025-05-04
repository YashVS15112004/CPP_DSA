#include<bits/stdc++.h>
using namespace std;
int waysToSplitArray(vector<int>& nums) 
{
    int n = nums.size(),ans = 0;
    long long sum = accumulate(nums.begin(),nums.end(),0LL),temp = 0LL;
    for(int i=0;i<n-1;i++)
    {
        temp += nums[i];
        if(temp>=(sum-temp)) ans++;
    } 
    return ans; 
}
int main()
{
    vector<int> nums = {2,3,1,0};
    cout<<waysToSplitArray(nums);
}