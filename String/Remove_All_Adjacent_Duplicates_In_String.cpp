#include<bits/stdc++.h>
using namespace std;
string removeDuplicates(string s) {
        stack<char> st;
        int n = s.size(),i = 1;
        st.push(s[0]);
        while(i<n)
        {
            if((i<n && !st.empty() && st.top()!=s[i]) || st.empty()) st.push(s[i]);
            else st.pop();
            i++;
        }
        string ans = "";
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
}
int main()
{
    string s = "abbaca";
    cout<<removeDuplicates(s);
}