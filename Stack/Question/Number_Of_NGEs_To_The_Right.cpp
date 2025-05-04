#include<bits/stdc++.h>
using namespace std;
vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices)
{
    vector<int> ans (queries,0);
    stack<int> st;
    int cnt = 0;
    for(int j=0;j<queries;j++)
    {
        cnt = 0;
        for(int i=n-1;i>=indices[j];i--) if(arr[i]>arr[indices[j]]) cnt++;
        ans[j] = cnt;
    }
    return ans;
}
int main()
{
    vector<int> arr = {3, 4, 2, 7, 5, 8, 10, 6};
    int queries = 2;
    vector<int> indices = {0, 5};
    vector<int> ans = count_NGE(arr.size(),arr,queries,indices);
    for(auto it:ans) cout<<it<<" ";
}
