#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int GCD(int n,int m)
{
    int ans;
    int a;
    if(n>m) {a=m;}
    else {a=n;} 
    for(int i=1;i<=a;i++)
    {
        if(a%i==0)
        {
            ans = i;
        }
    }
    return ans;
}
int main()
{
    int n;
    int m;
    cin>>n>>m;
    cout<<GCD(n,m);
}