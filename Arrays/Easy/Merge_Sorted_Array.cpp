#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& nums1,int m,vector<int>& nums2,int n) {
        if(n==0) return;
        int j=0;
        int k=0;
        vector<int> temp;
        while(temp.size()<m+n)
        {
            if(j<m && k<n && nums1[j]<nums2[k]) temp.push_back(nums1[j++]);
            else if(j<m && k<n && nums1[j]==nums2[k])
            {
                temp.push_back(nums1[j++]);
                temp.push_back(nums2[k++]);
            }
            else if(j<m && k<n && nums1[j]>nums2[k]) temp.push_back(nums2[k++]);
            else if(k>=n) temp.push_back(nums1[j++]);
            else temp.push_back(nums2[k++]);
        }
        nums1.clear();
        for(auto it:temp) nums1.push_back(it);
        return;
}
int main()
{
    vector<int> nums1 = {2,0};
    int m = 1;
    vector<int> nums2 = {1};
    int n = 1;
    merge(nums1,m,nums2,n);
    for(auto it:nums1) cout<<it<<" ";
}
