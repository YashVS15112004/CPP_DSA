#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void sum_subseq(int i,int arr[],vector<int>&ds,int n,int target)
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
                exit(0);
            }
        return;
    }
    ds.push_back(arr[i]);
    sum_subseq(i+1,arr,ds,n,target);
    ds.pop_back();
    sum_subseq(i+1,arr,ds,n,target);
}
int main()
{
    int arr[] = {3,1,2};
    vector<int> ds;
    sum_subseq(0,arr,ds,3,3);
}