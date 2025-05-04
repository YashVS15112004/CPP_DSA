#include<bits/stdc++.h>
using namespace std;
int minimumLength(string s) 
{
    unordered_map<char,int> mpp;
    for(auto it:s) mpp[it]++;
    int ans = 0;
    for(auto it:mpp)
    {
        if(it.second%2==1) ans += 1;
        else if(it.second%2==0) ans += 2;
    } 
    return ans;
}
int main()
{
    string s = "aa";
    cout<<minimumLength(s);
}