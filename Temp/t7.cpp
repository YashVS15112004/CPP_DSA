#include <bits/stdc++.h>
using namespace std;
int minMaxDifference(int num) 
{
    string s = to_string(num),p = s;
    int n = s.size(),j = 0;
    char nm1 = 'X',nm2,rep;
    while(j<n && (p[j]=='1') || (p[j]=='0')) j++; 
    nm2 = p[j];
    rep = (j==0)?'1':'0';
    for(int i=0;i<n;i++)
    {
        if(j<n && p[j]==nm2) p[j] = rep;
        if(nm1=='X' && s[i]!='9')
        {
            nm1 = s[i];
            s[i] = '9';
        }
        else if(s[i]==nm1) s[i] = '9';
        j++;
    }
    int mx = stoi(s);
    int mn = stoi(p);
    cout<<mx<<" "<<mn<<endl;
    return mx-mn;
}
int main()
{
    int num = 1101057;
    cout<<minMaxDifference(num);    
}