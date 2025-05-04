#include<bits/stdc++.h>
using namespace std;
int minSwaps(string s) 
{
    int n = s.size();
    if(n==2)
    {
        if(s[0]=='[' && s[1]==']') return 0;
        else return 1;
    }
    list<int> ob;
    for(int i=n-1;i>=0;i--) if(s[i]=='[') ob.push_back(i);
    int on=0,cn=0;
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i]==']') cn++;
        if(s[i]=='[') on++;
        if(cn>on)
        {
            auto it = ob.begin();
            int idx = *it;
            ob.pop_front();
            swap(s[i],s[idx]);
            cnt++;
            on++;
            cn--;
        }
    }
    return cnt;
}
int main()
{
    string s = "[]";
    cout<<minSwaps(s);
}