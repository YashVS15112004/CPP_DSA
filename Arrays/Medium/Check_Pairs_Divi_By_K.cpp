#include<bits/stdc++.h>
using namespace std;
bool canArrange(vector<int>& arr, int k) {
    int n = arr.size();
    int m = n/2;
    int cnt = 0;
    unordered_map<int,int> freq;
    for(auto it:arr) freq[(((it%k)+k)%k)]++;
    for(int i=0;i<k;i++)
    {
        if (freq[i] != freq[k - i]) return false;
    }
    return freq[0] % 2 == 0;
}
int main()
{
    vector<int> arr = {1,2,3,4,5,6};
    cout<<canArrange(arr,10);
}