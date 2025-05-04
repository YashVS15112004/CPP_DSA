#include<bits/stdc++.h>
using namespace std;
int celebrity(vector<vector<int> >& M, int n) {
        int top=0;
        int bottom= n-1;
        while(top<bottom){
            if(M[top][bottom]==1)
            top++;
            else if(M[bottom][top]==1)
            bottom--;
            else{
                top++;
                bottom--;
            }
        }
        if(top>bottom) return -1;
        for(int i=0;i<n;i++){
            if(i==top) continue;
            if(M[top][i]==0&&M[i][top]==1)
            continue;
            else
            return -1;
        }
        return top;
}
int main()
{
    vector<vector<int>> M = {{0,1,0},{0,0,0},{1,1,0}};
    cout<<celebrity(M,M.size());
}