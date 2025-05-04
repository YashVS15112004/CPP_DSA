#include<bits/stdc++.h>
using namespace std;
int findContentChildren(vector<int>& g, vector<int>& s) {
       sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans = 0,m = s.size(),i=0,j=0,n = g.size();
        if(m==0) return 0;
        while(j<m && i<n)
        {
            if(g[i]<=s[j])
            {
                ans++;
                i++;
            }
            j++;
        }
        return ans; 
}
int main()
{
    vector<int> g = {1,2,3}, s = {1,1};
    cout<<findContentChildren(g,s);
}