#include<bits/stdc++.h>
using namespace std;
int searchInsert(vector<int>& nums, int target)
{
    int low = 0;
    int high = nums.size()-1;
    int idx = 0;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target)
        {
            idx = mid + 1;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return idx;
}
int main()
{
    vector<int> nums = {1,3,5,6,8,9,11};
    int target = 10;
    cout<<searchInsert(nums,target);
}
