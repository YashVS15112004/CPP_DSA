#include<bits/stdc++.h>
using namespace std;
bool canMakeSubsequence(string str1, string str2) 
{
    int n = str1.size(),m = str2.size(),i = 0,j = 0;
    if(m>n) return 0;
    while(i<n && j<m)
    {
        char next = (i<n && str1[i]=='z')?'a':str1[i]+1;
        if(i<n && j<m && (str1[i]==str2[j]||next==str2[j]))j++;
        i++;
    }
    return (j>=m)?true:false;   
}
int main()
{
    string str1 = "ab", str2 = "d";
    cout<<canMakeSubsequence(str1,str2);
}