#include<bits/stdc++.h>
using namespace std;
vector<int> searchRange_myappr(vector<int>& nums, int target) 
{
    int low = 0;
    int high = nums.size()-1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(nums[mid]==target)
        {
            if(nums[low]!=target) low++;
            if(nums[high]!=target) high--;
            else if(nums[low]==target && nums[high]==target){
                return {low,high};
            }
        }
        else if(nums[mid]<target) low = mid+1;
        else high = mid-1;
    }
    return {-1,-1};      
}
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result = {-1, -1};
    int left = binarySearch(nums, target, true); //True means will go in left direction.
    int right = binarySearch(nums, target, false); //False means will go in right direction.
    result[0] = left;
    result[1] = right;
    return result;        
}

int binarySearch(vector<int>& nums, int target, bool isSearchingLeft) {
    int left = 0;
    int right = nums.size() - 1;
    int idx = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
            
        if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            idx = mid;
            if (isSearchingLeft) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }
    return idx;
}    
int main()
{
    vector<int> nums = {1,1,2,3,5,5,7,7,7,7,10,12,14,14,16,17,19,19,20,21,22,22,22,23,23,24,25,26,26,26,27,28,30, 30,30,30,30,31,33,33,33,35,35,35,36,39,39,40,41,41,43,44,45,45,45,46,47,47,47,48,49,49,50,50};
    vector<int> ans = searchRange(nums,26);
    for(auto it:ans) cout<<it<<" ";
}