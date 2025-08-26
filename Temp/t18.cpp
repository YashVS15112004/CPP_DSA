#include<bits/stdc++.h>
using namespace std;
int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
    float ld = 0.0f;
    int n = dimensions.size(),prod = 0,length = 0,width = 0;
    for(int i=0;i<n;i++)
    {
        length = dimensions[i][0];
        width = dimensions[i][1];
        float d = sqrt((pow(length,2)+pow(width,2)));
        if(d>ld)
        {
            ld = d;
            prod = length*width;
        }
        else if(d==ld) prod = max(prod,(length*width));
    }    
    return prod;
}
int main()
{
    vector<vector<int>> dimensions = {{9,3},{8,6}};
    cout<<areaOfMaxDiagonal(dimensions);
}