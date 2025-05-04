#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    int n = intervals.size();
    vector<vector<int>> ans;
    sort(intervals.begin(),intervals.end());
    int start = intervals[0][0],end = intervals[0][1];
    if(n<=1) return intervals;
    for(int i=1;i<n;i++)
    {
        if(intervals[i][0]<=end) end = max(intervals[i][1],end);
        else
        {
            ans.push_back({start,end});
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }
    ans.push_back({start,end});
    return ans;
}
int main()
{
    vector<vector<int>> intervals = {
        {1, 3}, 
        {2, 6}, 
        {8, 10}, 
        {8, 9}, 
        {9, 11}, 
        {15, 18}, 
        {2, 4}, 
        {16, 17}
    };
    vector<vector<int>> ans = merge(intervals);
    for(auto it:ans) cout<<it[0]<<" "<<it[1]<<endl;
}