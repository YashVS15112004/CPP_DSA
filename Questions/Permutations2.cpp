#include<bits/stdc++.h>
using namespace std;
void perm(vector<vector<int>> &ans,vector<int> &nums,int idx)
{
    if(idx==nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for(int i=idx;i<nums.size();i++)
    {
        swap(nums[idx],nums[i]);
        perm(ans,nums,idx+1);
        swap(nums[idx],nums[i]);
    }
}
vector<vector<int>> permutation(vector<int> &nums)
{
    vector<vector<int>> ans;
    perm(ans,nums,0);
    return ans;
}
int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = permutation(nums);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}