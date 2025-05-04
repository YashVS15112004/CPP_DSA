#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
class MyStack{
    int arr[30000];
    int topi;
public:
    MyStack() {topi=-1;}
    void push(int val) {
        topi++;
        if(topi==30000) return;
        else arr[topi] = val;
    }
    int pop() {
        if(topi==-1) return -1;
        else return arr[topi--];
    }
    int top() {
        if(topi==-1) return -1;
        else return arr[topi];
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
    cout<<stack.pop()<<endl;
}