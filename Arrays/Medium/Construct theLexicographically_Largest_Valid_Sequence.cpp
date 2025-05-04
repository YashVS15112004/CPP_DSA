#include<bits/stdc++.h>
using namespace std;
bool findlex(int currind,vector<int>&res,vector<bool>&isused,int target){
        if(currind==res.size())return true;
        if(res[currind]!=0){
            return findlex(currind+1,res,isused,target);
        }
        for(int i=target;i>=1;i--){
            if(isused[i])continue;
            isused[i]=true;
            res[currind]=i;
            if(i==1){
                if(findlex(currind+1,res,isused,target))return true;
            }
            else if(currind+i<res.size() && res[currind+i]==0){
                res[currind+i]=i;
                if(findlex(currind+1,res,isused,target))return true;
                res[currind+i]=0;
            }
            res[currind]=0;
            isused[i]=false;
        }
        return false;
}
vector<int> constructDistancedSequence(int n) {
        vector<int>res(n*2-1,0);
        vector<bool>isused(n+1,false);
        findlex(0,res,isused,n);
        return res;
}
int main()
{
    int n = 5;
    vector<int> ans = constructDistancedSequence(n);
    for(auto it:ans) cout<<it<<" ";
}