#include<bits/stdc++.h>
using namespace std;
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ns = flowerbed.size();
      if(ns==1 && ((n==0 && (flowerbed[0]==0 || flowerbed[0]==1)) ||
      (n==1 && flowerbed[0]==0)) || n==0) return true;
      if(ns==1 && n==1 && flowerbed[0]==1) return false;
        for(int i=0;i<ns;i++)
        {
            if(i==0 && flowerbed[0]==0 && flowerbed[1]==0) 
            {
                flowerbed[0] = 1;
                n--;
            }
            else if(i==ns-1 && flowerbed[ns-1]==0 && flowerbed[ns-2]==0)
            {
                flowerbed[ns-1] = 1;
                n--;
            }
            else if(i!= 0 && i!=ns-1 && flowerbed[i]==0 && flowerbed[i-1]==0 && 
            flowerbed[i+1]==0)
            {
                flowerbed[i] = 1;
                n--;
            }
            if(n==0)break;
        }
        return (n==0)?true:false;  
}
int main()
{
    vector<int> flowerbed = {1,0,0,0,0,0,1};
    int n = 2;
    cout<<canPlaceFlowers(flowerbed,n);
}