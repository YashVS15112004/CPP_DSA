#include<math.h>
#include <iostream>
using namespace std;
int cube_sum(int n)
{
    int r;
    int ans = 0;
    while(n!=0)
    {
        r = n%10;
        n = n/10;
        ans += pow(r,3);
    }
    return ans;
}
bool armstrong(int n)
{
    int ans = cube_sum(n);
    if(ans == n)
    {
        return true;
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    cout<<armstrong(n)<<endl;
}