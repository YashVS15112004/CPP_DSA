#include<bits/stdc++.h>
using namespace std;
bool checkPalindrome(string str)
{
    int i  = 0;
    int j = str.size()-1;
    while(i<j) if(str[i++]!=str[j--]) return false;
    return true;
}
string shortestPalindrome(string s) 
{
    string ans = "";
    string temp = "";
    string ans1 = "";
    int n = s.size();
    if(checkPalindrome(s)) return s;
    else
    {
        string sr = s;
        reverse(sr.begin(),sr.end());
        int i = 0;
        int j = 0;
        while(i<n || j<n)
        {
            if(i<n && j<n && (s[i]==sr[j]))
            {
                ans1 += sr[j];
                i++;
                j++;
            } 
            else if(i<n && j<n && (s[i]!=sr[j])) ans1 += sr[j++];
            else if(j<n)ans1 += sr[j++];
            else if(i<n)ans1 += s[i++];
        }
        n = ans1.size();
        i = 0;
        j = n-1;
        while(i<j)
        {
            if(ans1[i]==ans1[j])
            {
                i++;
                j--;
            }
            else if(i<j && (ans1[i]!=ans1[j]))
            {
                temp += ans1[i];
                i++;
                j--;
            }
        }
        i = n-j;
        j = 0;
        while(j<i) ans += ans1[j++];
        ans += temp;
        while(i<n) ans += ans1[i++];
        return ans;
    } 
}
int main()
{
    string st = shortestPalindrome("aacecaaa");
    cout<<st<<endl;
    string rev = st;
    reverse(rev.begin(),rev.end());
    if(st==rev) cout<<"T";
    else cout<<"F";
}