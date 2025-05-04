#include<bits/stdc++.h>
using namespace std;
bool is_Anagram(string s,string t)
{
    map<char,int> sm;
    map<char,int> tm;
    for(int i=0;i<s.length();i++)
    {
        sm[s[i]] += 1;
    }
    for(int j=0;j<t.length();j++)
    {
        tm[t[j]] += 1;
    }
    for(int i=0;i<s.length();i++)
    {
        if(sm[s[i]]!=tm[s[i]])
        return false;
    }
    return true;
}
int main()
{
    string s,t;
    s = "anagram";
    t = "nagaram";
    cout<<is_Anagram(s,t)<<endl;
}