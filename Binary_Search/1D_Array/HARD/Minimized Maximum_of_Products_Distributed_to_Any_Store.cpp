#include<bits/stdc++.h>
using namespace std;
bool distribute(vector<int> quantities,int m,int n)
{
    int ms = quantities.size(),q=0;
    for(int i=0;i<ms;i++) q +=ceil((quantities[i]/(m+0.0)));
    return (q<=n)?true:false;
}
int minimizedMaximum(int n, vector<int>& quantities) 
{
    int low = 1,high = *max_element(quantities.begin(),quantities.end()),ans=0;
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        if(distribute(quantities,mid,n))
        {
            high = mid-1;
            ans = mid;
        }
        else
        {
            low = mid+1;
        }
    }
    return ans;
}
int main()
{
    int n = 1;
    vector<int> quantities = {1};
    cout<<minimizedMaximum(n,quantities);
}