#include<bits/stdc++.h>
using namespace std;
string kth(int n,int k)
{
    int fact = 1;
    vector<int> num;
    for(int i=1;i<n;i++)
    {
        fact*=i;
        num.push_back(i);
    }
    num.push_back(n);
    string ans = "";
    k-=1;
    while(true)
    {
        ans+=to_string(num[k/fact]);
        num.erase(num.begin()+k/fact);
        if(num.empty())
        {
            break;
        }
        k%=fact;
        fact/=num.size();
    }
    return ans;
}
int main()
{
    string ans = kth(4,17);
    cout<<ans;
}