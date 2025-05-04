#include<bits/stdc++.h>
using namespace std;
class MyStack {
    int arr[100];
    int front;
    int rear;
    public:
    MyStack() {
        front = 0;
        rear = 0;
    }
    void push(int x) {
        if(rear==100) return;
        else arr[rear++] = x;
    }
    int pop() {
        if(rear<=front) return -1;
        else return arr[--rear];   
    }
    int top() {
        if(rear<=front) return -1;
        return arr[rear-1];
    }
    bool empty() {
        if(rear==0) return true;
        else return false;
    }
};
int main()
{
    MyStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    cout<<stack.pop()<<endl;
    cout<<stack.pop()<<endl;
    cout<<stack.pop()<<endl;
    cout<<stack.pop()<<endl;
    cout<<stack.pop()<<endl;
}