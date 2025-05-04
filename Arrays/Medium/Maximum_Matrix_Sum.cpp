#include<bits/stdc++.h>
using namespace std;
long long maxMatrixSum(vector<vector<int>>& matrix) 
{
    long long summ =0;
    int  mini = INT_MAX;
    int neg=0;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            summ+=abs(matrix[i][j]);
            if(matrix[i][j]<=0) neg++;
            mini = min(mini,abs(matrix[i][j]));
        }
    }
    if(mini == INT_MAX) return summ;
    if(neg%2!=0) return summ-2*(mini);
    return summ;
}
int main()
{
    vector<vector<int>> matrix = {
        {-1, 1, 1},
        {1, -1, 1},
        {1, 1, -1}
    };
    cout<<maxMatrixSum(matrix);
}