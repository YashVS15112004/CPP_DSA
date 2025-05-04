#include<bits/stdc++.h>
using namespace std;
class MyQueue {
    int arr[100];
    int top;
    int ptr;
public:
    MyQueue() {top=-1;ptr=0;}
    void push(int x) {
        if(top==100) return;
        else arr[++top] = x;
    }
    int pop() {
        if(top<ptr) return -1;
        else return arr[ptr++];   
    }
    int peek() {
        if(top<ptr) return -1;
        else return arr[top]; 
    }
    bool empty() {
        if(top<ptr) return true;
        else false;
    }
};
int main()
{
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
}