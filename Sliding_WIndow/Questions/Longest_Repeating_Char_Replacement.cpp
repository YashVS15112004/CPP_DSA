#include<bits/stdc++.h> 
using namespace std;
int characterReplacement(string s, int k) 
{
    int l = 0,r = 0,maxf = 0,maxl = 0;
    int hash[26];
    for(int i=0;i<26;i++) hash[i] = 0;
    while(r<s.size())
    {
        hash[s[r]-'A']++;
        maxf = max(maxf,hash[s[r]-'A']);
        if((r-l+1)-maxf>k)
        {
            hash[s[l]-'A']--;
            maxf=0;
            l++;
        }
        if((r-l+1)-maxf<=k) maxl = max(maxl,r-l+1);
        r++;
    }
    return maxl;
}
int main()
{
    cout<<characterReplacement("AABABBA",1);
}
