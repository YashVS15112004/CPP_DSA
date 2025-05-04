#include<bits/stdc++.h>
using namespace std;
class StockSpanner {
    stack<pair<int,int>> st;
    stack<int> temp;
    int gt;
public:
    StockSpanner() {gt=0;}
    int next(int price) {
        int count = 1;
        if(st.empty() || st.top().first>price) 
        {
            st.push({price,count});
            return count;
        }
        else
        {
            while(!st.empty() && st.top().first<=price)
            {
                count += st.top().second;
                st.pop();
            }
            st.push({price,count});
            return count;
        }
    }
};
int main()
{
    StockSpanner *stockSpanner = new StockSpanner();
    cout<<stockSpanner->next(100)<<endl; // return 1
    cout<<stockSpanner->next(80)<<endl;  // return 1
    cout<<stockSpanner->next(60)<<endl;  // return 1
    cout<<stockSpanner->next(70)<<endl;  // return 2
    cout<<stockSpanner->next(60)<<endl;  // return 1
    cout<<stockSpanner->next(75)<<endl;  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
    cout<<stockSpanner->next(85)<<endl;  // return 6
}