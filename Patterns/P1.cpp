#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 3;
    for(int i=n;i>0;i--)
    {
        int temp1 = n;
        for(int j=0;j<n*i;j++)
        {
            if(j%i==0 && j!=0)
            {
                temp1--;
            }
            cout<<temp1<<"";
        }
        cout<<endl;
    }
}