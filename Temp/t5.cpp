#include <bits/stdc++.h>
using namespace std;
int minMaxDifference(int num) 
{
    string s = to_string(num),p = s;
    int n = s.size();
    char nm1 = 'X',nm2 = p[0];
    for(int i=0;i<n;i++)
    {
        if(p[i]==nm2) p[i] = '0';
        if(nm1=='X' && s[i]!='9')
        {
            nm1 = s[i];
            s[i] = '9';
        }
        else if(s[i]==nm1) s[i] = '9';
    }
    int mx = stoi(s);
    int mn = stoi(p);
    // cout<<s<<" "<<p<<endl;
    // cout<<mx<<" "<<mn<<endl;
    return mx-mn;
}
int main()
{
    int num = 90693669;
    cout<<minMaxDifference(num);    
}