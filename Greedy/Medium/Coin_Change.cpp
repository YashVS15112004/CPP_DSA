#include<bits/stdc++.h>
using namespace std;
vector<int> minPartition(int N)
{
    vector<int> ans;
    vector<int> denom = {1,2,5,10,20,50,100,200,500,2000};
    int i = denom.size()-1;
    while(N>0 && i>=0)
    {
        if(N>=denom[i]) 
        {
            N -= denom[i];
            ans.push_back(denom[i]);
        }
        else i--;
    }
    return ans;
}
int main() {
    vector<int> ans =  minPartition(43);
    for(auto it:ans) cout<<it<<" ";
    return 0;
}