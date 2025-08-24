#include<bits/stdc++.h>
using namespace std;
int longestSubarray(vector<int>& nums) 
{
    int n = nums.size();
    int i = 0,j = 0;
    int cnt = 0,maxc = 0,delc = 0;
    while(j<n)
    {
        if(nums[j]==1) cnt++;
        else if(delc==0 && nums[j]==0) delc++;
        else if(delc==1 && nums[j]==0) 
        {
            maxc = max(maxc,cnt);
            while(delc>0)
            {
                if(nums[i]==0) delc--;
                else if(nums[i]==1) cnt--;
                i++;
            }
            j--;
        }
        j++;
    }
    maxc = max(maxc,cnt);
    return (maxc==n)?maxc-1:maxc;    
}
int main()
{
    vector<int> nums = {1,1,1};
    cout<<longestSubarray(nums);
}