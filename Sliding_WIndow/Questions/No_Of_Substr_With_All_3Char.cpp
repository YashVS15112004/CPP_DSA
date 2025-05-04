#include<bits/stdc++.h>
using namespace std;
int atleastk(string s)
{
    int l=0,r=0,maxl=0,n=s.size();
    vector<int> freq(3,0);
    while(r<n)
    {
        freq[s[r]-'a']++;
        bool flag = true;
        for(auto it:freq) 
        {
            if(it==0) 
            {
                flag = false;
                break;
            }
        }
        if(flag==true)
        {
            while(flag)
            {
                freq[s[l]-'a']--;
                l++;
                for(auto it:freq) 
                {
                    if(it==0) 
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(flag==false) maxl += r-l+1;
        r++;
    }
    return maxl;
}
int numberOfSubstrings(string s) 
{
    int cnt1 = 0,n=s.size();
    for(int i=1;i<=n;i++) cnt1+=i;
    int cnt2 = atleastk(s);
    return cnt1-cnt2;
}
int main()
{
    cout<<numberOfSubstrings("abcabc");
}