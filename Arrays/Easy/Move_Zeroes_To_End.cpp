#include<bits/stdc++.h>
using namespace std;
void Move(vector<int> &nums)
{
    // Brute-Force - 1. Place non-zero elem in vecttor temp and again place them in org. vector and insert 0 in the left out indexes.
    int j = 0;
    for(int i=1;i<nums.size();i++)
    {
        if(nums[j]==0 && nums[i]!=0) swap(nums[j++],nums[i]);
        else if(nums[i]==0 && nums[j]!=0){j++;}
        else if(nums[i]!=0 && nums[j]!=0){j++;}
    }
}
vector<int> moveZeros(int n, vector<int> a){
    // Striver
    int j = -1;
    //place the pointer j:
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            j = i;
            break;
        }
}
}
int main()
{
    vector<int> nums = {4,2,4,0,0,3,0,5,1,0};
    Move(nums);
    for(auto it:nums) cout<<it<<" ";
}