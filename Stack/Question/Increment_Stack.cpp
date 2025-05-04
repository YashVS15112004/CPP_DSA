#include<bits/stdc++.h>
using namespace std;
class CustomStack {
    int arr[1000];
    int top;
    int size;
public:
    CustomStack(int maxSize) {
        top = -1;
        size = maxSize;
    }
    void push(int x) {
        if(top==size-1) return;
        else arr[++top] = x;
    }
    
    int pop() {
        if(top==-1) return -1;
        else return arr[top--];
    }
    
    void increment(int k, int val) {
        int n = min(k,size);
        for(int i=0;i<n;i++) arr[i]+=val;
    }
};
int main()
{
    CustomStack stk(3);
    stk.push(1);                          // stack becomes [1]
    stk.push(2);                          // stack becomes [1, 2]
    cout<<stk.pop()<<endl;
    stk.push(2);                          // stack becomes [1, 2]
    stk.push(3);                          // stack becomes [1, 2, 3]
    stk.push(4); 
    stk.increment(5, 100);                // stack becomes [101, 102, 103]
    stk.increment(2, 100);                // stack becomes [201, 202, 103]
    cout<<stk.pop()<<endl;                // return 103 --> Return top of the stack 103, stack becomes [201, 202]
    cout<<stk.pop()<<endl;                // return 202 --> Return top of the stack 202, stack becomes [201]
    cout<<stk.pop()<<endl;                // return 201 --> Return top of the stack 201, stack becomes []
    cout<<stk.pop()<<endl;  
}