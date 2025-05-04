#include<bits/stdc++.h>
using namespace std;
int countConsistentStrings(string allowed, vector<string>& words) 
{
    vector<char> charr (26,0);
    int lena = allowed.length();
    for(int i=0;i<lena;i++)
    {
        int idx = allowed[i] - 97;
        charr[idx] = allowed[i];
    }
    int cnt = 0;
    int lenw = words.size();
    for(int i=0;i<lenw;i++)
    {
        int j = 0;
        int lw = words[i].length();
        for(j=0;j<lw;j++)
        {
            int idx = words[i][j] - 97;
            if(charr[idx]!=words[i][j]) break;    
        }
        if(j==lw) cnt++;
    }
    return cnt;
}
int main()
{
    string allowed = "cad";
    vector<string> words = {"cc","acd","b","ba","bac","bad","ac","d"};
    cout<<countConsistentStrings(allowed,words);
}