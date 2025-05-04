#include<bits/stdc++.h>
using namespace std;
long long solve(vector<int>& bt) 
{
    long long wait = 0LL,indvw = 0LL;
        int n = bt.size();
        sort(bt.begin(),bt.end());
        for(int i=1;i<n;i++) 
        {
            indvw += bt[i-1];
            wait += indvw;
        }
        return floor(((double)wait)/n);
}
int main()
{
    int n = 5;
    vector<int> bt = {4,3,7,1,2};
    cout<<solve(bt);
}