#include<bits/stdc++.h>
using namespace std;
int LargestNum(vector<int> &nums)
{
    int max = INT_MIN;
    for(auto it:nums)
    {
        if(it>=max)
        {
            max = it;
        }
    }
    return max;
}
int main()
{
    vector<int> nums = {3,1,2,6,-12,3,23,5,-90};
    cout<<LargestNum(nums);
}