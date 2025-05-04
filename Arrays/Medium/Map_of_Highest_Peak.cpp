#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> highestPeak(vector<vector<int>> isWater)
{
int r=isWater.size();
        int c=isWater[0].size();
        vector<vector<int>>height(r,vector<int>(c,r+c));
        //first pass
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(isWater[i][j]==1){
                   height[i][j]=0;
                }
                else{
                    if(i>0){
                        height[i][j]=min(height[i][j],height[i-1][j]+1);

                    }
                    if(j>0){
                        height[i][j]=min(height[i][j],height[i][j-1]+1);
                    }
                }
            }
        }
        //second pass for adjacent cases from right bottom
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                if(i<r-1){
                      height[i][j]=min(height[i][j],height[i+1][j]+1);
                }
                if(j<c-1){
                      height[i][j]=min(height[i][j],height[i][j+1]+1);
                }
            }
        }
        return height;
}
int main()
{
    vector<vector<int>> isWater = {{0,1},{0,0}};
    vector<vector<int>> ans = highestPeak(isWater);
    for(auto it:ans) 
    {
        for(auto itr:it) cout<<itr<<" ";
        cout<<endl;
    }
}