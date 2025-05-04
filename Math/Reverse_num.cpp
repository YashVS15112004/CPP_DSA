#include<math.h>
#include <iostream>
using namespace std;
int reverse(int n)
{
    int r;
    int rnum = 0;
    while(n!=0)
    {
        r = n%10;
        n = n/10;
        rnum = (rnum*10)+r;
    }
    return rnum;
}
int main()
{
    int n;
    cin>>n;
    cout<<reverse(n)<<endl;
}