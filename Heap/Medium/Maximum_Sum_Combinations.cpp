#include<bits/stdc++.h>
using namespace std;
bool static cmp(int a,int b)
{
    return a>b;
}
vector<int> MaxSumComb(vector<int> &A, vector<int> &B, int C) 
{
    int n = A.size();
    priority_queue<int> maxhA;
    priority_queue<int> maxhB;
    for(auto it:A) maxhA.push(it);
    for(auto it:B) maxhB.push(it);
    vector<int> temp,ans;
    for(int i=0;i<=ceil(C/2.0);i++)
    {
        for(int j=0;j<ceil(C/2.0);j++)
        {
            ans.push_back(maxhB.top()+maxhA.top());
            temp.push_back(maxhA.top());
            maxhA.pop();
        }
        for(int k=0;k<temp.size();k++) maxhA.push(temp[k]);
        temp.clear();
        maxhB.pop();
    }
    sort(ans.begin(),ans.end(),cmp);
    auto it1 = ans.cbegin()+C;
    auto it2 = ans.cend();
    while(it1!=it2)
    {
        ans.pop_back();
        it2--;
    }
    return ans;
}
int main()
{
    vector<int> A,B;
    A = {58, 38, 60};
    B = {58, 38, 60};
    int C = 2;
    vector<int> ans = MaxSumComb(A,B,C);
    for(auto it:ans) cout<<it<<" ";
}
