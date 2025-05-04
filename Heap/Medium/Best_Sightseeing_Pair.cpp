#include<bits/stdc++.h>
using namespace std;
int maxScoreSightseeingPair(vector<int>& values) 
{
    int n = values.size(),ans = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minh;
    for(int i=0;i<n;i++)
    {
        pair<int,int> p = {i,values[i]};
        minh.push(p);
    }
    vector<pair<int,int>> temp;
    for(int i=0;i<n;i++)
    {
        int idx1 = minh.top().first;
        int ele1 = minh.top().second;
        minh.pop();
        while(!minh.empty())
        {
            int idx2 = minh.top().first;
            int ele2 = minh.top().second;
            temp.push_back({idx2,ele2});
            minh.pop();
            int sum = (ele1+idx1+ele2)-idx2;
            ans = max(ans,sum);
        }
        for(auto it:temp) minh.push(it);
        temp.clear();
    }
    return ans;
}
int main()
{
    vector<int> values = {7,8,8,10};
    cout<<maxScoreSightseeingPair(values);
}