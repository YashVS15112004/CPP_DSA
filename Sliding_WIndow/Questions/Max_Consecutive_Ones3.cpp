#include<bits/stdc++.h>
using namespace std;
int longestOnes(vector<int>& nums, int k) 
{
     int l=0,r=0,maxl=0,zero=0,n=nums.size();
        while(r<n){
            if(nums[r]==0) zero++;
            if(zero>k){
            if(nums[l]==0) zero--;
                l++;
            }
            if(zero<=k){
                maxl= max(maxl,r-l+1);
            }
            r++;
        }
    return maxl;
}
int main()
{
    vector<int>  nums = {0,0,0,1};
    int k = 4;
    cout<<longestOnes(nums,k);
}