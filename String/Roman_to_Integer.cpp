#include<bits/stdc++.h>
using namespace std;
int romanToInt(string s) 
{
    map<char,int> mp = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int n = s.size(),ans = 0,i = 0;
    while(i<n)
    {
        if(i<n-1 && mp[s[i]]<mp[s[i+1]]) 
        {
            ans += (mp[s[i+1]]-mp[s[i]]);
            i+=2;
        }
        else 
        {
            ans += mp[s[i]];
            i++;
        }
    }
    return ans;
}
int main()
{
    string s = "LVIII";
    cout<<romanToInt(s);
}