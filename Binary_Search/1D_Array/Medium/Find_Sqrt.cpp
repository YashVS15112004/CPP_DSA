#include<bits/stdc++.h>
using namespace std;
int sqrt(int x)
{
    unsigned long long int low=1;
    unsigned long long int high=x;
    unsigned long long int ans = 0;
    unsigned long long int num = x;
        while(low<=high)
    {
        unsigned long long int mid = low+(high-low)/2;
        unsigned long int sqr = mid * mid;
        if(sqr==num) return mid;
        else if(sqr>num) high=mid-1;
        else
        {
            ans = mid;
            low=mid+1;
        }
    }
    return ans;
}
int main()
{
    cout<<sqrt(2147395599);
}