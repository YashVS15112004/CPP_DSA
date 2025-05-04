#include<bits/stdc++.h>
using namespace std;
vector<vector<char>> rotateTheBox(vector<vector<char>>& box) 
{
    int n=box.size(),m=box[0].size(),ansi=0,ansj=0,boxi=n-1,boxj=m-1,i=m-1,j=m-1;
    if(n<=1 && m<=1) return box;
    vector<vector<char>> ans (m,vector<char> (n,' '));
    while(boxi>=0)
    {
        if(boxi>=0 && i>=0 && box[boxi][i]=='.')
        {
            swap(box[boxi][i],box[boxi][j]);
            if(box[boxi][i]=='#')i--;
            j--;
        }
        if(boxi>=0 && j>=0 && box[boxi][j]=='#')
        {
            swap(box[boxi][i],box[boxi][j]);
            i--;
            j--;
        }
        if(boxi>=0 && j>=0 && box[boxi][j]=='*')
        {
            j--;
            i=j;
        }
        if(j<0 || i<0)
        {
            boxi--;
            i=m-1;
            j=m-1;
        }
    }
    for(int i1=n-1;i1>=0;i1--)
    {
        for(int j1=0;j1<m;j1++)
        {
            ans[ansi][ansj] = box[i1][j1];
            ansi++;
        }
        ansi=0;
        ansj++;
    }
    return ans; 
}
int main()
{
    vector<vector<char>> box = {
        {'#', '.', '#'}
    };
    vector<vector<char>> ans = rotateTheBox(box);
    for(auto it:ans)
    {
        for(auto it1:it) cout<<it1<<" ";
        cout<<endl;
    }
}