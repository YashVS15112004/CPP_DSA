#include<bits/stdc++.h>
using namespace std;
void Left_Rotate(vector<int> &nums)
{
    int temp = nums[0]; // storing the first element of array in a variable
    for (int i = 0; i < nums.size() - 1; i++) nums[i] = nums[i + 1];
    nums[nums.size() - 1] = temp;
}
int main()
{
    vector<int> nums = {1,2};
    Left_Rotate(nums);
    for(auto it:nums) cout<<it<<" ";
}