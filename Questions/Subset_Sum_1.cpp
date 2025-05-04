#include<bits/stdc++.h>
using namespace std;
void SubSum(vector<int>&arr,int idx,vector<int>&ans,int sum)
{
    if(idx==arr.size())
    {
        ans.push_back(sum);
        return;
    }
    sum += arr[idx];
    SubSum(arr,idx+1,ans,sum);
    sum -= arr[idx];
    SubSum(arr,idx+1,ans,sum);
}
vector<int> SubsetSum(vector<int> &arr,int n)
{
    vector<int> ans;
    SubSum(arr,0,ans,0);
    sort(ans.begin(),ans.end());
    return ans;
}
int main()
{
    vector<int> arr = {2,3};
    vector<int> ans = SubsetSum(arr,2);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return 0;
}