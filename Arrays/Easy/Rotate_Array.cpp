#include<bits/stdc++.h>
using namespace std;
void Right_Rotate(vector<int> &nums,int k)
{
    // LC - Rotate Array Ques.
    if(nums.size()<=1)
    return;
    else{
        k = k%nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        return;
    }
}
void Left_Rotate(vector<int> &nums,int k)
{
    if(nums.size()<=1)
    return;
    else{
        k = k%nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+(nums.size()-k));
        reverse(nums.begin()+(nums.size()-k),nums.end());
        return;
    }
}
void Rotate(vector<int>&nums,int k,string dir)
{
    if(dir=="right") return Right_Rotate(nums,k);
    else if(dir=="left") return Left_Rotate(nums,k);
    else return;
}
int main()
{
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3; 
    string dir = "left";
    Rotate(nums,k,dir);
    for(auto it:nums) cout<<it<<" ";
}