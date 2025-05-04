#include<bits/stdc++.h> 
using namespace std;
long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = n-1;
        int nb = -1;
        if(i>0) nb = nums[i-1];
        while(nums[i]>=nb && k>0)
        {
            ans += nums[n-1];
            nums[n-1] = ceil(nums[n-1]/3.0);
            k--;
            sort(nums.begin(),nums.end());
            nb = -1;
            if(i>0) nb = nums[i-1];
        }
    return ans;
}
int main()
{
    vector<int> nums = {672579538,806947365,854095676,815137524};
    int k = 3;
    cout<<maxKelements(nums,k);
}