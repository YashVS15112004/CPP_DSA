#include<bits/stdc++.h>
using namespace std;
vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
{
    int n = A.size(),count = 0;   
    vector<int> freq (n,0),ans (n,0);
    for(int i=0;i<n;i++)
    {
        freq[A[i]-1]++;
        freq[B[i]-1]++;
        if(freq[A[i]-1]==2 && A[i]!=B[i]) count++;
        if(freq[B[i]-1]==2 && A[i]!=B[i]) count++;
        if(A[i]==B[i]) count++;
        ans[i] = count;
    }
    return ans;
}
int main()
{
    vector<int> A = {2,3,1},B = {3,1,2};
    vector<int> ans = findThePrefixCommonArray(A,B); //[0,2,3,4]
    for(auto it:ans) cout<<it<<" ";
}