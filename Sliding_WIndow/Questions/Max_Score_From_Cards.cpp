#include<bits/stdc++.h>
using namespace std;
int maxScore(vector<int>& cardPoints, int k) 
{
    int lsum =0, rsum =0, max =0,sum =0;
        int n = cardPoints.size();
        for(int i=0;i<k;i++){
            lsum = lsum + cardPoints[i];
        }
        max = lsum;
        for (int i = 0; i < k; i++) {
            lsum -= cardPoints[k-1-i];
            rsum += cardPoints[cardPoints.size()-1-i];
            sum = lsum+rsum;
            if(sum>max){
                max = sum;
            }
        }
        return max;  
}
int main()
{
    vector<int> cardPoints = {100,40,17,9,73,75};
    int k = 3;
    cout<<maxScore(cardPoints,k);
}