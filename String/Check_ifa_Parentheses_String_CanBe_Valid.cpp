#include<bits/stdc++.h>
using namespace std;
bool canBeValid(string s, string locked) 
{
    int n = s.size(),m = locked.size(),rc = 0;
    if(n%2!=0) return false;
    //Left to Right => for every ')' we should have a locked '(' or a unlocked bracket in the left;
    for(int i=0;i<n;i++)
    {
        if(s[i]==')' && locked[i]=='1') 
        {
            rc--;
            if(rc<0) return false;
        }
        else if(s[i]=='(' && locked[i]=='1') rc++;
        else if(locked[i]=='0') rc++;
    }
    if(rc<0) return false;
    //Right to Left => for every '(' we should have a locked ')' or a unlocked bracket in the right;
    rc = 0;
    for(int j=n-1;j>=0;j--)
    {
        if(s[j]=='(' && locked[j]=='1') 
        {
            rc--;
            if(rc<0) return false;
        }
        else if(s[j]==')' && locked[j]=='1') rc++;
        else if(locked[j]=='0') rc++;
    }
    return rc>=0;
}
int main()
{
    string s = "())(()(()(())()())(())((())(()())((())))))(((((((())(()))))(",
    locked = "100011110110011011010111100111011101111110000101001101001111";
    cout<<canBeValid(s,locked);
}