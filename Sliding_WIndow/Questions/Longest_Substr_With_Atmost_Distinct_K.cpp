#include<bits/stdc++.h>
using namespace std;
int characterReplacement(string s, int k) {
        int n = s.length(),l = 0, r = 0,maxc = 0;
        map<char, int> mp;
        while(r < n)
        {
            mp[s[r]]++;
            while(mp.size() > k)
            {
                mp[s[l]]--;
                if(mp[s[l]] == 0)
                    mp.erase(s[l]);
                l++;
            }
            if(mp.size() <= k)
                maxc = max(maxc, r - l + 1);
            r++;
        }
        return maxc;
}
int main()
{
    cout<<characterReplacement("aaabbccd",2);
}