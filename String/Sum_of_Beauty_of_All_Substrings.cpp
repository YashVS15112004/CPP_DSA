#include<bits/stdc++.h>
using namespace std;
int beautySum(string s) {
     unordered_map<char,int>mpp;
        int sum=0;
        for(int i=0;i<s.size()-1;i++){
            mpp.clear();
           for(int j=i;j<s.size();j++){
            mpp[s[j]]++;
            int maxi=INT_MIN;
            int mini=INT_MAX;
            for(auto it:mpp){
                maxi=max(maxi,it.second);
                mini=min(mini,it.second);
            }
            sum+=maxi-mini;
           }
        }
        return sum;   
}
int main()
{
    string s = "aabcb";
    cout<<beautySum(s);
}