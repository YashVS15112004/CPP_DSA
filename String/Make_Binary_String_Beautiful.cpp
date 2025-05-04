#include<bits/stdc++.h>
using namespace std;
int minChanges(string s) 
{
    int n = s.size();
    int i = 0,j = 1,ans = 0;
    while(j<n)
    {
        if(s[i]!=s[j]) ans++;
        i+=2;
        j+=2;
    }
    return ans;
}
int main()
{
    string s = "11000111";
    cout<<minChanges(s);
}