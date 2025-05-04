#include<bits/stdc++.h>
using namespace std;
string frequencySort(string s) 
{
    priority_queue<pair<int,char>> maxh;
    map<char,int> mp;
    int n = s.size();
    for(int i=0;i<n;i++) mp[s[i]]++;
    for(auto it:mp) maxh.push({it.second,it.first});
    mp.clear();
    s.clear();
    while(!maxh.empty())
    {
        int m = maxh.top().first;
        char ch = maxh.top().second;
        for(int i=0;i<m;i++) s += ch;
        maxh.pop();
    }
    return s;
}
int main()
{
    string s = "tree";
    cout<<frequencySort(s);
}