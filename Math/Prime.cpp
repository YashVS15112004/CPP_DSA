#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool prime(int n)
{
    int count = 1;
    for(int i=1;i<sqrt(n);i++)
    {
        if(n%i==0)
        {
            count++;
            if((n/i)==i)
            {
                count++;
            }
        }
        
    }
    if(count==2)
    {
        return true;
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    cout<<prime(n);
}