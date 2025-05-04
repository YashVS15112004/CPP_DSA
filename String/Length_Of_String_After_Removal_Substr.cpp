#include<bits/stdc++.h>
using namespace std;
int minLength(string s) {
        stack<char> st;
        for(int i=s.size()-1;i>=0;i--) st.push(s[i]);
        if(s.size()<=1) return s.size();
        string str = "";
        while(!st.empty())
        {
            char s1 = st.top(); st.pop();
            str.push_back(s1);
            int n = str.size();
            if(!st.empty() && (str.substr(n-1,1)+st.top()=="AB" || str.substr(n-1,1)+st.top()=="CD"))
            {
                if(!st.empty()) st.pop();
                str.pop_back();
            }
            else if(str.size()>1 && (str.substr(n-2,2)=="AB" ||str.substr(n-2,2)=="CD"))
            {
                str.pop_back();
                str.pop_back();
            }
        }
        return str.size();
}
int main()
{
    string s = "ABFCACDB";
    cout<<minLength(s);
}