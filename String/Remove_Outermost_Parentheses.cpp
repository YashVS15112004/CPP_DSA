#include<bits/stdc++.h>
using namespace std;
string removeOuterParentheses(string s) 
{
    stack<char> st;
    int n = s.size();
    string ans = "";
    for(int i=0;i<n;i++)
    {
        if(st.empty()) st.push(s[i]);
        else if(st.size()>=1 && s[i]=='(')
        {
            ans += s[i];
            st.push(s[i]);
        }
        else if(st.size()>1 && s[i]==')' && st.top()=='(')
        {
            ans = ans + s[i];
            st.pop();
        }
        else st.pop();
    } 
    return ans;      
}
int main()
{
    string s = "()()";
    cout<<removeOuterParentheses(s);
}