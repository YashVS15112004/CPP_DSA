#include<bits/stdc++.h>
using namespace std;
int maxProfit_my_approach(vector<int> &prices)
{
    int cp = INT_MAX,sp = INT_MIN,margin = 0,max_margin=0;
    for(int i=0;i<prices.size();i++)
    {
        if(prices[i]<cp)
        {
            cp = prices[i];
        }
        sp = prices[i];
        margin = sp - cp;
        if(margin>max_margin)
        max_margin = margin;
    }
    return max_margin;
}
int main()
{
    vector<int> prices = {7,6,4,3,1};
    cout<<maxProfit_my_approach(prices);
}