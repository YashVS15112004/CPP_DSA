#include<iostream>
using namespace std;
void func(int i,int n)
{
    if(i>n)
    return;

    func(i+1,n);
    cout<<i<<" ";
    
}
int main()
{
    func(1,20);
}