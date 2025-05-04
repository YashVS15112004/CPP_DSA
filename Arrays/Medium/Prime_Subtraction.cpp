#include<bits/stdc++.h>
using namespace std;
bool checkPrime(int n)
{
    int cnt = 0;
    for(int i=1;i<=sqrt(n);i++) if(n%i==0) cnt++;
    return (cnt>1)?false:true;
}
bool primeSubOperation(vector<int>& nums) 
{
    int n = nums.size();
    int mx = *max_element(nums.begin(),nums.end());
    vector<int> prime (mx,0);
    for(int i=1;i<mx;i++) if(checkPrime(i+1)) prime[i] = i+1;
    for(auto it:nums) cout<<it<<" ";
    cout<<endl;
    int pe = 0;
    int te = mx-1;
    while(te>=1)
    {
        if(prime[te]!=0 && prime[te]<nums[0]) 
        {
            nums[0] -= prime[te];
            break;
        }
        te--;
    }
    for(int i=1;i<n;i++)
    {
        pe = nums[i-1];
        int te = mx-1;
        while(te>=1)
        {
            if(prime[te]!=0 && prime[te]<nums[i] && (nums[i]-prime[te])>nums[i-1]) 
            {
                nums[i] -= prime[te];
                break;
            }
            te--;
        }
    }
    for(auto it:prime) cout<<it<<" ";
    cout<<endl;
    for(auto it:nums) cout<<it<<" ";
    cout<<endl;
    for(int i=0;i<n-1;i++) if(nums[i]>=nums[i+1]) return false;
    return true;
}
int main()
{
    vector<int> nums = {3,4,10,15,6};
    cout<<primeSubOperation(nums);
}