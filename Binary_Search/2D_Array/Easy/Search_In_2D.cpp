#include<bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size()-1;
    int lowr = 0;
    int highr = n-1;
    while(lowr<=highr)
    {
        int midr = lowr+(highr-lowr)/2;
        if(matrix[midr][0]<target && matrix[midr][m]>target)
        {
            int lowc = 0;
            int highc = m;
            while(lowc<=highc)
            {
                int midc = lowc+(highc-lowc)/2;
                if(matrix[midr][midc]<target) lowc = midc+1;
                else if(matrix[midr][midc]>target) highc = midc-1;
                else return true;
            }
            return false;
        }
        else if(matrix[midr][0]<target && matrix[midr][m]<target) lowr = midr+1;
        else highr = midr-1;
    }  
    return false;     
}
bool searchMatrix_Striver(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    //apply binary search:
    int low = 0, high = n * m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m;
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}
int main()
{
    vector<vector<int>> matrix = {{1,2,13,13,22,28},{31,33,34,34,36,38},{40,48,49,51,52,53},{55,56,59,60,60,60},
    {61,62,62,64,67,70}};
    cout<<searchMatrix(matrix,70);
}