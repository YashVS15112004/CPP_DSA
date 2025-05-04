#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
        return false;
        unordered_map<char,int> sm;
        for(int i=0;i<s.length();i++) sm[s[i]] += 1;
        for(int j=0;j<t.length();j++)
        {
            sm[t[j]]--;
            if(sm[t[j]]==0) sm.erase(t[j]);
        }
        return sm.empty();
}
int main()
{
    string s = "anagram", t = "nagaram";
    cout<<isAnagram(s,t);
}