#include<bits/stdc++.h>
using namespace std;
int check(vector<int> &boards,int mid,int kg)
{
    long long int sum=0;
    int kc = 1;
    int n = boards.size();
    for(int i=0;i<n;i++)
    {
        if(boards[i]+sum<=mid) sum+=boards[i];
        else{
            kc++;
            sum = boards[i];
        } 
    }
    if(kc<=kg) return 1;
    else return 0;
}
int painter_partition(vector<int> &boards, int k)
{
    int low = *max_element(boards.begin(),boards.end());
    int high = accumulate(boards.begin(),boards.end(),0);
    if(boards.size()==k) return low;
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        int op = check(boards,mid,k);
        if(op) high = mid-1;
        else low = mid+1;
    }
    return low;
}
int main()
{
    vector<int> boards = {2,1,5,6,2,3};
    cout<<painter_partition(boards,2);
}