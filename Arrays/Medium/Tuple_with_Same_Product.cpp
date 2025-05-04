#include<bits/stdc++.h>
using namespace std;
int tupleSameProduct(vector<int>& nums) 
{
    int n = nums.size(),prod = 1,ans = 0;
    if(n<=2) return n;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) mp[nums[i]*nums[j]]++;
    for(auto it:mp) cout<<it.first<<" "<<it.second<<endl;
    for(auto it:mp) ans += ((2*it.second)*(2*(it.second-1)));
    return ans;
}
int main()
{
    vector<int> nums = {2,3,4,6,8,12};
    cout<<tupleSameProduct(nums);
}