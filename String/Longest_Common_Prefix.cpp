#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>& strs) 
{
    string s = strs[0];
    int n = strs.size(),k = s.size();
    for(int i=1;i<n;i++)
    {
        string temp = "";
        int j = 0;
        while(j<k)
        {
            if(j<s.size() && j<strs[i].size() && s[j]==strs[i][j]) 
            {
                temp += s[j];
                j++;
            }
            else if(strs[i].size()<=j || s[j]!=strs[i][j])
            {
                s = temp;
                break;
            }
        }
    }
    return s;  
}
int main()
{
    vector<string> strs = {"flower","flow","flight"};
    cout<<longestCommonPrefix(strs);
}