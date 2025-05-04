#include<bits/stdc++.h>
using namespace std;
int findKthLargest(vector<int>& nums, int k) 
{
    priority_queue<int> mxh;
    for(auto it: nums) mxh.push(it);
    for(int i=0;i<k-1;i++) mxh.pop();
    return mxh.top();
}
int main()
{
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout<<findKthLargest(nums,k);
}