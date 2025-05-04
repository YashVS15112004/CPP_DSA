#include<bits/stdc++.h>
using namespace std;
bool checkIfExist(vector<int>& arr) {
    map<int,int> mp;
    int n = arr.size();
    for(int i=0;i<n;i++)
    mp[arr[i]] = i+1;
    int idx = (mp[0]>0)?mp[0]:mp.erase(0);
    for(int i=0;i<n;i++) if(arr[i]==0 && i+1!=idx) return true;
    for(int i=0;i<n;i++)
    {
        if(mp[arr[i]*2]>0 && mp[arr[i]*2]!=i+1) return true;
        else mp.erase(mp[arr[i]*2]);
    }
    return false;
}
int main()
{
    vector<int> arr = {2,3,3,0,0};
    cout<<checkIfExist(arr);
}