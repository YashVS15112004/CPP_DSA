#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool sum_subseq(int i,int arr[],vector<int>&ds,int n,int target)
{
    if(i==n)
    {
            int sum = 0;
            for(auto it:ds)
            {
                sum+=it;
            }
            if(sum == target)
            {
                for(auto it:ds)
                {
                    cout<<it<<" ";
                }
                cout<<endl;
                return true;
            }
        return false;
    }
    ds.push_back(arr[i]);
    if(sum_subseq(i+1,arr,ds,n,target)==true)
    return true;
    ds.pop_back();
    if(sum_subseq(i+1,arr,ds,n,target)==true)
    return true;

    return false;
}
int main()
{
    int arr[] = {3,1,2};
    vector<int> ds;
    sum_subseq(0,arr,ds,3,3);
}