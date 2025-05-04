#include<bits/stdc++.h>
using namespace std;
string compressedString(string word) 
{
    string comp = "";
    int n = word.size();
    int i = 0;
    int ccnt = 0;
    char ch = word[0];
    while(i<n)
    {
        if(ccnt>=9 || ch!=word[i])
        {
            comp += to_string(ccnt) + ch;
            ccnt = 1;
            ch = word[i];
        }
        else if(ch==word[i]) ccnt++;
        i++;
    }
    comp += to_string(ccnt) + ch;
    return comp;        
}
int main()
{
    string word = "aaaaaaaaaaaaaaaaaaa";
    cout<<compressedString(word);
}