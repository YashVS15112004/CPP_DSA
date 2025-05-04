#include<bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>>& matrix)
{
        int m = matrix.size();
        int n = matrix[0].size();
        int k = m-1;
        int l = n-1;
        for(int i=0;i<m;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
        for(int i=0;i<m;i++)
        {
            k = m-1;
            for(int j=0;j<n-i;j++)
            {
                if(i==m-1 && j==0) return;

                swap(matrix[i][j],matrix[k][l]);
                k--;
            }
            l--;
        }
        return;
}
int main()
{
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    rotate(matrix);
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}