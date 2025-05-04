#include<bits/stdc++.h>
using namespace std;
bool rotateString(string s, string goal) 
{
    if(s.size()!=goal.size()) return false;
    string t1 = s + s;
    int n = t1.size();
    int m = goal.size();
    for(int i=0;i<n;i++)
    {
        int j = i;
        int k = 0;
        while(k<m && t1[j]==goal[k])
        {
            j++;
            k++;
        }
        if(k==m) return true;
    }
    return false;
}
int main()
{
    string s = "abcde", goal = "abced";
    cout<<rotateString(s,goal);
}