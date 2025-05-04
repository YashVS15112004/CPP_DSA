// LastStoneWeight.cpp
#include<bits/stdc++.h>
using namespace std;
int lastStoneWeight(vector<int>& stones) 
{
    int l1,l2;
    priority_queue<int> maxh;
    for(auto it:stones) maxh.push(it);
    while(maxh.size()>1)
    {
        l1 = maxh.top();
        maxh.pop();
        l2 = maxh.top();
        maxh.pop();
        if(l1-l2!=0)maxh.push(l1-l2);
    }
    return (maxh.size()==1)?maxh.top():0;  
}
int main()
{
    vector<int> stones = {2,7,4,1,8,1};
    cout<<lastStoneWeight(stones);
}