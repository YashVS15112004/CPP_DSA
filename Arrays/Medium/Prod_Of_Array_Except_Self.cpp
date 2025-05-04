#include<bits/stdc++.h>
using namespace std;
 vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,1);
        
        int cur=1;
        for(int i=0;i<n;i++){
            ans[i]*=cur;
            cur*=nums[i];
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        cur=1;
        for(int i=n-1;i>=0;i--){
            ans[i]*=cur;
            cur*=nums[i];
        }
        return ans;
}      
int main()
{
    vector<int> nums = {1,2,3,4};
    vector<int> ans = productExceptSelf(nums);
    for(auto it:ans) cout<<it<<" ";
}
