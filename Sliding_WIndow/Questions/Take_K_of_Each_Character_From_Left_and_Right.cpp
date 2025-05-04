#include<bits/stdc++.h>
using namespace std;
int takeCharacters(string s, int k) 
{
    int n = s.size(),l = 0,r = 0,ans = n;
    vector<int> freq (3,0);
    for(auto it:s)
    {
        if(it=='a') freq[0]++;
        else if(it=='b') freq[1]++;
        else freq[2]++;
    }
    if(freq[0]<k || freq[1]<k || freq[2]<k) return -1;
    while(r<n)
    {
        freq[s[r]-'a']--;
        while(freq[0]<k ||freq[1]<k || freq[2]<k)
        {
            freq[s[l]-'a']++;
            l++;
        }
        ans = min(ans,n-(r-l+1));
        r++;
    }
    return ans;
}
int main()
{
    string s = "aabaaaacaabc";
    int k = 2;
    cout<<takeCharacters(s,k);
}