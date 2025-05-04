#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
}
void func(int index, string s, vector<string> &path,vector<vector<string> > &res) {
        if(index == s.size()) {
            res.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); ++i) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                func(i+1, s, path, res);
                path.pop_back();
            }
        }
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> ds;
    func(0,s,ds,ans);
    return ans;
}
int main()
{
    vector<vector<string>> ans = partition("aab");
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
