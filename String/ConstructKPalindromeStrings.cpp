#include<bits/stdc++.h>
using namespace std;
 bool canConstruct(string s, int k) 
{
    unordered_map<char,int> mpp;
    if(s.size()<k) return false;
    for(auto it:s) mpp[it]++;
    int c = 0;
    for(auto it:mpp)
    if(it.second%2!=0) c++;
    return (c>k)?false:true;
}
int main()
{
    string s = "leetcode";
    int k = 3;
    cout<<canConstruct(s,k);
}