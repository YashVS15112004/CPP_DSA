#include<iostream>
using namespace std;
bool palindrome(string &s,int i)
{
    if(i>=s.length()/2) return true;
    
    // If the start is not equal to the end, not the palindrome.
    if(s[i]!=s[s.length()-i-1]) return false;
    
    // If both characters are the same, increment i and check start+1 and end-1.
    return palindrome(s,i+1);
}
int main()
{
    string a = "abcdba";
    cout<<palindrome(a,0);
    return 0;
}