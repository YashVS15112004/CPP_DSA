#include<bits/stdc++.h>
using namespace std;
int speed(vector<int> &piles,float m)
{
    int totalH = 0;
    int n = piles.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(piles[i]) / (double)(m));
    }
    return totalH;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
    if(piles.size()==1 && h<=piles[0])//h==1
    {
        double temp = (piles[0]+0.0)/h;
        return ceil(temp);
    }
    int low = 1,high = piles[0];
    for(int i=1;i<n;i++)
    {
        if(piles[i]>high) high = piles[i];
    }
    //unsigned long long int ans = INT_MAX;
    while(low<=high)
    {
        unsigned long long int mid = low+(high-low)/2;
        unsigned long long int cnt = speed(piles,mid+0.0);
        if(cnt<=h) high=mid-1;
        else if(cnt>h) low=mid+1;
    }
    return low;
}
//---------------------------------------------------------------
// S T R I V E R
int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}
int calculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0;
    int n = v.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}
int minimumRateToEatBananas(vector<int> v, int h) {
    int low = 1, high = findMax(v);
    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int totalH = calculateTotalHours(v, mid);
        if (totalH <= h) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}
int main()
{
    vector<int> piles = {3,6,7,11};
    cout<<minEatingSpeed(piles,8);
}