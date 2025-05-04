#include<math.h>
#include <iostream>
using namespace std;
bool palindrome(int n)
{
    bool ans = false;
    int m = n;
    int r;
    int rnum = 0;
    while(n!=0)
    {
        r = n%10;
        n = n/10;
        rnum = (rnum*10)+r;
    }
    if(rnum==m)
    {ans = true;}
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<palindrome(n)<<endl;
}