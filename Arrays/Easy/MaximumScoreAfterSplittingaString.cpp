#include<bits/stdc++.h>
using namespace std;
int maxScore(string s) 
{
    int oc = 0,zc = 0,n = s.size(),ans = 0,z = 0;
    for(auto it:s) 
    {
        if(it=='1') oc++;
        else if(it=='0') zc++;
    }
    if(zc==0) return oc-1;
    if(oc==0) return zc-1;
    for(auto it:s)
    {
        if(it=='0') z++;
        if(it=='1') oc--;
        if((oc>0) || (z>0 && z<zc))
        {
            int sum = z+oc;
            ans = max(ans,sum);
        }
    }
    return ans;
}
int main()
{
    string s = "110000";
    cout<<maxScore(s);
}