#include<bits/stdc++.h>
using namespace std;
int digits(int n)
{
    int len = 0;
    while(n>0)
    {
        len++;
        n/=10;
    }
    return len;
}
int calc_space(int dig)
{
    int sp = 0;
    while(dig>0)
    {
        sp += pow(10,dig);
        dig--;
    }
    return sp;
}
int cspace(int i,int n,int dig)
{
    int len = 0;
    int space = 0;
    while(len<dig)
    {
        space += pow(10,len);
        len++;
    }
    space += n-pow(10,dig)+1;
    return space; 
}
vector<int> lexicalOrder(int n) 
{
    vector<int> ans (n,0);
    int dig = digits(n)-1;
    int spaces = 0;
    int idx = 0;
    int k = 0;
    int limit = 0;
    for(int i=1;i<=n;i++)
    {
        if(i<floor(n/pow(10,dig)))
        {
            if(ans[k]==0) ans[k] = i;
            spaces = calc_space(dig)+1;
            k+= spaces;
        }
        else if(i==floor(n/pow(10,dig)))
        {
            if(ans[k]==0) ans[k] = i;
            spaces = cspace(i,n,dig);
            k+= spaces;
            idx = k;
            limit = i;
        }
        else if(i>limit && i<=9)
        {
            if(ans[idx]==0) ans[idx] = i;
            idx++;
        }
        else if(floor(i/pow(10,dig))<=floor(n/pow(10,dig)) && floor(i/pow(10,dig))<=limit)
        {
            int rem = i%10;
            int div = i/pow(10,dig);
            k = pow(10,dig)*(abs(div-dig))+div+rem;
            if(ans[k]==0) ans[k] = i;
        }
    }
    return ans;
}
int main()
{
    vector<int> ans = lexicalOrder(99);
    for(auto it:ans) cout<<it<<" ";
}