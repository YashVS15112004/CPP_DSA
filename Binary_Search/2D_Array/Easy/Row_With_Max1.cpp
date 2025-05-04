#include<bits/stdc++.h>
using namespace std;
int rowWithMax1s(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    int idx = 0;
    int ans = -1;
    int cnt = INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i][0]==0 && arr[i][m-1]==0) continue;
        else if(arr[i][0]==1 && arr[i][m-1]==1) return i;
        else
        {
            int low = 0;
            int high = m-1;
            while(low<=high)
            {
                int mid = low+(high-low)/2;
                if(arr[i][mid]==0) low = mid+1;
                else 
                {
                    idx = mid;
                    high = mid-1;
                }
            }
            int cdiff = m - idx;
            if(cnt<cdiff)
            {
                cnt = cdiff;
                ans = i;
            } 
        }
        
    }
    return ans;        
}
int main()
{
    vector<vector<int>> arr = {{0, 0, 1, 1},{0, 0, 0, 1}};
    cout<<rowWithMax1s(arr);
}