#include<bits/stdc++.h>
using namespace std;
int maxDepth(string s) 
{
    stack<char> st;
    int n = s.size(),ans = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            st.push(s[i]);
            int sze = st.size();
            ans = max(ans,sze);
        }
        else if(!st.empty() && s[i]==')')st.pop();
    }
    return ans;
}
int main()
{
    string s = "(1)+((2))+(((3)))";
    cout<<maxDepth(s);
}