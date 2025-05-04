#include<bits/stdc++.h>
using namespace std;
string largestOddNumber(string num) 
{
    int i = num.size()-1;
    while(i>=0)
    {
        int ele = static_cast<int>(num[i]);
        if(ele%2==0) 
        {
            num.pop_back();
            i--;
        }
        else break;
    }
    return num;
}
int main()
{
    string num = "35427";
    cout<<largestOddNumber(num);
}