#include<bits/stdc++.h>
using namespace std;
vector<int> floorCiel(vector<int> &nums,int target)
{
    int low = 0;
    int high = nums.size()-1;
    int floor = -1;
    int ciel = -1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(nums[mid]==target) return {nums[mid],nums[mid]};
        else if(nums[mid]<target)
        {
            floor = mid;
            low = mid+1;
        }
        else
        {
            ciel = mid;
            high = mid - 1;
        } 
    }
    if(floor==-1) return {-1,nums[ciel]};
    else if(ciel==-1) return{nums[floor],-1};
    else return {nums[floor],nums[ciel]};
}
int main()
{
    vector<int> nums = {3,4,4,7,8,10};
    vector<int> ans = floorCiel(nums,5);
    for(auto it:ans) cout<<it<<" ";
}