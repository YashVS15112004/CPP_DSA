#include<bits/stdc++.h>
using namespace std;
vector<char> digits(int n)
{
    int dig = 0;
    vector<char> digs;
    if(n==1) return {};
    while(n!=0)
    {
        dig++;
        int rem = n%10;
        string r = to_string(rem);
        char ch = r[0];
        digs.push_back(ch);
        n/=10;
    }
    reverse(digs.begin(),digs.end());
    return digs;
}
int compress(vector<char>& chars)
{
    int n = chars.size(),i = 0,j = 1,ans = 0,cnt = 1;
    if(n<=1) return n;
    while(j<chars.size())
    {
        if(chars[i]==chars[j]) cnt++;
        else if(chars[i]!=chars[j])
        {
            vector<char> digs = digits(cnt);
            if(cnt>1){
            for(int k=0;k<digs.size();k++)
            chars[++i] = digs[k];
            for(int k = i;k<j-1;k++)
            {
                auto it = chars.begin()+i+1;
                chars.erase(it);
            }
            }
            i++;
            j = i;
            cnt = 1;
        }
        j++;
    }
    if(cnt>1) 
    {
      vector<char> digs = digits(cnt);
      for(int k=0;k<digs.size();k++)
        chars[++i] = digs[k];
        for(int k = i;k<j-1;k++)
        {
            auto it = chars.begin()+i+1;
            chars.erase(it);
        } 
    }
    for(auto it:chars) cout<<it<<" ";
    cout<<endl;
    return chars.size();
}    
int main()
{
    vector<char> chars =  {'a', 'a', 'a', 'a', 'a', 'b'};
    cout<<compress(chars);
}