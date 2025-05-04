#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> merge_better_opt_myappr(vector<vector<int>>& intervals)
{
    sort(intervals.begin(),intervals.end());
    int m = intervals.size();
    int n = intervals[0].size();
    if(m<=1) return intervals;
    unordered_map<int,pair<int,int>> mpp;
    pair<int,int> p = {intervals[0][0],intervals[0][1]};
    mpp[0] = p;
    int k = 0;
    vector<vector<int>> ans;
    for(int i=1;i<m;i++)
    {
        int a = intervals[i][0];
        int b = intervals[i][1];
        if(mpp[k].second >= a) 
        {
            int temp = max(mpp[k].second,b);
            mpp[k].second = temp;
        }
        else
        {
            k++;
            p = {a,b};
            mpp[k] = p;
        }
    }
    for(auto it:mpp)
    {
        vector<int> temp = {it.second.first,it.second.second};
        ans.push_back(temp);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
vector<vector<int>> mergeOverlappingIntervals_striver(vector<vector<int>> &arr) {
    int n = arr.size(); // size of the array
    //sort the given intervals:
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        // if the current interval does not
        // lie in the last interval:
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        // if the current interval
        // lies in the last interval:
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> intervals = {{1,4},{4,5}};
    vector<vector<int>> ans = mergeOverlappingIntervals_striver(intervals);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}