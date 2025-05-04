#include<bits/stdc++.h>
using namespace std;
vector<int> prevSmaller(vector<int> a) 
{
    stack<int> st;
    int n = a.size();
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && a[i]<=st.top()) st.pop();
        if(st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());
        st.push(a[i]);
    }
    return ans;
}
int main()
{
    vector<int> a = {4,5,2,10,8};
    vector<int> ans = prevSmaller(a);
    for(auto it:ans) cout<<it<<" ";
}