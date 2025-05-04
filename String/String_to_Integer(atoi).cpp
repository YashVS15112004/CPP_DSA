#include<bits/stdc++.h>
using namespace std;
int myAtoi(string s) 
{
    int i=0;
        while( i<s.size() && s[i]==' ' ){
            i++;
        }
        int sign =1;
        if (i<s.size() &&(s[i]=='+'||s[i] =='-')) {
            sign=(s[i]=='-')?-1:1;
            i++;
        }
        long long res=0;
        if(/*(s[i]>=65 && s[i]<=90)|| (s[i]>=97 && s[i]<=122)*/!isdigit(s[i]))return res;
        while(i<s.size() && isdigit(s[i])){
            res =res*10+(s[i]-'0');//imp pattern to conv. string to int
            if(res*sign >INT_MAX)return INT_MAX;
            if(res*sign <INT_MIN)return INT_MIN;
            i++;
        }
       
        return sign*res;   
}
int main()
{
    string s = "words and 987";
    cout<<myAtoi(s);
}