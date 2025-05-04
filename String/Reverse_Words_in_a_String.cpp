#include<bits/stdc++.h>
using namespace std;
string reverseWords(string s)
{
    vector<string> str;
    string st = "",ans = "";
    int n = s.size(),i = 0;
    while(i<n)
    {
        if(s[i]!=' ') st += s[i];
        else if(i>0 && s[i]==' ' && s[i-1]!=' ')
        {
            if(!str.empty())str.push_back(" ");
            str.push_back(st);
            st = "";
        }
        i++;
    }
    if(st!="")
    {
        if(!str.empty())str.push_back(" ");
        str.push_back(st);
        st = "";   
    }
    reverse(str.begin(),str.end());
    for(auto it:str) ans += it;
    return ans;
}
int main()
{
    string s = "  hello world  ";
    cout<<reverseWords(s);
}