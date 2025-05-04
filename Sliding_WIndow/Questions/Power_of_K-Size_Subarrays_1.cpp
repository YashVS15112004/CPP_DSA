#include<bits/stdc++.h>
using namespace std;
vector<int> resultsArray(vector<int>& nums, int k) 
{
    vector<int> ans;
    list<int> idx;
    int l=0,r=0,n=nums.size(),cnt=0;
    bool flag = true;
    if(k>n) return {};
    if(k==1) return nums;
    while(r<n)
    {
        if(r>0 && nums[r]-nums[r-1]!=1)
        idx.push_back(r);
        if(cnt==k-1)
        {
            if(!idx.empty() && l<*idx.cbegin()) ans.push_back(-1);
            l++;
            if(!idx.empty() && l==*idx.cbegin()) idx.pop_front();
            else if(idx.empty()) ans.push_back(nums[r]);
            cnt-=1;
        }
        cnt++;
        r++;
    }
    return ans;
}
int main()
{
    vector<int> nums = {2,2,2,2,2};
    int k = 4;
    vector<int> ans = resultsArray(nums,k);
    for(auto it:ans) cout<<it<<" ";
}