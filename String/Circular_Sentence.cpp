#include<bits/stdc++.h>
using namespace std;
bool isCircularSentence(string sentence) 
{
    int i = 0;
    int n = sentence.size();
    char ch = sentence[i++];
    while(i<n)
    {
        if(sentence[i]==' ' && sentence[i-1]!=sentence[i+1]) return false;
        i++;
    }
    if(ch!=sentence[i-1]) return false;
    return true;
}
int main()
{
    string sentence = "Leetcode is cool";
    cout<<isCircularSentence(sentence);
}