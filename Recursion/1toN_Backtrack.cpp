#include<iostream>
using namespace std;
void func(int i,int n)
{
    if(i<1)
    return;

    func(i-1,n);
    cout<<i<<" ";
}
int main()
{
    func(25,25);
}