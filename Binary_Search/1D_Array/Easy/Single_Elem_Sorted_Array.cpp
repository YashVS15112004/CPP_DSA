#include<bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int>& nums)
{
    int low=0,high=nums.size()-1;
    bool left=false,right=false;
    int i,j;
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        if(low==high) return nums[mid];
        if(mid<nums.size()-1 && nums[mid+1]==nums[mid]) right=true;
        else if(mid>0 && nums[mid-1]==nums[mid]) left=true;
        else return nums[mid];
        if(left)
        {
            i = mid-2;
            j = mid+1;
            left=false;
        }
        else if(right)
        {
            j = mid+2;
            i = mid-1;
            right=false;
        }
        if(abs(high-j+1)%2==0) //unique present in left.
        {
            high = i;
        }
        else //unique present in right.
        {
            low = j;
        }
    }
    return -1;
}
int main()
{
    vector<int> nums = {1,1,2,5,5};
    cout<<singleNonDuplicate(nums);
}
