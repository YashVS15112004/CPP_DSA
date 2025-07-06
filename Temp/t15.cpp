#include<bits/stdc++.h>
using namespace std;
class FindSumPairs {
    unordered_map<int,int> mp1,mp2;
    vector<int> n2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) 
    {
        for(auto it:nums1) mp1[it]++;
        for(auto it:nums2)
        {
            mp2[it]++;
            n2.push_back(it);
        } 
    }
    void add(int index, int val) 
    {
        int oldele = n2[index];
        int newele = oldele + val;
        n2[index] = newele;
        mp2[newele]++;
        mp2[oldele]--;
        if(mp2[oldele]==0) mp2.erase(oldele);
    }
    int count(int tot) 
    {
        int count = 0;
       for(auto it:mp1)
       {
            if(mp2[tot-it.first]>0) count += (it.second*mp2[tot-it.first]);
            else  mp2.erase(tot-it.first);
       }
       return count;
    }
};
int main()
{
    vector<int> nums1 = {1,1,2,2,2,3};
    vector<int> nums2 = {1,4,5,2,5,4};
    FindSumPairs* obj = new FindSumPairs(nums1, nums2);
    cout<<obj->count(7)<<endl;
    obj->add(3,2);
    cout<<obj->count(8)<<endl;
    cout<<obj->count(4)<<endl;
    obj->add(1,1);
    cout<<obj->count(7)<<endl;
}