#include<bits/stdc++.h>
using namespace std;
int findKRotation(vector<int> &arr) {
        int low = 0;
        int high = arr.size()-1;
        int mini = 0;
        int minn = INT_MAX;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(arr[low]<arr[high])
            {
                if(minn>arr[low]) return low;
                else return mini;
            }
            else if(arr[low]<=arr[mid]){
                if(minn>arr[low])
                {
                    minn = arr[low];
                    mini = low;
                }
                low = mid + 1;
            }
            else
            {
                if(minn>arr[mid])
                {
                    minn = arr[mid];
                    mini = mid;
                }
                high = mid-1;
            }
        }
        return mini;
}
int main()
{
    vector<int> arr = {38,40,43,44,4,9,12,21,32,34};
    cout<<findKRotation(arr);
}