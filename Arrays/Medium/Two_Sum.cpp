#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum_better(vector<int> &nums, int target) {
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size();i++)
        {
            int req = target - nums[i];
            if(mp.find(req)!=mp.end())
            {
                return {mp[req], i};
            }
            mp[nums[i]] = i;
        }
    return {-1,-1};
}
vector<int> twoSum_opt(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return {left,right};
        }
        else if (sum < target) left++;
        else right--;
    }
    return {-1,-1};
}
int main()
{
    vector<int> nums = {3,3};
    vector<int> ans = twoSum_better(nums,6);
    for(auto it:ans) cout<<it<<" ";
}