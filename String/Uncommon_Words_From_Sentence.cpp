#include<bits/stdc++.h>
using namespace std;
vector<string> uncommonFromSentences(string s1, string s2) {
    unordered_map<string,int> mp;
    int n1 = s1.size();
    int n2 = s2.size();
    int i=0,j=0;
    vector<string> ans;
    string t1 = "";
    string t2 = "";
    while(i<=n1 || j<=n2)
    {
        if((i<n1 && s1[i]==' ') || i==n1) 
        {
            mp[t1]++;
            t1 = "";
        }
        if((j<n2 && s2[j]==' ') || j==n2) 
        {
            mp[t2]++;
            t2 = "";
        }
        if(i<n1 && s1[i]!=' ') t1+=s1[i];
        if(j<n2 && s2[j]!=' ') t2+=s2[j];
        if(i<=n1) i++;
        if(j<=n2) j++;
    }
    for(auto it:mp) if(it.second==1) ans.push_back(it.first);
    return ans;
}
int main()
{
    string s1 = "apple apple";
    string s2 = "banana";
    vector<string> ans = uncommonFromSentences(s1,s2);
    for(auto it:ans) cout<<it<<" ";
}