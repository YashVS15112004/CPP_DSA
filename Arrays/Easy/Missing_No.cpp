#include<bits/stdc++.h>
using namespace std;
int missingNumber(vector<int>& nums) {
    int sum = 0;
    int tsum = nums.size();
    for(int i=0;i<nums.size();i++)
    {
        sum += nums[i];
        tsum += i;
    }
    return tsum - sum;
}
int main()
{
    vector<int> nums = {9,6,4,2,3,5,7,0,1};
    cout<<missingNumber(nums);
}
