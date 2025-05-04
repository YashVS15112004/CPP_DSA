#include<bits/stdc++.h>
using namespace std;
void subs(int i,int n,int sum,bool &flag,vector<int> nums,vector<int> temp)
{
    if(i==n)
    {
        int sm = 0;
        for(auto it:temp) sm += it;
        for(auto it:nums)
        {
            
        }
        for(auto it:temp) cout<<it<<" ";
        cout<<"---->"<<sm<<endl;
        if(sum-sm==0 && temp.size()!=n) flag = true;
        return;
    }
    temp.push_back(nums[i]);
    subs(i+1,n,sum,flag,nums,temp);
    temp.pop_back();
    subs(i+1,n,sum,flag,nums,temp);
}
bool canPartition(vector<int>& nums) {
    int n = nums.size();
    bool flag = false;
    int sum = accumulate(nums.begin(),nums.end(),0);
    cout<<sum<<endl;
    subs(0,n,sum,flag,nums,{}); 
    return flag;  
}
int main()
{
    vector<int> nums = {1,5,11,5};
    cout<<canPartition(nums);
}