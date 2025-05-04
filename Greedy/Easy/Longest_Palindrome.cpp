#include<bits/stdc++.h>
using namespace std;
int longestPalindrome(string s) 
{
    int ans = 0,flag = 0,cnt = 0,maxc = 0;
    map<char,int> mp;
    for(auto it:s) mp[it]++;
    for(auto it:mp) 
    {
        if(it.second%2==0) ans += it.second;
        else if(it.second%2!=0) cnt = max(cnt,it.second);
    }
    for(auto it:mp) if(it.second==cnt) maxc++;
    for(auto it:mp)
    {
        if(it.second!=1 && it.second%2!=0 && it.second!=cnt) ans += (2*(it.second/2));
    }
    return ans+((cnt==1)?1:(cnt+((maxc-1)*(2*(cnt/2))))); 
}
int main()
{
    string s = "aaaAaaaa";
    cout<<longestPalindrome(s);
}