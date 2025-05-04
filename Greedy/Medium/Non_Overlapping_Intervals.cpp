#include<bits/stdc++.h>
using namespace std;
static bool comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];//sorts array in asc order based on second index
    }
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),comp);
        int last=arr[0][1];
        int cnt=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i][0]>=last){
                last=arr[i][1];
            }else{
                cnt++;
            }
        }
        return cnt; 
}
int main()
{
    vector<vector<int>> intervals = {
        {-52, 31}, 
        {-73, -26}, 
        {82, 97}, 
        {-65, -11}, 
        {-62, -49}, 
        {95, 99}, 
        {58, 95}, 
        {-31, 49}, 
        {66, 98}, 
        {-63, 2}, 
        {30, 47}, 
        {-40, -26}
    };
    cout<<eraseOverlapIntervals(intervals);
}