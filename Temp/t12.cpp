#include <bits/stdc++.h>
using namespace std;
vector<string> divideString(string s, int k, char fill)
{
    int pad = s.size() % k;
    if (pad)
        s.append(k - pad, fill);
    vector<string> ans;
    ans.reserve(s.size() / k);
    for (size_t i = 0; i < s.size(); i += k)
        ans.emplace_back(s.substr(i, k));
    return ans;
}
int main()
{
    string s = "abcdefghij";
    int k = 3;
    char fill = 'x';
    vector<string> ans = divideString(s,k,fill);
    for(auto it:ans) cout<<it<<" ";
}