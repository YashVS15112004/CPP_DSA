#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void subsequence(int idx,int arr[],vector<int>&ds,int n)
{
    if(idx==n)
    {
        for(auto it:ds)
        {
            cout<<it<<" ";
        }
        if(ds.size()==0)
        {
            cout<<"{}";
        }
        cout<<endl;
        return;
    }
    ds.push_back(arr[idx]);
    subsequence(idx+1,arr,ds,n);
    ds.pop_back();
    subsequence(idx+1,arr,ds,n);
}
int main()
{
    int arr[] = {3,1,2};
    vector<int> ds;
    subsequence(0,arr,ds,3);
}