#include<bits/stdc++.h>
using namespace std;
bool isPossibleDivide(vector<int>& nums, int k) 
{
    int n = nums.size();
    if(n%k!=0) return 0;
    sort(nums.begin(),nums.end());
    unordered_map<int,int> mp;
    for(auto it:nums) mp[it]++;
    for(int i=0;i<n;i++)
    {
        int num = nums[i];
        if(mp[num]==0) 
        {
            mp.erase(num);
            continue;
        }
        mp[num]--;
        if(mp[num]==0) mp.erase(num);
        for(int j=1;j<k;j++)
        {
            if(mp[num+j]>0) 
            {
                mp[num+j]--;
                if(mp[num+j]==0) mp.erase(num+j);
            }
            else 
            {
                mp[num]++;
                for(int x=1;x<j;x++) mp[num=x]++;
                mp.erase(num+j);
                break;
            }
        }
    }
    return mp.empty();
}
int main()
{
    vector<int> nums = {2,1,2,3,5,2,5,6};
    int k = 2;
    cout<<isPossibleDivide(nums,k);
}