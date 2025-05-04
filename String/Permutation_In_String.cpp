#include<bits/stdc++.h>
using namespace std;
bool checkInclusion(string s1, string s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    if(n1>n2) return false;
    if(s1==s2) return true;
    unordered_map<char,int> mp1;
    unordered_map<char,int> mp2;
    for(auto it:s1) mp1[it]++;
    int k = n1;
    int i = 0;
    int j = 0;
    int x = i;
    while(i<n2)
    {
        if(j==k) 
        {
            bool flag = false;
            for(auto it:mp1)
            {
                if(it.second!=mp2[it.first])
                {
                    j=0;
                    mp2.clear();
                    flag = false;
                    break;
                } 
                else flag = true;
            }
            if(flag==true) return true;
            x++;
            i=x;
        }
        else
        {
            mp2[s2[i]]++;
            j++;
            i++; 
        }     
    }
    bool flag = false;
    for(auto it:mp1)
    {
        if(it.second!=mp2[it.first]){
            j=0;
            mp2.clear();
            flag = false;
            break;
        } 
        else flag = true;
    }
    return flag?true:false;
}
int main()
{
    string s1 = "adc", s2 = "dcda";
    cout<<checkInclusion(s1,s2);
}