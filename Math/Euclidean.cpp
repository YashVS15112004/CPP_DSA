#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int Euclid(int n,int m)
{
    if(n==0)
    return m;
    else
    {
        if(m>n)
        {
        int temp = n;
        n = m;
        m = temp;
        }
        return Euclid(n%m,m);
    }
}
int main()
{
    int n;
    int m;
    cin>>n>>m;
    cout<<Euclid(n,m);
}