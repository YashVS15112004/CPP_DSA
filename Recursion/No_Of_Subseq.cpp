#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int  sum_subseq(int i,int arr[],int sum,int n,int target)
{
    if(i==n)
    {
            if(sum == target)
            {
                return 1;
            }
        return 0;
    }
    sum += arr[i];
    int l = sum_subseq(i+1,arr,sum,n,target);
    sum -= arr[i];
    int r = sum_subseq(i+1,arr,sum,n,target);
    return l + r;
}
int main()
{
    int arr[] = {3,1,2};
    cout<<sum_subseq(0,arr,0,3,3);
}