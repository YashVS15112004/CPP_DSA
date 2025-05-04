#include<bits/stdc++.h>
using namespace std;
vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) 
{
    int n = nums.size(),ll = 0,hl = 0,m = queries.size();
    vector<vector<int>> interv;
    vector<bool> ans(m,false);
    for(int i=1;i<n;i++)
    {
        if((nums[i-1]%2==0 && nums[i]%2!=0) || (nums[i-1]%2!=0 && nums[i]%2==0))
        hl = i;
        else 
        {
            interv.push_back({ll,hl});
            ll = i;
            hl = i;
        }
    }
    interv.push_back({ll,hl});
    int k = interv.size();
    for(int i=0;i<m;i++)
    {
        int ll = queries[i][0],hl = queries[i][1],low = 0,high = k-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if((interv[mid][0]<=ll && interv[mid][1]>=hl))
            {
                ans[i] = true;
                break;
            }
            else if(interv[mid][0]<=ll) low = mid+1;
            else high = mid-1;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {7,7};
    vector<vector<int>> queries = {{1,1}};
    vector<bool> ans = isArraySpecial(nums,queries);
    for(auto it:ans) cout<<it<<" ";
}