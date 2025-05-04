#include<bits/stdc++.h>
using namespace std;
string removeKdigits(string num, int k) {
        stack<char>st;
        int n =num.size();
        if(n==k)return "0";
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && (st.top()-'0')>(num[i]-'0')){
                st.pop();
                k--;
                
            }
            st.push(num[i]);
        }
        if(st.empty())return "0";
            while(k>0 && !st.empty()){
                st.pop();
                k--;
            }
            string res="";
            while(!st.empty()){
              res+=st.top();
              st.pop();
            }
            while(res.size()>0 && res.back()=='0')res.pop_back();
            reverse(res.begin(),res.end());
            if(res.empty())return "0";
            return res;
}
int main()
{
    string num = "1432219";
    int k = 3;
    cout<<removeKdigits(num,k);
}