#include<bits/stdc++.h>
using namespace std;
string makeFancyString(string s) {
        int count = 1;
        string ans = "";
        int n = s.size();
        if(n<=2) return s;
        int i=0,j=0;
        while(i<n)
        {
            if(j==0) 
            {
                ans += s[i];
                j++;
            }
            else if(s[i]!=ans[j-1])
            {
                ans += s[i];
                j++;
                count=1;
            }
            else if(s[i]==ans[j-1])
            {
                if(count<2)
                {
                    count++;
                    ans += s[i];
                    j++;
                }
            }
            i++;
        }
        return ans;
}
int main()
{
    cout<<makeFancyString("aab");
}