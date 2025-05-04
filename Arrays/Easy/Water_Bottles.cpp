#include<bits/stdc++.h>
using namespace std;
int numWaterBottles(int numBottles, int numExchange) {
        int eb=0,ans=0;
        while(numBottles>0)
        {
            ans += numBottles;
            int temp = numBottles;
            numBottles = (numBottles+eb)/numExchange;
            eb = (temp+eb)%numExchange;
        }
        return ans;
}
int main()
{
    cout<<numWaterBottles(15,8);
}