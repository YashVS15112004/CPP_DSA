#include<bits/stdc++.h>
using namespace std;
bool areAlmostEqual(string s1, string s2) 
{
    if(s1==s2) return true;
    int n = s1.size();
    unordered_map<char,int> mp1,mp2; //taking s1 as ideal string
    for(int i=0;i<n;i++)
    {
        if(s1[i]!=s2[i])
        {
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
    }
    if(mp1.size()>2 || mp2.size()>2) return false;
    for(auto it:mp1)
    {
        if(mp2[it.first]==1) continue;
        else return false;
    }
    return true; 
}
int main()
{
    string s1 = "qgqeg",s2 = "gqgeq";
    cout<<areAlmostEqual(s1,s2);
}