#include<bits/stdc++.h>
using namespace std;
 int helper(vector<int>& nums, int k) {
        int left = 0, right = 0;
        map<int,int> map;
        int cnt = 0;
        while(right < nums.size()) {
            map[nums[right]]++;
            while(map.size() > k) {
                map[nums[left]]--;
                if(map[nums[left]] == 0)
                    map.erase(nums[left]);

                left++;
            }
            cnt += right - left + 1;
            right++;
        }
        return cnt;
    }
int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
int main()
{
    vector<int> nums = {1,2,1,3,4};
    int k = 3;
    cout<<subarraysWithKDistinct(nums,k);
}