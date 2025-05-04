#include<bits/stdc++.h>
using namespace std;
long long dividePlayers(vector<int>& skill) 
{
    unordered_map<int,int> mpp;
    int sum = 0;
    int n = skill.size();
    for(auto it:skill)
    {
        mpp[it]++;
        sum+=it;
    }
    mpp[0] = 0;
    int tp = n/2;
    int target = sum/tp;
    if(n==2) return skill[0]*skill[1];
    long long ans = 0;
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        int n1 = skill[i];
        int n2 = target-skill[i];
        if(n1!=n2 && mpp[n2]>=1 && mpp[n1]>=1)
        {
            long long prod = n1*(n2);
            ans += prod;
            if(n1==n2) mpp[n2] -=2;
            else 
            {
                mpp[n1]--;
                mpp[n2]--;
            }
            cnt++;
        }
        else if(n1==n2 && mpp[n2]>1 && mpp[n1]>1)
        {
            long long prod = n1*(n2);
            ans += prod;
            if(n1==n2) mpp[n2] -=2;
            else 
            {
                mpp[n1]--;
                mpp[n2]--;
            }
            cnt++;
        }
    }
    if(cnt==tp) return ans==0?-1:ans;
    return -1;
}
int main()
{
    vector<int> skill = {4,2,4,3};
    cout<<dividePlayers(skill);
}