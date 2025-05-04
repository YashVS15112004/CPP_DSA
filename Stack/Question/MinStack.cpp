#include<bits/stdc++.h>
using namespace std;
class MinStack {
    int arr[30000];
    int topi;
    int minEle;
    map<int,int> mp;
public:
    MinStack() {topi=-1;minEle = INT_MAX;}
    void push(int val) {
        topi++;
        if(topi==30000) return;
        else 
        {
            arr[topi] = val;
            mp[val]++;
        }
    }
    void pop() {
        if(topi==-1) return;
        else
        {
            if(mp[arr[topi]]==1) mp.erase(arr[topi]);
            else mp[arr[topi]]--;
            arr[topi--] = 0;
            return;
        }
    }
    int top() {
        if(topi==-1) return -1;
        else return arr[topi];
    }
    int getMin(){
        if(topi==-1) return -1;
        for(auto it:mp) return it.first;
        return 0;
    }
};
int main()
{
    MinStack s;
    s.push(-1);
    s.push(0);
    s.push(-3);
    cout<<s.getMin()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.getMin()<<endl;
}