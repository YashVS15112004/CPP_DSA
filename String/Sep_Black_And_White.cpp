#include<bits/stdc++.h>
using namespace std;
long long minimumSteps(string s) 
{
    int n = s.size();
    int i = 0;
    int j = 0;
    long long ans = 0;
    while(j<n && i<n)
    {
        if(s[i]=='0') 
        {
            i++;
            j++;
        }
        else if(s[j]=='1') j++;
        else if(i<j && s[i]=='1' && s[j]=='0') 
        {
            swap(s[i],s[j]);
            ans += j-i;
            i++;
            j++;
        }
    }
    return ans>=0?ans:0;
}
int main()
{
    cout<<minimumSteps("01010001");
}