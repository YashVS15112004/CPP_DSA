#include<bits/stdc++.h>
using namespace std;
int findLengthOfShortestSubarray(vector<int>& arr) 
{
    int n=arr.size();
        int r=n-1;
        int res=0;
        while(r>0 && arr[r-1]<=arr[r])r--;
        res=r;

        int l=0;
        while(l<r){
            while(r<n && arr[l]>arr[r]){
                r++;
            }
            res=min(res,r-l-1);
            if(arr[l]>arr[l+1])break;
            l++;
        }
        return res;     
}
int main()
{
    vector<int> arr = {2,2,2,1,1,1};
    cout<<findLengthOfShortestSubarray(arr);
}