#include<bits/stdc++.h>
using namespace std;
// Brute-Force
bool check(vector<int>& nums) {
    int idx = 0;
    int flag = 1;
    for(int i=0;i<nums.size()-1;i++)
    {
        if(nums[i]<=nums[i+1]) continue;
        else
        {
            idx= i+1;
            flag = 0;
            break;
        }
    }
    if(flag==1) return true;
    else
    {
        reverse(nums.begin(),nums.begin()+idx);
        reverse(nums.begin()+idx,nums.end());
        reverse(nums.begin(),nums.end());
        flag = 1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<=nums[i+1]) continue;
            else
            {
                return false;
            }
        }
        return true;
    }
}
int main()
{
    vector<int> nums = {3,4,5,1,2};
    cout<<check(nums);
}