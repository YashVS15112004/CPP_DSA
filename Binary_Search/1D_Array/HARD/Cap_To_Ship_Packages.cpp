#include<bits/stdc++.h>
using namespace std;
int check(vector<int> &weights,int days,int m)
{
    int n = weights.size();
    int day_cal=0;
    long long int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=weights[i];
        if(sum==m)
        {
            day_cal++;
            sum=0;
        }
        else if(sum>m)
        {
            day_cal++;
            sum=weights[i];
        }
    }
    if(sum<m && sum!=0) day_cal++;
    if(day_cal<=days) return 1;
    else return 0;
}
int sum(vector<int> &weights)
{
    long long int sum=0;
    for(auto it:weights) sum+=it;
    return sum;
}
int max_ele(vector<int> &weights)
{
    long long int max = INT_MIN;
    for(auto it:weights) if(it>max) max=it;
    return max;
}
int shipWithinDays(vector<int>& weights, int days) 
{
    long long int low = max_ele(weights);
    long long int high = sum(weights);
    long long int ans = high;
    while(low<=high)
    {
        long long int mid = low+(high-low)/2;
        int chk = check(weights,days,mid);
        if(chk)
        {
            high = mid-1;
            ans = min(mid,ans);
        }
        else low = mid+1;
    }
    return ans;        
}
int main()
{
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    cout<<shipWithinDays(weights,5);
}