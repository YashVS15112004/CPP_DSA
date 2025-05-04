#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
vector<int> factors(int n)
{
    vector<int> ans;
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i) 
                ans.push_back(i); 
            else
            {
                ans.push_back(i);
                ans.push_back(n/i);
            }
        } 
    }
    sort(ans.begin(),ans.end());
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> ans = factors(n);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
}