#include<bits/stdc++.h>
using namespace std;
int SecondLargest(vector<int> &nums)
{
    int largest = nums[0];
    int slargest = INT_MIN;
    for(int i=1;i<nums.size();i++)
    {
        if(largest<nums[i])
        {
            slargest = largest;
            largest = nums[i];
        }
        else if(nums[i]<largest && slargest<nums[i])
        {
            slargest = nums[i];
        }
    }
    return slargest;
}
int SecondSmallest(vector<int> &nums)
{
    int smallest = nums[0];
    int ssmallest = INT_MAX;
    for(int i=1;i<nums.size();i++)
    {
       if(nums[i]<smallest)
       {
            ssmallest = smallest;
            smallest = nums[i];
       }
       else if(nums[i]>smallest && nums[i]<ssmallest)
       {
            ssmallest = nums[i];
       }
    }
    return ssmallest;
}
int main()
{
    vector<int> nums = {3,1,12,6,-12,3,15,23,23,5,-90};
    cout<<SecondLargest(nums)<<endl;
    cout<<SecondSmallest(nums)<<endl;
}