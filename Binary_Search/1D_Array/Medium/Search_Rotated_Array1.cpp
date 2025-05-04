#include<bits/stdc++.h>
using namespace std;
int search_myappr(vector<int>& nums, int target) 
{
    int low = 0;
    int high = nums.size()-1;
    int k = high;
    int mid = low + (high-low)/2;
    int i = mid;
    int j = mid;
    while(i>low || j<high)
    {
        if(i!= low && nums[i]<nums[i-1])
        {
            k = i-1;
            break;
        } 
        else if(j!= high && nums[j]>nums[j+1]) 
        {
            k = j;
            break;
        }
        else
        {
            i--;
            j++;
        }
    }
    low = 0;
    high = k;
    while(low<=high)
    {
        mid = low + (high-low)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) low = mid+1;
        else high = mid-1;
    }
    low = k+1;
    high = nums.size()-1;
    while(low<=high)
    {
        mid = low + (high-low)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) low = mid+1;
        else high = mid-1;
    }
    return -1;
}
int search(vector<int>& arr, int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        //if mid points the target
        if (arr[mid] == k) return mid;
        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
        else { //if right part is sorted:
            if (arr[mid] <= k && k <= arr[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    vector<int> nums = {4,5,6,7,0,1,2};
    cout<<search(nums,nums.size(),0);
}