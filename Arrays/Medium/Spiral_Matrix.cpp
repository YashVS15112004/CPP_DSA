#include<bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    vector<int> ans;
    int i=0,j=0;
    int m=matrix.size();
    int n=matrix[0].size();
    if(m<1 && n<1) return ans; //If empty
    // For 1st row
    for(int k=0;k<n;k++)
    {
        ans.push_back(matrix[i][j]);
        matrix[i][j] = INT_MIN;
        j++;
    }
    if(m<=1) return ans; //If row in matix<=1 return ans
    i++;j--; //i j set to 1,n-1
    int flag = 1;
    while(flag!=0)
    {
        ans.push_back(matrix[i][j]);
        matrix[i][j] = INT_MIN;
        if(j<n-1 && matrix[i][j+1]!=INT_MIN && matrix[i-1][j]==INT_MIN) j++; //Move Right
        else if(j<=n-1 && i<m-1 && matrix[i+1][j]!=INT_MIN) i++; //Move Down
        else if(i<=m-1 && j>0 && matrix[i][j-1]!=INT_MIN) j--; //Move Left
        else if(i>0 && j<=n-1 && matrix[i-1][j]!=INT_MIN) i--; //Move Up
        else return ans; //Return ans if all visited 
    }
}
int main()
{
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<int> ans = spiralOrder(matrix);
    for(auto it: ans) cout<<it<<" ";
}