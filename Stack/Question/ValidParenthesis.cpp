#include<bits/stdc++.h>
using namespace std;
bool isValid(string s) 
{
    stack<char> st;
    int n = s.length();
    for(int i=0;i<n;i++)
    {
        char c = s[i];
        if(c=='(' || c=='{' || c=='[') st.push(c);
        else if(!st.empty() && ((c==')' && st.top()=='(') || (c=='}' && st.top()=='{') 
        || (c==']' && st.top()=='['))) st.pop();
        else st.push(c);
    }
    if(st.empty()) return true;
    return false;
}
int main()
{
    cout<<isValid("]");
}