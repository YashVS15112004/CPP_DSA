#include<bits/stdc++.h>
using namespace std;
string longestPalindrome(string s) {
int n = s.size();
    if (n <= 1) return s;
    int start = 0, maxLen = 1;
    auto expand = [&](int left, int right) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        } 
    };
    for (int i = 0; i < n; i++) {
        expand(i, i);     // Odd-length palindrome
        expand(i, i + 1); // Even-length palindrome
    }
    return s.substr(start, maxLen);   
}
int main()
{
    string s = "ac";
    cout<<longestPalindrome(s);
}