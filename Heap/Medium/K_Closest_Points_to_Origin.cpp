#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
{
    priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> minh;
    for(int i=0;i<points.size();i++)
    {
        double dist = sqrt(pow((0.0-(double)points[i][0]),2) + pow((0.0-(double)points[i][1]),2));
        pair<double,pair<int,int>> p = {dist,{points[i][0],points[i][1]}};
        minh.push(p);
    }
    vector<vector<int>> ans;
    for(int i=0;i<=k-1;i++)
    {
        int x = minh.top().second.first;
        int y = minh.top().second.second;
        ans.push_back({x,y});
        minh.pop();
    }
    return ans;
}
int main()
{
    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
    int k = 2;
    vector<vector<int>> ans = kClosest(points,k);
    for(auto it:ans) cout<<it[0]<<" "<<it[1]<<endl;
}