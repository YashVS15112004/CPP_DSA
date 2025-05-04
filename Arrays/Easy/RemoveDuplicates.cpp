#include<bits/stdc++.h>
using namespace std;
//Brute Force - Use set to store elements,return set.size() and copy the elements of set to nums.
int Remove_Duplicates(vector<int> &nums)
{
    int j = 1;
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]!=nums[i-1])
        {
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}
int main()
{
    vector<int> nums = {1,1,2,2,2,3,3};
    cout<<Remove_Duplicates(nums)<<endl;
    for(auto it:nums) cout<<it<<" ";
}