#include<bits/stdc++.h>
using namespace std;
int check(vector<int> &bloomDay,int m,int k,int div)
{
    int n=bloomDay.size();
    int j=1;
    for(int i=0;i<n;i++)
    {
        double temp = (double)bloomDay[i]/(double)div;
        if(m==0) break;
        if(temp<=1.0)
        {
            if(j%k==0) m--;
            j++;
        } 
        else  j=1;
    }
    if(m==0) return 1;
    else return 0;
}
int min_num(vector<int> &bloomDay)
{
    int n = bloomDay.size();
    int min = INT_MAX;
    for(int i=0;i<n;i++) if(bloomDay[i]<min) min = bloomDay[i];
    return min;
}
int max_num(vector<int> &bloomDay)
{
    int n = bloomDay.size();
    int max = INT_MIN;
    for(int i=0;i<n;i++) if(bloomDay[i]>max) max = bloomDay[i];
    return max;
}
int minDays(vector<int>& bloomDay, int m, int k) 
{
    int low = min_num(bloomDay);
    int high = max_num(bloomDay);
    int ans=-1;
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        int chk = check(bloomDay,m,k,mid);
        if(chk)
        {
            high=mid-1;
            ans=mid;
        }
        else low=mid+1;
    }
    return ans;  
}
int main()
{
    vector<int> bloomDay = {88,75,65,90,26,5,72,4,99,48,96,62,75,4,72,83,46,68,6};
    cout<<minDays(bloomDay,6,1);
}