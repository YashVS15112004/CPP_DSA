#include<bits/stdc++.h>
using namespace std;
int countPalindromicSubsequence(string s) 
{
    int n = s.size(),cnt = 0;
    unordered_set<char> ch;
    for(auto it:s) ch.insert(it);
    for(auto it:ch)
    {
        int l=-1,r=0;
        for(int i=0;i<n;i++)
        {
            if(it==s[i])
            {
                if(l==-1) l = i;
                r = i;
            }
            
        }
        {
            unordered_set<char> st;
            for(int idx=l+1;idx<r;idx++)
            st.insert(s[idx]);
            cnt += st.size();
        }
    }
    return cnt;   
}
int main()
{
    string s = "aabca";
    cout<<countPalindromicSubsequence(s);
}