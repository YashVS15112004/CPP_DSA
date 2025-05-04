#include<bits/stdc++.h>
using namespace std;
int lessequaltok(vector<int>& nums,int goal){
        if(goal < 0)
        return 0;

        int l = 0;
        int r = 0;
        int ans = 0;
        int n = nums.size();
        int sum = 0;

        while(r < n){
        sum += nums[r];

        while(sum > goal){
            sum -= nums[l];
            l++;
        }
        ans += (r-l+1);
        r++;
        }
        return ans;
        
    }
int numSubarraysWithSum(vector<int>& nums, int goal) {
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]%2==0) nums[i] = 0;
        else nums[i] = 1;
    }
    return lessequaltok(nums,goal)-lessequaltok(nums,goal-1);
}
int main()
{
    vector<int> nums = {1,1,2,1,1};
    int goal = 3;
    cout<<numSubarraysWithSum(nums,goal);
}