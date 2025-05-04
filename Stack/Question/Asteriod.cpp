#include<bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(vector<int>& asteroids) 
{
    vector<int> ans;
    stack<int> st1;
    stack<int> st2;
    int n = asteroids.size();
    for(int i=n-1;i>=0;i--) st1.push(asteroids[i]);
    while(!st1.empty())
    {
        if(st1.top()<0 && st2.empty()) 
        {
            ans.push_back(st1.top());
            st1.pop();
        }
        else if(st1.top()<0 && !st2.empty())
        {
            while(!st2.empty())
            {
                int t1 = st1.top();
                st1.push(st2.top());
                st2.pop();
                int t2 = st1.top();
                if(abs(t1)>abs(t2)) st1.pop();
                else if(abs(t1)<abs(t2))
                {
                    st1.pop();
                    st1.pop();
                    st1.push(t2);
                    break;
                }
                else
                {
                    st1.pop();
                    st1.pop();
                    break;
                }

            }
        }
        else if(st1.top()>0)
        {
            st2.push(st1.top());
            st1.pop();
        }    
    }
    vector<int> temp;
    while(!st1.empty())
    {
        temp.push_back(st1.top());
        st1.pop();
    }
    while(!st2.empty()) 
    {
        temp.push_back(st2.top());
        st2.pop();
    }
    reverse(temp.begin(),temp.end());
    for(auto it:temp) ans.push_back(it);
    return ans;
}
int main()
{
    vector<int> asteroids = {1,-7,-3,-12,1,-8};
    vector<int> ans = asteroidCollision(asteroids);
    for(auto it:ans) cout<<it<<" ";
}