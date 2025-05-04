#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s) {
        int maxl = 1;
        int i = 0;
        int j = i+1;
        int n = s.length();
        if(n<1) return 0;
        unordered_map<char,int> mp;
        int flag = 1;
        while(i<n-1)
        {
            if(flag==1) 
            {
                mp[s[i]] = 1;
                flag = 0;
            }
            else if(mp[s[j]]>0 || j==n)
            {
                int len = j - i;
                if(len==n) return len;
                maxl = max(len,maxl);
                i++;
                flag = 1;
                j = i+1;
                mp.clear();
            }
            else
            {
                mp[s[j]]++;
                j++;
            }
        }
        return maxl;
}
int main()
{
    cout<<lengthOfLongestSubstring("pwwkew");
}