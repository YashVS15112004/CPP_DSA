#include<bits/stdc++.h>
using namespace std;
int findPlatform(vector<int>& arr, vector<int>& dep) 
{
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int ans = 1,n = arr.size(),i=1,j=0,platform = 0;
    if(n<=1) return n;
    while(i<n && j<n)
    {
        if(arr[i]<=dep[j])
        {
            i++;
            ans++;
        }
        else
        {
            j++;
            ans--;
        }
        platform = max(platform,ans);
    }
    return platform;
}
int main()
{
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800}, dep = {910, 1200, 1120, 1130, 1900, 2000};
    cout<<findPlatform(arr,dep);
}