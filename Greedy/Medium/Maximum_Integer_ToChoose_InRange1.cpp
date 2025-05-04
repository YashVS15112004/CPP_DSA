#include<bits/stdc++.h>
using namespace std;
int maxCount(vector<int>& banned, int n, int maxSum) 
{
    unordered_map<int,int> mp;
    int sze = banned.size(),sum = 0,count = 0;
    for(int i=0;i<sze;i++)
    if(banned[i]<=n) mp[banned[i]]++;
    for(int i=1;i<=n;i++)
    {
        if(mp[i]>0) continue;
        else
        {
            mp.erase(i);
            if(sum + i <=maxSum)
            {
                sum += i;
                count++;
            }
            else break;
        }
    }
    return count;
}
int main()
{
    vector<int> banned = {11};
    int n = 7, maxSum = 50;
    cout<<maxCount(banned,n,maxSum);
}