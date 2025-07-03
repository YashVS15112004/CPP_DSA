#include<bits/stdc++.h>
using namespace std;
char kthCharacter(int k) 
{
    string str = "a";
    int i = 0,j = 1;
    while(j<k)
    {
        while(i<j)
        {
            char ch = str[i];
            if(ch=='z') ch = 'a';
            else ch++;
            str += ch;
            i++;
        }
        j = str.size();
        i = 0;
    } 
    return str[k-1];
}
int main()
{
    cout<<kthCharacter(10);
}