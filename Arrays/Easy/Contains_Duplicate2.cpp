#include<bits/stdc++.h>
using namespace std;
bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,pair<int,int>> mp;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]].second==0)mp[nums[i]].first = i;
            mp[nums[i]].second++;
            if(mp[nums[i]].second>1)
            {
                if(abs(mp[nums[i]].first-i)<=k) return true;
                else mp[nums[i]].first = i;
            }
        }
        return false;
}
int main()
{
    vector<int> nums = {1,0,1,1};
    int k = 1;
    cout<<containsNearbyDuplicate(nums,k);
}
