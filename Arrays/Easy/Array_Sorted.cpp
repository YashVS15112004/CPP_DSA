#include<bits/stdc++.h>
using namespace std;
bool isSorted(vector<int> &nums)
{
    for(int i=0;i<nums.size()-1;i++)
    {
        if(nums[i]<=nums[i+1]) continue;
        else return false;
    }
    return true;
}
int main()
{
    vector<int> nums = {1,2,34,45,64,67,67,78};
    cout<<isSorted(nums);
}