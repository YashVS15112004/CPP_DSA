#include<bits/stdc++.h>
using namespace std;
vector<int> Intersection(vector<int> arr1,vector<int> arr2)
{
    int i=0,j=0;
    vector<int> ans;

    while(i<arr1.size() && j<arr2.size())
    {
        if(arr1[i]<arr2[j])
        {
            i++;
        }
        else if(arr2[j]<arr1[i])
        {
            j++;
        }
        else if(arr1[i]==arr2[j])
        {
            if(ans.size()==0 || arr1[i]!=ans.back())
            {
                ans.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }  
    return ans;  
}
int main()
{
    vector<int> arr1 = {1,2,2,3,3,4,5,6};
    vector<int> arr2 = {2,3,3,5,6,6,7};
    vector<int> ans =  Intersection(arr1,arr2);
    for(auto it:ans) cout<<it<<" ";
}