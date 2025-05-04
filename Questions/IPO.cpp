#include<bits/stdc++.h>
using namespace std;
int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
{
    int len = profits.size();
    int flg = 1;
    for(int i=0;i<capital.size();i++)
    {
        if(w>=capital[i])
        {
            flg = 0;
        }
    }
    if(flg==1)
    return w;
    while(k>0 && len>0)
    {
        int prft = 0;
        int key = 0;
        for(int i=0;i<capital.size();i++)
        {
            if(w>=capital[i] && capital[i]!=-1)
            {
                if(prft<=profits[i])
                {
                    prft = profits[i];
                    key = i;
                }
            }
        }
        w += prft;
        profits[key] = -1;
        capital[key] = -1;
        len--;
        k--;

    }
    return w;
}
int main()
{
    int k = 3, w = 0;
    vector<int> profits = {1,2,3};
    vector<int> capital= {0,1,2};
    cout<<findMaximizedCapital(k,w,profits,capital)<<endl;
    return 0;
}