#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
{
        vector<vector<int>>ans;
        int i=0;
        while(i<intervals.size() && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        int intervalStart=newInterval[0];
        int intervalEnd=newInterval[1];
        while(i<intervals.size() && intervals[i][0]<=newInterval[1]){
            intervalStart=min(intervalStart,intervals[i][0]);
            intervalEnd=max(intervalEnd,intervals[i][1]);
            i++;
        }
        ans.push_back({intervalStart, intervalEnd});
        while(i<intervals.size()){
            ans.push_back(intervals[i]);
            i++;
        }      
        return ans;        
}
int main()
{
    vector<vector<int>> intervals = {{1,5}};
    vector<int> newInterval = {2,3};
    vector<vector<int>> ans = insert(intervals,newInterval);
    for(auto it1:ans)
    {
        for(auto it2:it1) cout<<it2<<" ";
        cout<<endl;
    }
}