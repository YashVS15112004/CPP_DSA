#include<bits/stdc++.h>
using namespace std;
vector<int> partitionLabels(string s) 
{
    int n = s.size(),cnt = 1;
    vector<int> ans;
    unordered_map<char,int> mp1,mp2;
    for(auto it:s) mp1[it]++;
    mp2[s[0]]++;
    for(int i=1;i<n;i++)
    {
        bool flag = false;
        for(auto it:mp2)
        {
            if(mp1[it.first]>it.second)
            {
                mp2[s[i]]++;
                flag = true;
                break;
            }
        }
        if(flag) cnt++;
        else
        {
            ans.push_back(cnt);
            mp2.clear();
            mp2[s[i]]++;
            cnt = 1;
        }
    }
    ans.push_back(cnt);
    return ans;   
}
int main()
{
    string s = "eccbbbbdec";
    vector<int> ans = partitionLabels(s);
    for(auto it:ans) cout<<it<<" ";
}