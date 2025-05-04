#include<bits/stdc++.h>
using namespace std;
int findMaxConsecutiveOnes(vector<int>& nums) {
        int ocount = 0;
        int maxc = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1) ocount++;
            else
            {
                if(ocount>=maxc) maxc = ocount;
                ocount=0;
            }    
        }
        if(ocount>=maxc) maxc = ocount;
        return maxc;
}
int main()
{
    vector<int> nums = {1,1,0,1,1,1};
    cout<<findMaxConsecutiveOnes(nums);
}